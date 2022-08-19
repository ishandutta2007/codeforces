// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 2005 /*rem*/
#define mod 1000000007
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

int n, d[maxn];
vi ans[maxn];
set<pi> e;
vi query(int x) {
  if (!ans[x].empty()) {
    return ans[x];
  }
  printf("? %d\n", x);
  fflush(stdout);
  for (int i = 1; i <= n; i++) {
    scanf("%d", d + i);
    if (d[i] == 1) {
      e.insert({x, i});
      e.insert({i, x});
    }
  }
  ans[x] = vi(d + 1, d + n + 1);
  return ans[x];
}

int main() {
  scanf("%d", &n);
  vi ans = query(1);
  vi L, R;
  for (int i = 1; i <= n; i++)
    if (ans[i - 1] % 2 == 0)
      L.pb(i);
    else
      R.pb(i);
  if (L.size() > R.size())
    swap(L, R);
  for (auto x : L)
    query(x);
  printf("!\n");
  for (auto x : e)
    if (x.fi < x.se)
      printf("%d %d\n", x.fi, x.se);
  fflush(stdout);
}