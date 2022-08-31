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

int n, a[maxn], b[maxn];
vi son[maxn];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    son[i].clear();
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    a[i] = -1;
    son[b[i]].pb(i);
  }
  vi leaf;
  vi wrong;
  for (int i = 1; i <= n; i++) {
    if (son[i].empty())
      leaf.pb(i);
    else {
      int lef = -1;
      for (auto y : son[i]) {
        if (son[y].empty())
          lef = y;
      }
      if (lef == -1)
        lef = son[i][0];
      a[lef] = i;
      for (auto y : son[i])
        if (y != lef)
          wrong.pb(y);
    }
  }
  int m = wrong.size();
  while (true) {
    random_shuffle(wrong.begin(), wrong.end());
    bool dif = 1;
    for (int i = 0; i < m; i++)
      if (wrong[i] == leaf[i]) {
        dif = 0;
        break;
      }
    if (dif)
      break;
  }
  for (int i = 0; i < m; i++)
    a[wrong[i]] = leaf[i];
  printf("%d\n", n - m);
  for (int i = 1; i <= n; i++)
    printf("%d ", a[i]);
  puts("");
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}