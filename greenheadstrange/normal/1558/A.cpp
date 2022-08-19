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

void solve() {
  int a, b;
  scanf("%d%d", &a, &b);
  set<int> r;
  for (int p = 0; p <= 1; p++) {
    int sa = (a + b + 1 - p) / 2, sb = a + b - sa;
    int lp = abs(sa - a), rp = lp;
    if (sa < a) {
      rp = lp + 2 * min(sa, b);
    } else {
      rp = lp + 2 * min(sb, a);
    }
    for (int j = lp; j <= rp; j += 2)
      r.insert(j);
  }
  printf("%d\n", (int)r.size());
  for (auto x : r)
    printf("%d ", x);
  printf("\n");
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++)
    solve();
}