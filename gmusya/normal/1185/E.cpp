#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector <vector <pair <int, int>>> cnt(26);
    vector<vector<char>> c(n, vector<char>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        cin >> c[i][j];
        if (c[i][j] != '.')
          cnt[c[i][j] - 'a'].push_back({i, j});
        else
          c[i][j] = 'a' - 1;
      }
    for (int i = 0; i < 26; i++)
      sort(cnt[i].begin(), cnt[i].end());
    vector <pair <pair <int, int>, pair <int, int>>> ans;
    pair <int, int> empt;
    bool flag = true;
    for (int it = 25; it >= 0; it--) {
      if (cnt[it].empty()) {
        if (!ans.empty())
          ans.push_back({empt, empt});
        continue;
      }
      int x1, x2, y1, y2;
      tie(x1, y1) = tie(cnt[it][0].first, cnt[it][0].second);
      tie(x2, y2) = tie(cnt[it].back().first, cnt[it].back().second);
      if (x1 != x2 && y1 != y2) {
        flag = false;
        continue;
      }
      int cnt1 = 0;
      for (int i = x1; i <= x2; i++)
        for (int j = y1; j <= y2; j++) {
          if (c[i][j] < ('a' + it))
            flag = false;
          cnt1 += (c[i][j] == ('a' + it));
        }
      if (cnt1 != cnt[it].size())
        flag = false;
      empt = {x1, y1};
      ans.push_back({{x1, y1}, {x2, y2}});
    }
    if (!flag) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      cout << ans.size() << '\n';
      reverse(ans.begin(), ans.end());
      for (auto [a, b] : ans)
        cout << a.first + 1 << ' ' << a.second + 1 << ' ' << b.first + 1 << ' ' << b.second + 1 << '\n';
    }
  }
  return 0;
}