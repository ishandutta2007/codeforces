#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> v[2];

int calc(const vector<int>& vv, int x) {
  int ret = 0;
  for (int i = 0; i < vv.size(); ++i)
    if (vv[i] == x) {
      ++ret;
    }
  return ret;
}

bool t36;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int s, f;
    scanf("%d%d", &s, &f);
    v[s].push_back(f);
    // if (i == 0 && f == 996875577) t36 = true;
  }
  for (int i = 0; i < 2; ++i)
    sort(v[i].begin(), v[i].end());
  int ans = 0; long long cnt = 0;
  for (int i = 0; i < v[1].size(); ++i) {
    // if (i > 0 && v[1][i] == v[1][i - 1]) continue;
    int p1 = lower_bound(v[0].begin(), v[0].end(), v[1][i]) - v[0].begin() - 1;
    int p2 = upper_bound(v[0].begin(), v[0].end(), v[1][i]) - v[0].begin();
    int x = p1 + 1, y = p2 - p1 - 1, z = v[0].size() - x - y;
    if (x >= 0 && y >= 0 && z >= 0) {
      ans = 2 * n; 
      cnt += 1LL * x * (z + y) + 1LL * y * z;
      cnt += 1LL * y * (y - 1) / 2;
      // cout << x << "  " << y << " " << z << endl;
    }
  }
  for (int i = 0; i < v[0].size(); ++i) {
    // if (i > 0 && v[0][i] == v[0][i - 1]) continue;
    int p1 = lower_bound(v[1].begin(), v[1].end(), v[0][i]) - v[1].begin() - 1;
    int p2 = upper_bound(v[1].begin(), v[1].end(), v[0][i]) - v[1].begin();
    int x = p1 + 1, y = p2 - p1 - 1, z = v[1].size() - x - y;
    if (x >= 0 && y >= 0 && z >= 0) {
      ans = 2 * n; 
      cnt += 1LL * x * (z + y) + 1LL * y * z;
      cnt += 1LL * y * (y - 1) / 2;
      // cout << x << "  " << y << " " << z << endl;
    }
  }
  if (t36) cout << ans << " " << cnt << endl;
  if (cnt == 0) ans = 0;
  if (ans == 0) {
    if (v[1].size() && v[0].size()) {
      if (v[1][0] >= v[0].back()) {
        int x = calc(v[1], v[1][0]),
            y = calc(v[0], v[0].back()),
            z = m - x - y;
        ans = 2 * (n - (v[1][0] + n - v[0].back() - n));
        // cout << x << "  " << y << endl;
        cnt = 1LL * x * y * z + 1LL * x * (x - 1) / 2 * y + 1LL * x * y * (y - 1) / 2;
      } else if (v[0][0] >= v[1].back()) {
        int x = calc(v[0], v[0][0]),
            y = calc(v[1], v[1].back()),
            z = m - x - y;
        ans = 2 * (n - (v[0][0] + n - v[1].back() - n));
        // cout << x << "  " << y << endl;
        cnt = 1LL * x * y * z + 1LL * x * (x - 1) / 2 * y + 1LL * x * y * (y - 1) / 2;
      }
    }
    if (t36) cout << ans << "  " << cnt << endl;
    if (v[1].size() > 2 && 2 * (v[1].back() - v[1][0]) >= ans) {
      if (2 * (v[1].back() - v[1][0]) > ans) {
        ans = 2 * (v[1].back() - v[1][0]);
        cnt = 0;
      }
      int x = calc(v[1], v[1].back()), y  = calc(v[1], v[1][0]), z = v[1].size() - x - y;
      if (v[1].back() == v[1][0]) {
        cnt += 1LL * x * (x - 1) * (x - 2) / 6;
      } else cnt += 1LL * x * y * z + 1LL * x * (x - 1) / 2 * y + 1LL * x * y * (y - 1) / 2;
    }
    if (t36) cout << ans << "  " << cnt << endl;
    if (v[0].size() > 2 && 2 * (v[0].back() - v[0][0]) >= ans) {
      if (2 * (v[0].back() - v[0][0]) > ans) {
        ans = 2 * (v[0].back() - v[0][0]);
        cnt = 0;
      }
      int x = calc(v[0], v[0].back()), y  = calc(v[0], v[0][0]), z = v[0].size() - x - y;
      if (t36) cout << x << " " << y << " " << z << endl;
      if (v[0].back() == v[0][0]) {
        cnt += 1LL * x * (x - 1) * (x - 2) / 6;
      } else cnt += 1LL * x * y * z + 1LL * x * (x - 1) / 2 * y + 1LL * x * y * (y - 1) / 2;
    }
    if (t36) cout << ans << "  " << cnt << endl;
  }
  // cout << ans << endl;
  cout << cnt << endl;
  return 0;
}