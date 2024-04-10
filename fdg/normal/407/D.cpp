#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[404][404];
int cnt[404] = {0};

const int inf = 1000000;

// set<pair<int, int> > f;
// set<pair<int, int> >::iterator it;
// multiset<int> cf;
// int mn[404];

// set<int> nums[16002];
// set<int>::iterator num_it;

short nx[402][160002];
int dp[402][402];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &arr[i][j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      dp[i][j] = m;
    for (int j = 0; j <= 160000; ++j)
      nx[i][j] = m;
  }
  int ans = 1;
  for (int j = m - 1; j >= 0; --j) {
    for (int i = 0; i < n; ++i) {
      dp[i][i] = min(dp[i][i], (int) nx[i][arr[i][j]]);
      ans = max(ans, dp[i][i] - j);
    }
    for (int i = 0; i < n; ++i) {
      nx[i][arr[i][j]] = j;
    }
    for (int i1 = n - 1; i1 >= 0; --i1) {
      for (int i2 = i1 + 1; i2 < n; ++i2) {
        dp[i1][i2] = min(dp[i1][i2], min(min(dp[i1 + 1][i2], dp[i1][i2 - 1]),
          min((int) nx[i1][arr[i2][j]], (int) nx[i2][arr[i1][j]])));
        ans = max(ans, (i2 - i1 + 1) * (dp[i1][i2] - j));
      }
    }
  }
  // for (int l = 0; l < m; ++l) {
  //   for (int i = 1; i <= 16000; ++i)
  //     nums[i].clear();
  //   // f.clear();
  //   for (int i = 0; i <= n; ++i)
  //     mn[i] = inf;
  //   for (int r = l; r < m; ++r) {
  //     if ((m - 1 - l + 1) * n <= ans) break;
  //     // cout << l << "  " << r << endl;
  //     for (int i = 0; i < n; ++i) {
  //       // it = f.lower_bound(make_pair(arr[i][r], i));
  //       num_it = nums[arr[i][r]].lower_bound(i);
  //       if (num_it != nums[arr[i][r]].end()) {
  //         mn[i] = min(mn[i], *num_it);
  //       }
  //       if (num_it != nums[arr[i][r]].begin()) {
  //         --num_it;
  //         // cout << "It:  " << i << "  " << it->second << endl;
  //         // if (it->first == arr[i][r]) {
  //           mn[*num_it] = min(mn[*num_it], i);
  //         // }
  //       }
  //       // f.insert(make_pair(arr[i][r], i));
  //       nums[arr[i][r]].insert(i);
  //     }
  //     // for (int i = 0; i < n; ++i) {
  //     //   f.insert(make_pair(arr[i][r], i));
  //     // }

  //     // cf.clear();
  //     int top = 0;
  //     memset(cnt, 0, sizeof(cnt));
  //     for (int i = 0; i < n; ++i) {
  //       if (mn[i] != inf)
  //         cnt[mn[i]]++;
  //       while (top <= i && cnt[i]) {
  //         if (mn[top] != inf)
  //           --cnt[mn[top]];
  //         ++top;
  //       }
  //       if ((r - l + 1) * (n - top) <= ans) break;
  //       ans = max(ans, (r - l + 1) * (i - top + 1));  
  //     }
  //   }
  // }
  printf("%d\n", ans);
  return 0;
}