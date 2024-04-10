#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int a[100005], b[100005];
vector<int> v[100005];
int it[100005];

int dp[2][100005];

int main() {
  int n, m, s, e;
  scanf("%d%d%d%d", &n, &m, &s, &e);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    v[a[i]].push_back(i);
  }
  for (int i = 1; i <= 100000; ++i)
    v[i].push_back(n + 1);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i]);
  }
  // cout << sizeof(dp) << endl;
  int cur = 0, next = 1;
  memset(dp[cur], -1, sizeof(dp[cur]));
  for (int t = 0; t <= 302; ++t) {
    int min_pos = t == 0 ? -1 : (n - 1);
    // cout << min_pos << endl;
    memset(it, 0, sizeof(it));
    for (int i = 0; i < m; ++i) {
      int w = upper_bound(v[b[i]].begin(), v[b[i]].end(), min_pos) - v[b[i]].begin();
      // while (w < v[b[i]].size() && v[b[i]][w] <= min_pos) ++w;
      // it[b[i]] = w;
      dp[next][i] = v[b[i]][w];
      min_pos = min(min_pos, dp[cur][i]);
    }
    // for (int i = 0; i < m; ++i) {
    //   cout << dp[next][i] << "  ";
    // }
    // cout << endl;
    bool can = false;
    for (int i = 0; i < m; ++i) {
      if (dp[next][i] < n && e * (t + 1) + (i + 1) + dp[next][i] + 1 <= s) {
        can = true;
        // cout << i << "  " << dp[next][i] << endl;
        break;
      }
    }
    if (!can) {
      printf("%d\n", t);
      return 0;
    }
    cur ^= 1; next ^= 1;
  }
  return 0;
}