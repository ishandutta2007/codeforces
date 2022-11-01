#include <iostream>
#include <vector>

using namespace std;

int solve(vector <vector <int>> &a, int col) {
  int n = a.size();
  int ans = 0;
  {
    vector <bool> flag(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (a[i][j] == col)
          flag[i] = true;
    for (int i = 0; i < n; i++) {
      if (!flag[i])
        continue;
      int l = n + 1, r = -1;
      for (int j = 0; j < n; j++)
        if (a[i][j] == col) {
          l = min(l, j);
          r = max(r, j);
        }
      int len1 = r - l;
      int len2 = max(r, n - l - 1);
      for (int j = 0; j < n; j++) {
        if (!flag[i] && !flag[j])
          continue;
        if (flag[j])
          ans = max(ans, abs(i - j) * len2);
        else
          ans = max(ans, abs(i - j) * len1);
      }
    }
  }
  {
    vector <bool> flag(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (a[i][j] == col)
          flag[j] = true;
    for (int j = 0; j < n; j++) {
      if (!flag[j])
        continue;
      int l = n + 1, r = -1;
      for (int i = 0; i < n; i++)
        if (a[i][j] == col) {
          l = min(l, i);
          r = max(r, i);
        }
      int len1 = r - l;
      int len2 = max(r, n - l - 1);
      for (int i = 0; i < n; i++) {
        if (!flag[i])
          continue;
        if (flag[i])
          ans = max(ans, abs(i - j) * len2);
        else
          ans = max(ans, abs(i - j) * len1);
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <vector <int>> a(n, vector <int>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        char c;
        cin >> c;
        a[i][j] = c - '0';
      }
    for (int col = 0; col < 10; col++)
      cout << solve(a, col) << ' ';
    cout << '\n';
  }
  return 0;
}