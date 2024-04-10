#include <bits/stdc++.h>

const int N = 300'000;
const int MOD = 998'244'353;

int len, m, indeg[N], count[N + 1], dp[N + 1];
std::set<int> out[N];

int find_chain(int u) {
  int result = 1;
  while (out[u].size()) {
    if (out[u].size() > 1) {
      return -1;
    }
    int v = *out[u].begin();
    if (indeg[v] > 1) {
      return -1;
    }
    u = v;
    result++;
  }
  return result;
}

int main() {
  {
    int n;
    scanf("%d%d%d", &n, &len, &m);
    for (int i = 0; i < n; ++i) {
      int c;
      scanf("%d", &c);
      int last;
      for (int j = 0, a; j < c; ++j) {
        scanf("%d", &a);
        a--;
        if (j) {
          if (out[last].emplace(a).second) {
            indeg[a]++;
          }
        }
        last = a;
      }
    }
  }
  for (int c = 0; c < m; ++c) {
    if (indeg[c] == 0) {
      int l = find_chain(c);
      if (~l) {
        count[l]++;
      }
    }
  }
  std::vector<std::pair<int, int>> non_zeros;
  for (int i = 1; i <= len; ++i) {
    if (count[i] > 0) {
      non_zeros.emplace_back(i, count[i]);
    }
  }
  dp[0] = 1;
  for (int i = 1; i <= len; ++i) {
    for (auto [l, c] : non_zeros) {
      if (l > i) {
        break;
      }
      dp[i] += 1LL * dp[i - l] * c % MOD;
      if (dp[i] >= MOD) {
        dp[i] -= MOD;
      }
    }
  }
  printf("%d\n", dp[len]);
}