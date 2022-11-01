#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair <int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> cnt(1'001);
  for (int i = 0; i < n * n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  vector <vector <vector <pii>>> sq(5);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      vector <pii> cur;
      if (n - i - 1 < i || n - j - 1 < j)
        continue;
      cur.push_back({i, j});
      cur.push_back({n - i - 1, j});
      cur.push_back({i, n - j - 1});
      cur.push_back({n - i - 1, n - j - 1});
      sort(cur.begin(), cur.end());
      cur.resize(unique(cur.begin(), cur.end()) - cur.begin());
      sq[cur.size()].push_back(cur);
    }
  vector <vector <int>> mat(n, vector <int>(n));
  for (int k = 4; k >= 1; k /= 2) {
    for (int i = 1; i <= 1000; i++) {
      while (cnt[i] >= k) {
        if (sq[k].empty())
          break;
        cnt[i] -= k;
        for (auto &now : sq[k].back())
          mat[now.first][now.second] = i;
        sq[k].pop_back();
      }
    }
  }
  for (int i = 1; i <= 1'000; i++)
    if (cnt[i]) {
      cout << "NO\n";
      return 0;
    }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << mat[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}