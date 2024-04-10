#include <bits/stdc++.h>

const int N = 18;

int n, parity[1 << N];
bool graph[N][N];
uint64_t path[1 << N][N], psum[N][1 << N], ssum[N + 1][1 << N], dp[1 << N];
std::vector<std::pair<std::vector<int>, uint64_t>> partitions;

void dfs(int sum, int bound, int depth, std::vector<int> &&partition) {
  if (sum) {
    for (int size = std::min(sum, bound); size; --size) {
      partition.push_back(size);
      for (int mask = 0; mask < 1 << n; ++mask) {
        ssum[depth + 1][mask] = ssum[depth][mask] * psum[size - 1][mask];
      }
      dfs(sum - size, size, depth + 1, std::move(partition));
      partition.pop_back();
    }
  } else {
    uint64_t result = 0;
    for (int mask = 0; mask < 1 << n; ++mask) {
      if (parity[mask]) {
        result -= ssum[depth][mask];
      } else {
        result += ssum[depth][mask];
      }
    }
    partitions.emplace_back(partition, result);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    static char buffer[N + 1];
    scanf("%s", buffer);
    for (int j = 0; j < n; ++j) {
      graph[i][j] = buffer[j] == '1';
    }
  }
  for (int i = 0; i < n; ++i) {
    path[1 << i][i] = 1;
  }
  for (int mask = 1; mask < 1 << n; ++mask) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (graph[i][j] && (~mask >> j & 1)) {
          path[mask | 1 << j][j] += path[mask][i];
        }
      }
    }
  }
  for (int mask = 1; mask < 1 << n; ++mask) {
    int length = __builtin_popcount(mask) - 1;
    for (int i = 0; i < n; ++i) {
      psum[length][mask] += path[mask][i];
    }
  }
  for (int length = 0; length < n; ++length) {
    for (int i = 0; i < n; ++i) {
      for (int mask = 0; mask < 1 << n; ++mask) {
        if (mask >> i & 1) {
          psum[length][mask] += psum[length][mask ^ (1 << i)];
        }
      }
    }
  }
  std::fill(ssum[0], ssum[0] + (1 << n), 1);
  for (int mask = 0; mask < 1 << n; ++mask) {
    parity[mask] = n - __builtin_popcount(mask) & 1;
  }
  dfs(n, n, 0, {});
  std::sort(partitions.begin(), partitions.end());
  for (int mask = 0; mask < 1 << n - 1; ++mask) {
    std::vector<int> partition;
    for (int i = 0, size = 1; i < n; ++i) {
      if (~mask >> i & 1) {
        partition.push_back(size);
        size = 1;
      } else {
        size++;
      }
    }
    std::sort(partition.begin(), partition.end(), std::greater<int>());
    dp[mask] = std::lower_bound(partitions.begin(), partitions.end(),
                                std::make_pair(partition, static_cast<uint64_t>(0)))
                   ->second;
  }
  for (int i = 0; i < n - 1; ++i) {
    for (int mask = 1 << n - 1; mask--;) {
      if (~mask >> i & 1) {
        dp[mask] -= dp[mask ^ (1 << i)];
      }
    }
  }
  for (int mask = 0; mask < 1 << n - 1; ++mask) {
    printf("%llu%c", static_cast<unsigned long long>(dp[mask]), " \n"[mask + 1 == (1 << n - 1)]);
  }
}