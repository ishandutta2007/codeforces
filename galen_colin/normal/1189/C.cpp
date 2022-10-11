#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j;
typedef long long ll;

ll n, q, Q, k;
int a[100001], red[100001][25];
int dp[100001][25];

int main() {
  io;
  cin >> n;
  f0r(i, n) cin >> a[i];
  cin >> Q;
  f0r(i, n) red[i][0] = a[i];
  for (int i = n-1; i >= 0; i--) {
    int t = 0;
    for (int j = 2; j + i <= n; j *= 2) { //len
      t++;
      red[i][t] = (red[i][t-1] + red[i + j/2][t-1]) % 10;
    }
  }
  
  f0r(i, n) dp[i][0] = 0;
  for (int i = n-1; i >= 0; i--) {
    int t = 0;
    for (int j = 2; j + i <= n; j *= 2) { //len
      t++;
      dp[i][t] = dp[i][t-1] + dp[i + j/2][t-1] + ((red[i][t-1] + red[i + j/2][t-1]) >= 10);
    }
  }
  f0r(q, Q) {
    int l, r;
    cin >> l >> r;
    int t = 0;
    for (int k = r - l + 1; k > 1; k /= 2) {
      t++;
    }
    cout << dp[--l][t] << endl;
  }
}