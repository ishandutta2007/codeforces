#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(2 * n);
    for (int i = 0; i < 2 * n; i++)
      cin >> a[i];
    sort(a.begin(), a.end());
    bool flag = false;
    for (int i = 0; i + 1 < 2 * n; i++) {
      int x = a[i] + a[2 * n - 1];
      multiset <int> ms;
      for (int j = 0; j < 2 * n; j++)
        ms.insert(a[j]);
      vector <pair <int, int>> answer;
      for (int it = 0; it < n; it++) {
        int c = *ms.rbegin();
        ms.erase(ms.find(c));
        if (ms.find(x - c) == ms.end())
          break;
        answer.push_back({c, x - c});
        ms.erase(ms.find(x - c));
        x = c;
      }
      if (answer.size() == n) {
        flag = true;
        cout << "YES\n";
        cout << a[i] + a[2 * n - 1] << '\n';
        for (auto &now : answer)
          cout << now.first << ' ' << now.second << '\n';
        break;
      }
    }
    if (!flag)
      cout << "NO\n";
  }
  return 0;
}