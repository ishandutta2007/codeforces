#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <vector <int>> pos(n + 1, vector <int>(1, -1));
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      pos[x].push_back(i);
    }
    for (int i = 0; i <= n; i++)
      pos[i].push_back(n);
    vector <int> ans(n + 2, INF);
    for (int i = 0; i <= n; i++) {
      int maxdiff = 0;
      for (int j = 0; j + 1 < (int)pos[i].size(); j++)
        maxdiff = max(maxdiff, pos[i][j + 1] - pos[i][j]);
      ans[maxdiff] = min(ans[maxdiff], i);
    }
    for (int i = 1; i <= n; i++)
      ans[i] = min(ans[i], ans[i - 1]);
    for (int i = 1; i <= n; i++) {
      if (ans[i] == INF)
        ans[i] = -1;
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}