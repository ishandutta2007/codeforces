#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <vector <int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        char c;
        cin >> c;
        a[i][j] = c - '0';
      }
    vector <pair <int, int>> cnt0, cnt1;
    if (a[0][1] == 0)
      cnt0.push_back({0, 1});
    else
      cnt1.push_back({0, 1});
    if (a[1][0] == 0)
      cnt0.push_back({1, 0});
    else
      cnt1.push_back({1, 0});
    if (a[n - 1][n - 2] == 0)
      cnt1.push_back({n - 1, n - 2});
    else
      cnt0.push_back({n - 1, n - 2});
    if (a[n - 2][n - 1] == 0)
      cnt1.push_back({n - 2, n - 1});
    else
      cnt0.push_back({n - 2, n - 1});
    if (cnt0.size() < cnt1.size()) {
      cout << cnt0.size() << '\n';
      for (auto &now : cnt0)
        cout << now.first + 1 << ' ' << now.second + 1 << '\n';
    } else {
      cout << cnt1.size() << '\n';
      for (auto &now : cnt1)
        cout << now.first + 1 << ' ' << now.second + 1 << '\n';
    }
  }
  return 0;
}