#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <string>

typedef long long ll;

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s, t;
  cin >> s >> t;
  if (t[0] == t[1]) {
    for (int i = 0; i < n; i++)
      if (s[i] != t[0] && k > 0) {
        s[i] = t[0];
        k--;
      }
    ll cnt = 0;
    for (int i = 0; i < n; i++)
      cnt += (s[i] == t[0]);
    cout << cnt * (cnt - 1) / 2 << '\n';
    return 0;
  }
  vvvi dp1(n + 1, vvi(n + 1, vi(n + 1, -INF)));
  dp1[0][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp1[i] = dp1[i - 1];
    char ch = s[i - 1];
    for (int a = 0; a < n; a++)
      for (int cnt = 0; cnt + (ch != t[0]) <= n; cnt++)
        dp1[i][a + 1][cnt + (ch != t[0])] = max(dp1[i][a + 1][cnt + (ch != t[0])], dp1[i - 1][a][cnt]);
    for (int a = 0; a <= n; a++)
      for (int cnt = 0; cnt + (ch != t[1]) <= n; cnt++)
        dp1[i][a][cnt + (ch != t[1])] = max(dp1[i][a][cnt + (ch != t[1])], dp1[i - 1][a][cnt] + a);
  }
  vvvi dp2(n + 1, vvi(n + 1, vi(n + 1, -INF)));
  dp2[n][0][0] = 0;
  for (int i = n - 1; i >= 0; i--) {
    dp2[i] = dp2[i + 1];
    char ch = s[i];
    for (int b = 0; b < n; b++)
      for (int cnt = 0; cnt + (ch != t[1]) <= n; cnt++)
        dp2[i][b + 1][cnt + (ch != t[1])] = max(dp2[i][b + 1][cnt + (ch != t[1])], dp2[i + 1][b][cnt]);
    for (int b = 0; b <= n; b++)
      for (int cnt = 0; cnt + (ch != t[0]) <= n; cnt++)
        dp2[i][b][cnt + (ch != t[0])] = max(dp2[i][b][cnt + (ch != t[0])], dp2[i + 1][b][cnt] + b);
  }
  for (int i = 0; i <= n; i++)
    for (int a = 0; a <= n; a++)
      for (int cnt = 1; cnt <= n; cnt++)
        dp1[i][a][cnt] = max(dp1[i][a][cnt], dp1[i][a][cnt - 1]);
  for (int i = 0; i <= n; i++)
    for (int b = 0; b <= n; b++)
      for (int cnt = 1; cnt <= n; cnt++)
        dp2[i][b][cnt] = max(dp2[i][b][cnt], dp2[i][b][cnt - 1]);
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int a = 0; a <= n; a++)
      for (int b = 0; b <= n; b++)
        for (int cnt = 0; cnt <= k; cnt++)
          ans = max(ans, dp1[i][a][cnt] + dp2[i][b][k - cnt] + a * b);
  cout << ans;
  return 0;
}