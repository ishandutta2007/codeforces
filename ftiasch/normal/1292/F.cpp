#include <bits/stdc++.h>

const int N = 60;
const int M = 11;
const int MOD = 1e9 + 7;

int binom[N + 1][N + 1], n, a[N], parent[N], inDegree[N], v0[N], v1[N], msk1[N],
    dp[N + 1][1 << M];

int findRoot(int u) {
  if (parent[u] != u) {
    parent[u] = findRoot(parent[u]);
  }
  return parent[u];
}

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int solve(int n0, int n1) {
  assert(n0 <= M);
  for (int j = 0; j < n1; ++ j) {
    msk1[j] = 0;
  }
  for (int i = 0; i < n0; ++i) {
    for (int j = 0; j < n1; ++j) {
      if (v1[j] % v0[i] == 0) {
        msk1[j] |= 1 << i;
      }
    }
  }
  for (int i = 1; i <= n1; ++i) {
    for (int msk = 0; msk < 1 << n0; ++msk) {
      dp[i][msk] = 0;
    }
  }
  for (int i = 0; i < n1; ++i) {
    add(dp[1][msk1[i]], 1);
  }
  for (int i = 1; i < n1; ++i) {
    for (int msk = 0; msk < 1 << n0; ++msk) {
      if (dp[i][msk]) {
        int cnt = 0;
        for (int j = 0; j < n1; ++j) {
          if ((msk1[j] & msk) == msk1[j]) {
            cnt++;
          } else if (msk1[j] & msk) {
            add(dp[i + 1][msk | msk1[j]], dp[i][msk]);
          }
        }
        if (i < cnt) {
          add(dp[i + 1][msk], 1LL * (cnt - i) * dp[i][msk] % MOD);
        }
      }
    }
  }
  return dp[n1][(1 << n0) - 1];
}

int main() {
#ifdef LOCAL_JUDGE
  freopen("F.in", "r", stdin);
#endif
  for (int i = 0; i <= N; ++i) {
    binom[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
    }
  }
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      parent[i] = i;
      inDegree[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i != j && a[j] % a[i] == 0) { // i -> j
          if (findRoot(i) != findRoot(j)) {
            parent[findRoot(i)] = findRoot(j);
          }
          inDegree[j]++;
        }
      }
    }
    int result = 1, size = 0;
    for (int group = 0; group < n; ++group) {
      if (parent[group] == group) {
        int n0 = 0, n1 = 0;
        for (int i = 0; i < n; ++i) {
          if (findRoot(i) == group) {
            if (inDegree[i]) {
              v1[n1++] = a[i];
            } else {
              v0[n0++] = a[i];
            }
          }
        }
        if (n1) {
          size += n1 - 1;
          result =
              1LL * result * binom[size][n1 - 1] % MOD * solve(n0, n1) % MOD;
        }
      }
    }
    printf("%d\n", result);
  }
}