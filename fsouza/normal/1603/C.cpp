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

vector<pair<int, int>> get_splits(int value) {
  vector<int> cands_a;
  {
    int div;
    for (div = 1; div * div <= value; ++div)
      cands_a.push_back((value + (div-1)) / div);
    for (int rep = 0; rep < 5; ++rep) {
      cands_a.push_back((value + (div-1)) / div);
      ++div;
    }
  }
  reverse(cands_a.begin(), cands_a.end());
  cands_a.resize(unique(cands_a.begin(), cands_a.end()) - cands_a.begin());

  vector<int> cands_b;
  {
    int res;
    for (res = 1; res * res <= value; ++res) {
      cands_b.push_back(res);
    }
    for (int rep = 0; rep < 5; ++rep) {
      cands_b.push_back(res);
      ++res;
    }
  }

  vector<int> cands(cands_a.size() + cands_b.size());
  merge(cands_a.begin(), cands_a.end(), cands_b.begin(), cands_b.end(),
        cands.begin());
  cands.resize(unique(cands.begin(), cands.end()) - cands.begin());
  while (cands.back() > value) cands.pop_back();

  vector<pair<int, int>> result;
  for (int end_value : cands) {
    int nsplit = max(value / end_value - 2, 1);
    while ((value + (nsplit-1)) / nsplit > end_value)
      ++nsplit;

    if ((value + (nsplit-1)) / nsplit == end_value)
      result.emplace_back(end_value, nsplit - 1);
  }
  assert(result.back().first == value);
  return result;
}

const int mod = 998244353;

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    vector<int> values(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &values[i]);

    int result = 0;
    vector<pair<int, int>> prev_dp = {{1, 0}};
    for (int i = 0; i < n; ++i) {
      vector<pair<int, int>> splits = get_splits(values[i]);
      vector<pair<int, int>> dp;
      int cur = 0;

      for (pair<int, int> split : splits) {
        int not_even = (values[i] % split.first != 0 ? 1 : 0);
        while (cur + 1 < (int)prev_dp.size() && prev_dp[cur + 1].first <= split.first - not_even)
          ++cur;

        int dp_s = ((lint)(i + 1) * split.second + prev_dp[cur].second) % mod;

        dp.emplace_back(split.first, dp_s);
      }

      result += dp.back().second;
      if (result >= mod) result -= mod;
      prev_dp = dp;
    }

    printf("%d\n", result);
  }
  return 0;
}