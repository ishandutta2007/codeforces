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
int a[maxn][10];
void solve() {
  scanf("%d", &n);
  auto cmp = [&](int x, int y) {
    int c = 0;
    for (int i = 0; i < 5; i++)
      c += a[x][i] < a[y][i];
    return c >= 3;
  };
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 5; j++) {
      scanf("%d", &a[i][j]);
    }
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (cmp(i, ans))
      ans = i;
  bool win = true;
  for (int i = 0; i < n; i++)
    if (i != ans && cmp(i, ans))
      win = false;
  if (win) {
    printf("%d\n", ans + 1);
  } else
    puts("-1");
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}