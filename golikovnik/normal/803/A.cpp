#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  if (k > n * n) {
    cout << "-1\n";
    return 0;
  }
  vector<vector<int>> ans(n, vector<int>(n));
  for (int i = 0; i < n && k; ++i) {
    int shift = 0;
    while (k && shift < n - i) {
      if (k == 1) {
        --k;
        if (!shift) {
          ans[i][i] = 1;
        } else {
          ans[i + 1][i + 1] = 1;
        }
        break;
      }
      ans[i][i + shift] = ans[i + shift][i] = 1;
      --k;
      k -= bool(shift);
      ++shift;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}