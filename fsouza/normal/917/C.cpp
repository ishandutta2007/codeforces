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

vector<vector<lint>> combine(const vector<vector<lint>> &a,
                             const vector<vector<lint>> &b) {
  const int n = a.size();
  vector<vector<lint>> res(n, vector<lint>(n, LLONG_MAX));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < n; ++k)
        if (a[i][k] != LLONG_MAX && b[k][j] != LLONG_MAX)
          res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
  return res;
}

int main() {
  int np, max_jump_len, field_len, nstone;
  scanf("%d %d %d %d", &np, &max_jump_len, &field_len, &nstone);
  vector<int> jump_cost(max_jump_len + 1);
  for (int len = 1; len <= max_jump_len; ++len)
    scanf("%d", &jump_cost[len]);
  struct stone_t {
    int pos, cost;
  };
  vector<stone_t> stones;
  for (int i = 0; i < nstone; ++i) {
    int pos, cost;
    scanf("%d %d", &pos, &cost), --pos;
    stones.push_back({pos, cost});
  }
  sort(stones.begin(), stones.end(),
       [](const stone_t &a, const stone_t &b) { return a.pos < b.pos; });
  const int block_size = max_jump_len;
  vector<int> id2mask, mask2id(1<<block_size, -1);
  for (int mask = 0; mask < (1<<block_size); ++mask)
    if (__builtin_popcount(mask) == np) {
      mask2id[mask] = id2mask.size();
      id2mask.push_back(mask);
    }
  const int nmask = id2mask.size();
  vector<vector<lint>> adj(nmask, vector<lint>(nmask, LLONG_MAX));
  for (int mask_id_a = 0; mask_id_a < nmask; ++mask_id_a) {
    const int mask_a = id2mask[mask_id_a];
    if (mask_a & (1<<0)) {
      for (int jump = 1; jump <= max_jump_len; ++jump)
        if (!(mask_a & (1<<jump))) {
          int mask_b = (mask_a | (1<<jump)) >> 1;
          int mask_id_b = mask2id[mask_b];
          adj[mask_id_a][mask_id_b] = jump_cost[jump];
        }
    } else {
      int mask_b = mask_a >> 1;
      int mask_id_b = mask2id[mask_b];
      adj[mask_id_a][mask_id_b] = 0LL;
    }
  }
  vector<vector<vector<lint>>> adj2i;
  adj2i.push_back(adj);
  while ((1<<adj2i.size()) <= field_len)
    adj2i.push_back(combine(adj2i.back(), adj2i.back()));

  vector<lint> dp(nmask, LLONG_MAX);
  dp[mask2id[(1<<np) - 1]] = 0LL;

  int stone_id_from_base = nstone;
  for (int base = field_len - np - 1; base >= 0; --base) {
    vector<lint> dp_next(nmask, LLONG_MAX);
    swap(dp, dp_next);

    while (stone_id_from_base - 1 >= 0 &&
           stones[stone_id_from_base - 1].pos >= base)
      --stone_id_from_base;
    if (stone_id_from_base != nstone &&
        stones[stone_id_from_base].pos <= base + max_jump_len) {
      for (int mask_id_a = 0; mask_id_a < nmask; ++mask_id_a) {
        const int mask_a = id2mask[mask_id_a];
        if (mask_a & (1<<0)) {
          int stone_id2 = stone_id_from_base;
          for (int jump = 1; jump <= max_jump_len; ++jump)
            if (!(mask_a & (1<<jump))) {
              const int mask_b = (mask_a | (1<<jump)) >> 1;
              const int mask_id_b = mask2id[mask_b];
              lint cand_cost = jump_cost[jump];
              if (dp_next[mask_id_b] == LLONG_MAX) continue;
              cand_cost += dp_next[mask_id_b];
              while (stone_id2 != nstone &&
                     stones[stone_id2].pos < base + jump)
                ++stone_id2;
              if (stone_id2 != nstone && stones[stone_id2].pos == base + jump)
                cand_cost += stones[stone_id2].cost;
              dp[mask_id_a] = min(dp[mask_id_a], cand_cost);
            }
        } else {
          dp[mask_id_a] = dp_next[mask2id[mask_a >> 1]];
        }
      }
    } else {
      int new_base;
      if (stone_id_from_base - 1 >= 0)
        new_base = stones[stone_id_from_base - 1].pos;
      else
        new_base = 0;
      const int dist = base - new_base + 1;
      vector<vector<lint>> adjpdist(nmask, vector<lint>(nmask, LLONG_MAX));
      for (int i = 0; i < nmask; ++i) adjpdist[i][i] = 0LL;
      for (int l = 0; (1<<l) <= dist; ++l)
        if (dist & (1<<l))
          adjpdist = combine(adjpdist, adj2i[l]);
      for (int mask_id_a = 0; mask_id_a < nmask; ++mask_id_a)
        for (int mask_id_b = 0; mask_id_b < nmask; ++mask_id_b)
          if (adjpdist[mask_id_a][mask_id_b] != LLONG_MAX &&
              dp_next[mask_id_b] != LLONG_MAX) {
            dp[mask_id_a] =
              min(dp[mask_id_a],
                  adjpdist[mask_id_a][mask_id_b] + dp_next[mask_id_b]);
          }
      base = new_base;
    }
  }
  printf("%lld\n", dp[mask2id[(1<<np) - 1]]);
  return 0;
}