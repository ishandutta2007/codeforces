#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vvi a(n, vi(m));
  int s = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (c == '*')
        a[i][j] = 1;
      s += a[i][j];
    }
  for (int i = 1; i + 1 < n; i++)
    for (int j = 1; j + 1 < m; j++)
      if (a[i - 1][j] && a[i + 1][j] && a[i][j - 1] && a[i][j + 1]) {
        if (!a[i][j])
          continue;
        int cnt = 1;
        for (int x = i - 1; x >= 0 && a[x][j]; x--)
          cnt++;
        for (int x = i + 1; x < n && a[x][j]; x++)
          cnt++;
        for (int x = j - 1; x >= 0 && a[i][x]; x--)
          cnt++;
        for (int x = j + 1; x < m && a[i][x]; x++)
          cnt++;
        if (cnt == s)
          cout << "YES\n";
        else
          cout << "NO\n";
        return 0;
      }
  cout << "NO\n";
  return 0;
}