#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int x = 0;
  for (int i = 0; i < n; i++)
    x ^= a[i];
  vector <pair <pair <int, int>, int>> ans;
  if (n % 2 == 1) {
    for (int i = 0; i + 2 < n; i += 2) {
      int c = (a[0] ^ a[i + 1] ^ a[i + 2]);
      ans.push_back({{0, i + 1}, i + 2});
      a[0] = a[i + 1] = a[i + 2] = c;
    }
    for (int i = 0; i + 2 < n; i += 2) {
      int c = (a[0] ^ a[i + 1] ^ a[i + 2]);
      ans.push_back({{0, i + 1}, i + 2});
      a[0] = a[i + 1] = a[i + 2] = c;
    }
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (auto &now : ans)
      cout << now.first.first + 1 << ' ' << now.first.second + 1 << ' ' << now.second + 1 << '\n';
    return 0;
  }
  int pos = 0;
  if (x) {
    cout << "NO";
    return 0;
  }
  vector <int> ids;
  for (int i = 0; i < n; i++) {
    if (i == pos)
      continue;
    ids.push_back(i);
  }
  cout << "YES\n";
  for (int i = 0; i + 2 < n; i += 2)
    ans.push_back({{ids[0], ids[i + 1]}, ids[i + 2]});
  cout << ans.size() * 2 << '\n';
  for (auto &now : ans)
    cout << now.first.first + 1 << ' ' << now.first.second + 1 << ' ' << now.second + 1 << '\n';
  for (auto &now : ans)
    cout << now.first.first + 1 << ' ' << now.first.second + 1 << ' ' << now.second + 1 << '\n';
  return 0;
}