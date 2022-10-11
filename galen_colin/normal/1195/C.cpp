#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
ll i, j;
const ll mod = 1e9 + 7;

ll n, q, Q, T, m, k, r, x;
ll a[2][100001], dp[3][100002];

int main() {
  io;
  cin >> n;
  f0r(i, n) cin >> a[0][i];
  f0r(i, n) cin >> a[1][i];
  ms(dp, 0);
  f1r(i, 1, n+1) {
    dp[0][i] = a[0][i-1] + max(dp[1][i-1], dp[2][i-1]);
    dp[1][i] = a[1][i-1] + max(dp[0][i-1], dp[2][i-1]);
    dp[2][i] = max(max(dp[0][i-1], dp[1][i-1]), dp[2][i-1]);
  }
  cout << max(max(dp[0][n], dp[1][n]), dp[2][n]) << endl;
}