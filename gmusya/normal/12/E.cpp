#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <vector <int>> ans(n, vector <int>(n));
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j <= n - 1; j++) {
      ans[i][j] = (i + j + 1) % n;
      if (i + j >= n - 1)
        ans[i][j]++;
    }
  for (int i = 0; i < n; i++) {
    ans[i][n - 1] = ans[i][i];
    ans[n - 1][i] = ans[i][i];
    ans[i][i] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << ans[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}