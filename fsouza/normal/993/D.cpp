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

struct task_t {
  int power, ncpu;
  bool operator<(const task_t &o) const {
    if (power != o.power)
      return power < o.power;
    return ncpu > o.ncpu;
  }
};

int main() {
  int n;
  scanf("%d", &n);
  vector<task_t> tasks(n);
  int max_power = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &tasks[i].power);
    max_power = max(max_power, tasks[i].power);
  }
  for (int i = 0; i < n; ++i)
    scanf("%d", &tasks[i].ncpu);
  sort(tasks.begin(), tasks.end());

  lint left = 0, right = max_power * 1000LL;
  while (left < right) {
    lint mid = left + (right - left) / 2;

    static vector<lint> dp;
    static vector<lint> next_dp;
    dp.resize(n + 1);
    next_dp.resize(n + 1);

    fill(dp.begin(), dp.end(), LLONG_MAX);
    dp[0] = 0LL;

    for (int j = 0, i = j; i < n; i = j) {
      while (j < n && tasks[j].power == tasks[i].power) ++j;

      fill(next_dp.begin(), next_dp.end(), LLONG_MAX);

      for (int nr = 0; nr <= n; ++nr) {
        if (dp[nr] == LLONG_MAX) continue;

        lint acc_values = 0LL;
        for (int nkeep = 0; nkeep <= j - i; ++nkeep) {
          int nremove = j - i - nkeep;
          int nr2 = max(nr - nkeep, 0) + nremove;

          next_dp[nr2] = min(next_dp[nr2], dp[nr] + acc_values);

          if (nkeep + 1 <= j - i) {
            int k = i + nkeep;
            acc_values += 1000LL * tasks[k].power - mid * tasks[k].ncpu;
          }
        }
      }

      swap(dp, next_dp);
    }

    if (dp[0] <= 0) right = mid;
    else left = mid + 1;
  }
  printf("%lld\n", left);

  return 0;
}