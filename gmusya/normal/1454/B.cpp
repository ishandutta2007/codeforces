#include <iostream>
#include <vector>
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
    vector <pair <int, int>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a.begin(), a.end());
    int ans = -1;
    for (int i = 0; i < n; i++) {
      bool flag = true;
      if (i && a[i - 1].first == a[i].first)
        flag = false;
      if (i + 1 < n && a[i].first == a[i + 1].first)
        flag = false;
      if (flag) {
        ans = a[i].second + 1;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}