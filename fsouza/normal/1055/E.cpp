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

struct seg_t {
  int l, r;
};

int get_max_good(const vector<int> &values, const vector<seg_t> &segs,
                 int choose, int limit) {
  const int n = values.size();
  vector<int> good_pref(n + 1);
  good_pref[0] = 0;
  for (int i = 0; i < n; ++i)
    good_pref[i + 1] = good_pref[i] + (values[i] <= limit);

  vector<int> max_end(n, -1);
  for (const seg_t &seg : segs)
    max_end[seg.l] = max(max_end[seg.l], seg.r);
  vector<int> max_end_until(n, -1);
  max_end_until[0] = max_end[0];
  for (int i = 1; i < n; ++i)
    max_end_until[i] = max(max_end_until[i - 1], max_end[i]);

  vector<int> dp(n + 1, 0);
  vector<int> next_dp = dp;
  for (int rep = 0; rep < choose; ++rep) {
    copy(dp.begin(), dp.end(), next_dp.begin());

    for (int i = 0; i < n; ++i) {
      int new_end = max_end_until[i];
      if (new_end >= i) {
        int add = good_pref[new_end + 1] - good_pref[i];
        next_dp[new_end + 1] = max(next_dp[new_end + 1], dp[i] + add);
      }
    }
    for (int i = 0; i < n; ++i)
      next_dp[i + 1] = max(next_dp[i + 1], next_dp[i]);

    swap(dp, next_dp);
  }

  return dp[n];
}

int main() {
  int n, nseg, choose, k;
  scanf("%d %d %d %d", &n, &nseg, &choose, &k), --k;

  vector<int> values(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &values[i]);
  vector<seg_t> segs(nseg);
  for (int i = 0; i < nseg; ++i) {
    scanf("%d %d", &segs[i].l, &segs[i].r), --segs[i].l, --segs[i].r;
  }

  vector<int> diff_values = values;
  sort(diff_values.begin(), diff_values.end());
  diff_values.resize(unique(diff_values.begin(), diff_values.end()) -
                     diff_values.begin());
  int l = 0, r = (int)diff_values.size();
  while (l < r) {
    int m = l + (r - l) / 2;
    int max_good = get_max_good(values, segs, choose, diff_values[m]);
    if (max_good >= k + 1) r = m;
    else l = m + 1;
  }

  if (r == (int)diff_values.size()) printf("-1\n");
  else printf("%d\n", diff_values[l]);

  return 0;
}