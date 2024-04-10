// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T>
bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}

using namespace std;

ll ksm(ll a, ll b) {
  if (!b) return 1;
  ll ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1) ns = ns * a % mod;
  return ns;
}

int n;
vector<pair<int,int>> p[maxn];
vector<array<int,3>> e[maxn];
int up[maxn], down[maxn], mxdown[maxn];
ll s, inv[maxn];


void mul(int x) {
  //printf("mul %d\n",x);
  for (auto pr : p[x]) {
    int p = pr.fi;
    up[p] += pr.se;
    int d = min(up[p], down[p]);
    up[p] -= d; down[p] -= d;
  }
}

void div(int x) {
  //printf("div %d\n", x);
  for (auto pr : p[x]) {
    int p = pr.fi;
    down[p] += pr.se;
    int d = min(up[p], down[p]);
    up[p] -= d; down[p] -= d;
    chkmax(mxdown[p], down[p]);
  }  
}

void dfs(int u,int par, ll modv) {
  s = (s + modv) % mod;
  for (auto pv: e[u]) {
    int v = pv[0];
    if (v == par) continue;
    mul(pv[2]); div(pv[1]);
    dfs(v, u, modv * inv[pv[1]] % mod * pv[2] % mod);
    mul(pv[1]); div(pv[2]);
  }
}

void solve() {
  scanf("%d", &n);
  s = 0;
  for (int i = 1; i <= n; i++) {
    e[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int u, v, x, y;
    scanf("%d%d%d%d", &u, &v, &x, &y);
    e[u].push_back({v, x, y});
    e[v].push_back({u, y, x});
  }
  for (int i = 1; i <= n; i++) {
    up[i] = 0, down[i] = 0, mxdown[i] = 0;
  }
  dfs(1, 0, 1);
  ll v = 1;
  for (int i = 1; i <= n; i++) 
    for (int j = 0; j < mxdown[i]; j++)
      v = v * i % mod;
  //printf("vv %lld\n", v);
  printf("%lld\n", v * s % mod);
}

int main() {
  inv[1] = 1;
  for (int i = 2; i <= 200000; i++) {
    int m = i;
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    for (int j = 2; j * j <= m; j++) if (m % j == 0) {
      int e = 0;
      while (m % j == 0) m /= j, e++;
      p[i].push_back({j, e});
    }
    if (m != 1) p[i].push_back({m, 1});
  }
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}