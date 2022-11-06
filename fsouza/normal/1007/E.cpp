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

struct st_t { lint a, b, c; };

struct solver_t {
  vector<st_t> sts;
  int total_nt;
  lint k;

  int total_ns = sts.size();

  struct dp_t { lint ntrain = -1LL, people; };
  vector<vector<array<dp_t, 2>>> dp1_memo = vector<vector<array<dp_t, 2>>>(
      total_ns + 1, vector<array<dp_t, 2>>(total_nt + 1));
  vector<vector<array<dp_t, 2>>> dp2_memo = dp1_memo;

  lint solve() { return dp1(total_ns, total_nt, true).ntrain; }

  dp_t dp1(int ns, int nt, bool use_a) {
    dp_t &res = dp1_memo[ns][nt][use_a];
    if (res.ntrain != -1LL) return res;

    if (ns == 0) return res = {0LL, 0LL};
    st_t &last_st = sts[ns - 1];

    if (nt == 0) {
      dp_t sub = dp1(ns - 1, nt, use_a);
      return res = {sub.ntrain, (use_a ? last_st.a : last_st.b) + sub.people};
    }

    res = {LLONG_MAX, -1LL};

    {
      lint last = (use_a ? last_st.a : last_st.b) + (lint)nt * last_st.b;
      if (last <= last_st.c) {
        dp_t sub = dp1(ns - 1, nt, use_a);
        if (sub.ntrain != LLONG_MAX) {
          dp_t cand = {sub.ntrain, sub.people + last};
          if (cand.ntrain < res.ntrain) res = cand;
        }
      }
    }

    for (int t = 0; t < nt; ++t) {
      dp_t upper = dp2(ns, t + 1, use_a);
      if (upper.ntrain == LLONG_MAX) continue;
      dp_t lower = dp1(ns - 1, nt - (t + 1), false);
      if (lower.ntrain == LLONG_MAX) continue;
      lint last = upper.people + (lint)(nt - (t + 1)) * last_st.b;
      lint extra = (max(last - last_st.c, 0LL) + k - 1) / k;
      lint max_extra = (upper.people - last_st.b) / k;
      if (extra > max_extra) continue;
      last -= extra * k;
      dp_t cand = {upper.ntrain + lower.ntrain + extra, lower.people + last};
      if (cand.ntrain < res.ntrain) res = cand;
    }

    return res;
  }

  dp_t dp2(int ns, int nt, bool use_a) {
    dp_t &res = dp2_memo[ns][nt][use_a];
    if (res.ntrain != -1LL) return res;

    assert(ns > 0);
    st_t &st = sts[ns - 1];
    if (nt == 0) return res = {0LL, use_a ? st.a : st.b };

    res = {LLONG_MAX, -1LL};
    for (int t = -1; t < nt - 1; ++t) {
      dp_t upper = dp2(ns, t + 1, use_a);
      if (upper.ntrain == LLONG_MAX) continue;
      dp_t mid = dp1(ns - 1, nt - (t + 1) - 1, use_a && (t == -1));
      if (mid.ntrain == LLONG_MAX) continue;
      lint last = upper.people + (lint)(nt - (t + 1) - 1) * st.b;

      lint extra_0 = (max(last - st.c, 0LL) + k - 1) / k;
      lint max_extra_0 = (t == -1 ? 0LL : (upper.people - st.b) / k);
      if (extra_0 > max_extra_0) continue;
      last -= extra_0 * k;

      lint extra_1 = (mid.people + k - 1) / k;
      lint residual = extra_1 * k - mid.people;
      last -= residual;
      if (last < 0) continue;

      lint extra_2 = (max(last + st.b - st.c, 0LL) + k - 1) / k;
      last -= extra_2 * k;
      if (last < 0) continue;

      last += st.b;
      dp_t cand = {upper.ntrain + mid.ntrain + extra_0 + extra_1 + extra_2,
                   last};
      if (cand.ntrain < res.ntrain) res = cand;
    }
    return res;
  }
};

int main() {
  int ns, nt;
  lint k;
  scanf("%d %d %lld", &ns, &nt, &k);
  vector<st_t> sts;
  for (int i = 0; i < ns; ++i) {
    lint a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    sts.push_back({a, b, c});
  }
  sts.push_back({(k - 1) * nt, 0LL, (k - 1) * nt});
  ns = sts.size();

  solver_t solver{sts, nt, k};
  printf("%lld\n", solver.solve());

  return 0;
}