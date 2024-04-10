#include <bits/stdc++.h>

constexpr int sqrt(int n) {
  int r = 0;
  while (r * r < n) {
    r++;
  }
  return r;
}

const int N = 100002;
const int B = sqrt(N);
const int MOD = 998244353;

void update(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int n, limit, blocks, bdelta[B], value[N], sum[B], sufsum[B][N], dp[N],
    last[N][2];

template <int d> void add(int l, int r) {
  for (int bid = l / blocks, bbegin = bid * blocks; bid <= (r - 1) / blocks;
       ++bid, bbegin += blocks) {
    int bend = bbegin + blocks;
    if (l <= bbegin && bend <= r) {
      bdelta[bid] += d;
    } else {
      for (int i = std::max(l, bbegin); i < std::min(r, bend); ++i) {
        if (d == -1) {
          update(sufsum[bid][value[i]--], MOD - dp[i]);
        } else {
          update(sufsum[bid][++value[i]], dp[i]);
        }
      }
    }
  }
}

int query() {
  int result = 0;
  for (int bid = 0; bid < blocks; ++bid) {
    update(result, sum[bid]);
    int index = limit + 1 - bdelta[bid];
    update(result, MOD - sufsum[bid][std::min(std::max(index, 0), n + 1)]);
  }
  return result;
}

int main() {
  scanf("%d%d", &n, &limit);
  blocks = sqrt(n);
  dp[0] = 1;
  for (int i = 1, a; i <= n; ++i) {
    scanf("%d", &a);
    int bid = (i - 1) / blocks;
    assert(bdelta[bid] == 0);
    update(sum[bid], dp[i - 1]);
    update(sufsum[bid][0], dp[i - 1]);
    if (last[a][1]) {
      add<-1>(last[a][0], last[a][1]);
    }
    add<1>(last[a][1], i);
    dp[i] = query();
    // printf("dp[%d]=%d\n", i, dp[i]);
    last[a][0] = last[a][1];
    last[a][1] = i;
  }
  printf("%d\n", dp[n]);
}