#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;
typedef long double ldouble;

const int maxn = 100, lim_maxscore = 10 * maxn;
const ldouble inf = pow((ldouble)2, 200), alpha = 1.0 / (ldouble)0.9;

ldouble dp[2][maxn + 1][lim_maxscore + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  struct task_t {
    int diff, value;
  };

  int nt;
  cin >> nt;
  for (int test = 0; test < nt; ++test) {
    int n;
    cin >> n;
    ldouble c, maxt;
    cin >> c >> maxt;
    vector<task_t> tasks(n);
    int maxscore = 0;
    for (int i = 0; i < n; ++i) {
      cin >> tasks[i].diff >> tasks[i].value;
      maxscore += tasks[i].value;
    }

    sort(tasks.begin(), tasks.end(), [](const task_t &lhs, const task_t &rhs) {
      return lhs.diff < rhs.diff;
    });

    int now = 0, prev = 1;
    for (int so = 0; so <= n; ++so)
      for (int sc = 0; sc <= maxscore; ++sc)
        dp[now][so][sc] = inf;
    dp[now][0][0] = 0.0;

    for (int i = 0; i < n; ++i) {
      swap(now, prev);

      memcpy(dp[now], dp[prev], sizeof(dp[now]));
      for (int so = 0; so <= n; ++so)
        for (int sc = 0; sc <= maxscore; ++sc) {
          if (dp[prev][so][sc] == inf) continue;

          ldouble &res = dp[now][so + 1][sc + tasks[i].value];
          res = min(res, (dp[prev][so][sc] + tasks[i].diff) * alpha);
        }
    }

    int result = 0;
    for (int so = 0; so <= n; ++so)
      for (int sc = 0; sc <= maxscore; ++sc) {
        if (dp[now][so][sc] == inf) continue;
        ldouble k = dp[now][so][sc];

        ldouble train_t = max((sqrt(c * k) - 1) / c, (ldouble)0.0);
        ldouble total_t = k / (1 + train_t * c) + train_t + (ldouble)10 * so;
        if (total_t <= maxt) {
          result = max(result, sc);
        }
      }

    cout << result << "\n";
  }
  return 0;
}