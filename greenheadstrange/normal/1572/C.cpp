// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 3005 /*rem*/
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

int n, a[maxn], vis[maxn][maxn], dp[maxn][maxn], T2;
int nxt[maxn];
int solve(int l, int r) {
  if (vis[l][r] == T2)
    return dp[l][r];
  vis[l][r] = T2;
  if (l >= r)
    return dp[l][r] = 0;
  dp[l][r] = solve(l + 1, r);
  for (int j = nxt[l]; j <= r; j = nxt[j])
    dp[l][r] = max(dp[l][r], solve(l + 1, j - 1) + 1 + solve(j, r));
  return dp[l][r];
}
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (a[i] == a[i - 1]) {
      --i;
      --n;
    }
  }
  for (int i = 1; i <= n; i++) {
    nxt[i] = n + 1;
    for (int j = i + 1; j <= n; j++)
      if (a[i] == a[j]) {
        nxt[i] = j;
        break;
      }
  }
  T2++;
  printf("%d\n", n - 1 - solve(1, n));
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++)
    solve();
}