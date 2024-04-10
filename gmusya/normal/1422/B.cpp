#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

typedef long long ll;

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector <vector <ll>> a(n, vector <ll>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> a[i][j];
    ll ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (i > n - i - 1 || j > m - j - 1) continue;
        set <pair <ll, ll>> s;
        s.insert({i, j});
        s.insert({n - i - 1, j});
        s.insert({n - i - 1, m - j - 1});
        s.insert({i, m - j - 1});
        vector <ll> arr;
        for (auto &now : s)
          arr.push_back(a[now.first][now.second]);
        sort(arr.begin(), arr.end());
        if (arr.size() == 1) continue;
        if (arr.size() == 2) {
          ans += arr[1] - arr[0];
          continue;
        }
        ans += arr[3] - arr[2];
        ans += arr[1] - arr[0];
        ans += 2 * (arr[2] - arr[1]);
      }
    cout << ans << '\n';
  }
  return 0;
}