#include <bits/stdc++.h>

namespace {
using u64 = uint64_t;

static const int MOD = 998244353;

struct LargeSolver {
  LargeSolver(int r_, int m_, std::vector<u64> &&b_)
      : r{r_}, m{m_}, b{std::move(b_)}, count(m + 1), result(m + 1) {
    dfs_large(0, 0, 0);
    int power_of_two = 1;
    for (int i = 0; i < m - r; ++i) {
      power_of_two = ((MOD + 1LL) / 2) * power_of_two % MOD;
    }
    for (int d = 0; d <= m; ++d) {
      std::vector<int> coef(m + 1);
      coef[0] = power_of_two;
      for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j > 0; --j) {
          coef[j] += (i < d ? MOD - 1LL : 1LL) * coef[j - 1] % MOD;
          if (coef[j] >= MOD) {
            coef[j] -= MOD;
          }
        }
      }
      for (int c = 0; c <= m; ++c) {
        result[c] += 1LL * coef[c] * count[d] % MOD;
        if (result[c] >= MOD) {
          result[c] -= MOD;
        }
      }
    }
  }

  void dfs_large(int i, int c, u64 x) {
    if (i < m - r) {
      dfs_large(i + 1, c, x);
      dfs_large(i + 1, c + 1, x ^ b[i]);
    } else {
      count[c + __builtin_popcountll(x)]++;
    }
  }

  int r, m;
  std::vector<u64> b;
  std::vector<int> count, result;
};

struct Solver {
  Solver(int n_, int m_, std::vector<u64> &&a_)
      : n{n_}, m{m_}, rank{0}, a{std::move(a_)}, result(m + 1) {
    std::vector<int> notpivot_bits;
    for (int j = 0; j < m; ++j) {
      int pivot = rank;
      while (pivot < n && (~a[pivot] >> j & 1)) {
        pivot++;
      }
      if (pivot < n) {
        std::swap(a[rank], a[pivot]);
        for (int i = 0; i < n; ++i) {
          if (i != rank && a[i] >> j & 1) {
            a[i] ^= a[rank];
          }
        }
        rank++;
      } else {
        notpivot_bits.push_back(j);
      }
    }
    if (rank <= m - rank) {
      dfs_small(0, 0);
    } else {
      std::vector<u64> basis;
      basis.reserve(m - rank);
      for (int j : notpivot_bits) {
        u64 b = 0;
        for (int i = 0; i < rank; ++i) {
          b |= (a[i] >> j & 1) << i;
        }
        basis.push_back(b);
      }
      LargeSolver solver{rank, m, std::move(basis)};
      std::copy(solver.result.begin(), solver.result.end(), result.begin());
    }
    int power_of_two = 1;
    for (int i = rank; i < n; ++i) {
      power_of_two += power_of_two;
      if (power_of_two >= MOD) {
        power_of_two -= MOD;
      }
    }
    for (int i = 0; i <= m; ++i) {
      result[i] = 1LL * power_of_two * result[i] % MOD;
    }
  }

  void dfs_small(int i, u64 x) {
    if (i < rank) {
      dfs_small(i + 1, x);
      dfs_small(i + 1, x ^ a[i]);
    } else {
      result[__builtin_popcountll(x)]++;
    }
  }

  int n, m, rank;
  std::vector<u64> a;
  std::vector<int> result;
};

} // namespace

int main() {
  std::ios::sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<u64> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  Solver solver{n, m, std::move(a)};
  for (int i = 0; i <= m; ++i) {
    printf("%d%c", solver.result[i], " \n"[i == m]);
  }
}