// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
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

int n, a[maxn];

ll solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  bool al1 = true, alodd = true;
  ;
  ll s = 0;
  for (int i = 2; i <= n - 1; i++) {
    al1 &= a[i] == 1;
    alodd &= a[i] % 2 == 1;
    s += (a[i] + 1) / 2;
  }
  if (n == 3 && a[2] % 2 == 1) {
    return -1;
  }
  if (al1) return -1;
  return s;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) printf("%lld\n", solve());
}