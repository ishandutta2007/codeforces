#include <iostream>

using namespace std;

int ans[1000][1000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n / 2; i++)
    for (int j = 0; j < n / 2; j++) {
      ans[i][j] = 4 * (i * (n / 2) + j);
      ans[i][j + n / 2] = ans[i][j] + 1;
      ans[i + n / 2][j] = ans[i][j] + 2;
      ans[i + n / 2][j + n / 2] = ans[i][j] + 3;
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << ans[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}