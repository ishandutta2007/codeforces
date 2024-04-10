#line 1 "sol.cpp"
#include <bits/stdc++.h>

template <typename T> void update(T &x, T a) { x = std::min(x, a); }

const int N = 15;
const int MAGIC = 19;

int inv2[MAGIC], n, a[N], sum[1 << N];
std::pair<int, int> dp[N + 1][1 << N][N];

int lowbit(int mask) { return inv2[(mask & -mask) % MAGIC]; }

int main() {
  for (int i = 0, two = 1; i < N; ++i) {
    inv2[two] = i;
    two = two * 2 % MAGIC;
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    sum[0] = 0;
    for (int mask = 1; mask < 1 << n; ++mask) {
      int i = lowbit(mask);
      sum[mask] = sum[mask ^ (1 << i)] + a[i];
    }
    for (int mask = 1; mask < 1 << n; ++mask) {
      int low = lowbit(mask);
      std::fill(dp[1][mask], dp[1][mask] + n, std::make_pair(INT_MAX, -1));
      dp[1][mask][low] = {sum[mask], mask};
    }
    for (int k = 1; k < n; ++k) {
      for (int mask = 1; mask < 1 << n; ++mask) {
        std::fill(dp[k + 1][mask], dp[k + 1][mask] + n,
                  std::make_pair(INT_MAX, -1));
      }
      for (int mask = 1; mask + 1 < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
          if (dp[k][mask][i].first < INT_MAX) {
            int comp = ((1 << n) - 1) ^ mask;
            assert(comp > 0);
            for (int sub = comp; sub >> i; sub = (sub - 1) & comp) {
              if (dp[k][mask][i].first < sum[sub]) {
                int nxt = lowbit(sub & ~((1 << i) - 1));
                update(dp[k + 1][mask | sub][nxt], {sum[sub], i << n | sub});
              }
            }
          }
        }
      }
    }
    int sz = n + 1;
    int idx = n;
    while (idx == n) {
      sz--;
      idx = 0;
      while (idx < n && dp[sz][(1 << n) - 1][idx].first == INT_MAX) {
        idx++;
      }
    }
    printf("%d\n", n - sz);
    std::vector<int> index(n);
    std::iota(index.begin(), index.end(), 1);
    auto merge = [&](int i, int j) {
      printf("%d %d\n", index[i], index[j]);
      // 1 2 3 4 5 6
      //   ^ 2 3 4 5
      for (int k = i; k < n; ++k) {
        index[k]--;
      }
    };
    for (int mask = (1 << n) - 1; sz > 0; sz--) {
      int from = dp[sz][mask][idx].second;
      int sub = from & ((1 << n) - 1);
      for (int i = 0; i < n; ++i) {
        if (i != idx && (sub >> i & 1)) {
          merge(i, idx);
        }
      }
      mask ^= sub;
      idx = from >> n;
    }
  }
}