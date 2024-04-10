#include <iostream>
#include <vector>

using namespace std;

typedef pair <int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++)
      a[i] = i;
    vector <bool> flag(n + 1);
    vector <pii> ans;
    for (int i = 3; i < n; i++) {
      if (i == 2 || i == 4 || i == 16 || i == 256 || i == 65536)
        continue;
      ans.push_back({i, i + 1});
    }
    if (n > 65536) {
      ans.push_back({n, 65536});
      ans.push_back({n, 65536});
    }
    if (n < 65536 && n > 256) {
      ans.push_back({n, 256});
      ans.push_back({n, 256});
    }
    if (n < 256 && n > 16) {
      ans.push_back({n, 16});
      ans.push_back({n, 16});
    }
    if (n < 16 && n > 4) {
      ans.push_back({n, 4});
      ans.push_back({n, 4});
    }
    if (n < 4 && n > 2) {
      ans.push_back({n, 2});
      ans.push_back({n, 2});
    }
    if (n >= 65536) {
      ans.push_back({65536, 256});
      ans.push_back({65536, 256});
    }
    if (n >= 256) {
      ans.push_back({256, 16});
      ans.push_back({256, 16});
    }
    if (n >= 16) {
      ans.push_back({16, 4});
      ans.push_back({16, 4});
    }
    if (n >= 4) {
      ans.push_back({4, 2});
      ans.push_back({4, 2});
    }
    cout << ans.size() << '\n';
    for (auto &now : ans)
      cout << now.first << ' ' << now.second << '\n';
  }
  return 0;
}