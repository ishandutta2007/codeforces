#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, d;
  cin >> n >> k >> d;
  vector <vector <int>> ans(d, vector <int>(n));
  for (int i = 0; i < d; i++)
    for (int j = 0; j < n; j++) {
      int tmp = j;
      for (int it = 0; it < min(25, i); it++)
        tmp /= k;
      ans[i][j] = tmp % k;
    }
  int val = 1;
  for (int i = 0; i < d; i++) {
    val *= k;
    if (val > n)
      break;
  }
  if (val < n) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < n; j++)
      cout << ans[i][j] + 1 << ' ';
    cout << '\n';
  }
  return 0;
}