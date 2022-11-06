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

constexpr int nl = 26*2 + 1, maxn = 10;

struct seq_t {
  int len;
  vector<int> values;
  vector<array<int, nl>> next;
  array<vector<int>, nl> found_at;
  seq_t(const string &s) {
    len = s.size() + 1;

    for (int i = 0; i < len; ++i) {
      int v;
      if (i == 0)
        v = 0;
      else if ('a' <= s[i - 1] && s[i - 1] <= 'z')
        v = 1 + (s[i - 1] - 'a');
      else if ('A' <= s[i - 1] && s[i - 1] <= 'Z')
        v = 1 + 26 + (s[i - 1] - 'A');
      else
        assert(false);

      values.push_back(v);
      found_at[v].push_back(i);
    }

    next.resize(len + 1);
    for (int l = 0; l < nl; ++l)
      next[len][l] = len;
    for (int i = len - 1; i >= 0; --i) {
      next[i] = next[i + 1];
      next[i][values[i]] = i;
    }
  }
};

struct dp_t {
  int many;
  int next_let;
  int next_mask;
};

int n;
vector<seq_t> seqs;
dp_t dp[nl][1<<maxn];

dp_t solve(int value, int mask) {
  dp_t &result = dp[value][mask];
  if (result.many != -1) return result;

  result.many = 1;
  for (int next = 0; next < nl; ++next) {
    int new_mask = 0;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      int cur_pos = seqs[i].found_at[value][(mask&(1<<i)) != 0 ? 1 : 0];
      int new_pos = seqs[i].next[cur_pos + 1][next];
      if (new_pos == seqs[i].len) {
        ok = false;
        break;
      }
      if (new_pos != seqs[i].found_at[next][0])
        new_mask |= 1<<i;
    }
    if (!ok) continue;

    dp_t next_dp = solve(next, new_mask);
    if (next_dp.many + 1 > result.many) {
      result.many = next_dp.many + 1;
      result.next_let = next;
      result.next_mask = new_mask;
    }
  }

  return result;
}

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    scanf("%d", &n);
    seqs.clear();
    for (int i = 0; i < n; ++i) {
      char buffer[128];
      scanf(" %s", buffer);
      seqs.push_back(seq_t(string(buffer)));
    }

    memset(dp, -1, sizeof(dp));

    dp_t res = solve(0, 0);
    printf("%d\n", res.many - 1);

    int let = 0, mask = 0;
    for (int rep = 0; rep < res.many - 1; ++rep) {
      int new_let = dp[let][mask].next_let;
      int new_mask = dp[let][mask].next_mask;

      if (new_let < 1 + 26) printf("%c", 'a' + (new_let - 1));
      else printf("%c", 'A' + (new_let - 1 - 26));

      let = new_let;
      mask = new_mask;
    }
    printf("\n");
  }
  return 0;
}