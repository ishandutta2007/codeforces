// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
#define mod 31607
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

int M = 1000001;
vi pr[maxn];
int par[maxn];
int n, q, a[maxn], id[maxn];
set<int> con[maxn];
int getPar(int x) {
  if (par[x] == x)
    return x;
  else
    return par[x] = getPar(par[x]);
}

int main() {
  scanf("%d%d", &n, &q);

  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int cnt = n;
  for (int i = 2; i <= M; i++)
    if (pr[i].empty()) {
      id[i] = cnt++;
      for (int j = i; j <= M; j += i)
        pr[j].pb(i);
    }
  for (int i = 0; i < cnt; i++)
    par[i] = i;
  for (int i = 0; i < n; i++) {
    for (int j : pr[a[i]]) {
      int k = id[j];
      par[getPar(i)] = getPar(k);
    }
  }
  for (int i = 0; i < n; i++) {
    set<int> p;
    for (int j : pr[a[i]])
      p.insert(getPar(id[j]));
    for (int j : pr[a[i] + 1])
      p.insert(getPar(id[j]));
    for (int x : p)
      for (int y : p)
        if (x != y) {
          con[x].insert(y);
          con[y].insert(x);
        }
  }
  for (int i = 0; i < q; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u;
    --v;
    u = getPar(u);
    v = getPar(v);
    if (u == v) {
      puts("0");
    } else {
      if (con[u].count(v))
        puts("1");
      else
        puts("2");
    }
  }
}