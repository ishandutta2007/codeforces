#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    bool flag = false;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i + 1 < n; i++)
      if (a[i] != a[i + 1])
        flag = true;
    if (!flag) {
      cout << "NO" << '\n';
      continue;
    }
    int id = 1;
    for (int i = 2; i < n; i++)
      if (a[i] != a[0])
        id = i;
    vector <pair <int, int>> ans;
    ans.push_back({0, id});
    for (int i = 1; i < n; i++) {
      if (i == id)
        continue;
      if (a[i] == a[0])
        ans.push_back({i, id});
      else
        ans.push_back({i, 0});
    }
    cout << "YES\n";
    for (auto &now : ans)
      cout << now.first + 1 << ' ' << now.second + 1 << '\n';
  }
  return 0;
}