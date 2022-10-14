#include <bits/stdc++.h>

const int N = 10;
const int C = 26 * 2;
const int L = C * 2;
const int INVALID = 1 << N;

using Pair = std::pair<int, std::pair<int, int>>;

int n, len[N], s[N][L], next[N][L][C], count[C][N], indices[C][N][2], id0[L],
    next_mask[N][C];
char buffer[L + 1];
Pair dp[C][1 << N];

void dfs(int c, int i, int mask) {
  if (i < n) {
    if (count[c][i] > 0) {
      int j = indices[c][i][0];
      for (int d = 0; d < C; ++d) {
        next_mask[i][d] = next_mask[i - 1][d] | next[i][j][d];
      }
      dfs(c, i + 1, mask);
      if (count[c][i] > 1) {
        int j = indices[c][i][1];
        for (int d = 0; d < C; ++d) {
          next_mask[i][d] = next_mask[i - 1][d] | next[i][j][d];
        }
        dfs(c, i + 1, mask | 1 << i);
      }
    }
  } else {
    dp[c][mask] = {1, {-1, -1}};
    for (int d = 0; d < C; ++d) {
      int nm = next_mask[n - 1][d];
      if (!(nm & INVALID)) {
        dp[c][mask] = std::max(dp[c][mask], {dp[d][nm].first + 1, {d, nm}});
      }
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    memset(count, 0, sizeof(count));
    for (int i = 0; i < n; ++i) {
      scanf("%s", buffer);
      len[i] = strlen(buffer);
      for (int j = 0; j < len[i]; ++j) {
        s[i][j] = islower(buffer[j]) ? buffer[j] - 'a' : buffer[j] - 'A' + 26;
      }
      for (int j = len[i]; j--;) {
        for (int c = 0; c < C; ++c) {
          next[i][j][c] = count[c][i] == 0 ? INVALID : (count[c][i] - 1) << i;
        }
        int c = s[i][j];
        if (i == 0) {
          id0[j] = count[c][i];
        }
        indices[c][i][count[c][i]++] = j;
      }
      // next[i][j][c] = id
    }
    memset(dp, -1, sizeof(dp));
    for (int j = len[0]; j--;) {
      for (int d = 0; d < C; ++d) {
        next_mask[0][d] = next[0][j][d];
      }
      dfs(s[0][j], 1, id0[j]);
    }
    Pair result{0, {-1, -1}};
    for (int c = 0; c < C; ++c) {
      for (int mask = 0; mask < 1 << n; ++mask) {
        result = std::max(result, {dp[c][mask].first, {c, mask}});
      }
    }
    printf("%d\n", result.first);
    int len = 0;
    auto [c, mask] = result.second;
    while (~c) {
      buffer[len++] = c < 26 ? 'a' + c : 'A' + (c - 26);
      std::tie(c, mask) = dp[c][mask].second;
    }
    buffer[len++] = '\0';
    puts(buffer);
  }
}