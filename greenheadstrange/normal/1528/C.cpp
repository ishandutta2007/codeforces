// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 300005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T> bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}

using namespace std;

ll ksm(ll a, ll b) {
  if (!b)
    return 1;
  ll ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1)
    ns = ns * a % mod;
  return ns;
}

int n, ans, idx;
vi sona[maxn], sonb[maxn];
int l[maxn], r[maxn], id[maxn];
set<int> v;

void dfsb(int x) {
  l[x] = ++idx;
  id[idx] = x;
  for (auto y : sonb[x])
    dfsb(y);
  r[x] = idx;
}

bool ispar(int x, int y) { return l[x] <= l[y] && r[y] <= r[x]; }

void dfsa(int x) {
  bool adda = true;
  auto it = v.lower_bound(l[x]);
  if (it != v.end() && ispar(x, id[*it]))
    adda = false;
  if (adda)
    v.insert(l[x]);
  int dela = -1;
  auto it2 = v.lower_bound(l[x]);
  if (it2 != v.begin()) {
    --it2;
    if (ispar(id[*it2], x))
      dela = *it2;
  }
  if (dela != -1)
    v.erase(dela);
  ans = max(ans, (int)v.size());
  for (auto y : sona[x])
    dfsa(y);
  if (adda)
    v.erase(l[x]);
  if (dela != -1)
    v.insert(dela);
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    sona[i].clear();
    sonb[i].clear();
  }
  for (int i = 2; i <= n; i++) {
    int x;
    scanf("%d", &x);
    sona[x].push_back(i);
  }
  for (int i = 2; i <= n; i++) {
    int x;
    scanf("%d", &x);
    sonb[x].push_back(i);
  }
  ans = 0;
  idx = 0;
  dfsb(1);
  v.clear();
  dfsa(1);
  printf("%d\n", ans);
}

int main() {
  int T;
  for (scanf("%d", &T); T; T--) {
    solve();
  }
}