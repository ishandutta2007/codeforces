#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n + 2);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  if (n > 75) {
    cout << 1;
    return 0;
  }
  a[n + 1] = 2e9;
  int ans = INF;
  vector <int> x(n + 2);
  for (int i = 1; i <= n; i++)
    x[i] = (a[i] ^ x[i - 1]);
  for (int l = 1; l <= n; l++)
    for (int m = l; m <= n; m++) {
      int val = (x[m] ^ x[l - 1]);
      if (val < a[l - 1] || val > a[m + 1]) {
        ans = min(ans, m - l);
        continue;
      }
      for (int r = m + 1; r <= n; r++) {
        int tmp = (x[r] ^ x[m]);
        if (tmp < val)
          ans = min(ans, r - l - 1);
      }
    }
  if (ans == INF)
    ans = -1;
  cout << ans;
  return 0;
}