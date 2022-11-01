#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <pair <int, int>> ans;
  for (int i = 1; i <= k; i++)
    for (int j = i + 1; j <= k; j++) {
      if (n <= 0)
        break;
      ans.push_back({i, j});
      ans.push_back({j, i});
      n -= 2;
    }
  if (n > 0) {
    cout << "NO\n";
    return 0;
  }
  if (n < 0)
    ans.pop_back();
  cout << "YES\n";
  for (auto &now : ans)
    cout << now.first << ' ' << now.second << '\n';
  return 0;
}