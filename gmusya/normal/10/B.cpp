#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <vector <bool>> used(k + 1, vector<bool>(k + 1));
  int c = (k + 1) / 2;
  for (int i = 0; i < n; i++) {
    int len;
    cin >> len;
    int f = 1e9;
    pair <int, int> ans = {-1, -1};
    for (int x = 1; x <= k; x++)
      for (int y = 1; y + len - 1 <= k; y++) {
        bool flag = true;
        int tmpf = 0;
        for (int z = y; z <= y + len - 1; z++) {
          if (used[x][z])
            flag = false;
          tmpf += abs(c - x) + abs(c - z);
        }
        if (flag && tmpf < f) {
          ans = {x, y};
          f = tmpf;
        }
    }
    if (ans.first == -1) {
      cout << -1 << '\n';
      continue;
    }
    cout << ans.first << ' ' << ans.second << ' ' << ans.second + len - 1 << '\n';
    for (int i = ans.second; i <= ans.second + len - 1; i++)
      used[ans.first][i] = true;
  }
  return 0;
}