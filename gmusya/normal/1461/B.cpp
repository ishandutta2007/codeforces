#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vvi a(n + 1, vi(m + 1)), s(n + 1, vi(m + 1));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        char c;
        cin >> c;
        if (c == '*')
          a[i][j] = 1;
      }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        s[i][j] = s[i][j - 1] + a[i][j];
    int ans = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        for (int c = 0; c + i <= n && j - c >= 1 && j + c <= m; c++) {
          if (s[i + c][j + c] - s[i + c][j - c - 1] != 2 * c + 1)
            break;
          ans++;
        }
      }
    cout << ans << '\n';
  }
  return 0;
}