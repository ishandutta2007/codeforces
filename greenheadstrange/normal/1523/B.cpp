// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 10005 /*rem*/
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

int n;
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%*d");
  printf("%d\n", 3 * n);
  for (int x = 1; x <= n; x += 2) {
    int y = x + 1;
    printf("2 %d %d\n", x, y);
    printf("1 %d %d\n", x, y);
    printf("2 %d %d\n", x, y);
    printf("2 %d %d\n", x, y);
    printf("1 %d %d\n", x, y);
    printf("2 %d %d\n", x, y);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}