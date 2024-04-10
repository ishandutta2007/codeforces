#include <bits/stdc++.h>
#include <limits>

namespace montgomery {

using u64 = uint64_t;
using u32 = uint32_t;

struct u128 {
  static u128 multiply(u64 x, u64 y) {
    // u64 high, low;
    // __asm__("mulq %3\n\t" : "=d"(high), "=a"(low) : "%a"(x), "rm"(y) : "cc");
    // return {high, low};
    uint64_t a = x & UINT32_MAX, b = x >> 32u, c = y & UINT32_MAX, d = y >> 32u,
             ac = a * c, bc = b * c, ad = a * d, bd = b * d,
             z = (bc & UINT32_MAX) + (ad & UINT32_MAX) + (ac >> 32u);
    return {bd + (bc >> 32u) + (ad >> 32u) + (z >> 32u),
            (z & UINT32_MAX) << 32u | (ac & UINT32_MAX)};
  }

  u64 high, low;
};

template <u64 MOD> struct MontgomeryT {
  static_assert(MOD <= std::numeric_limits<u64>::max() >> 1, "");

  static u64 from_monty(u64 x) { return reduce(u128{0, x}); }

  static u64 multiply(u64 x, u64 y) { return reduce(u128::multiply(x, y)); }

  static u64 to_monty(u64 x) { return multiply(x, R2); }

  static u64 inverse(u64 a) {
    u64 result = R;
    u64 n = MOD - 2;
    while (n) {
      if (n & 1) {
        result = multiply(result, a);
      }
      a = multiply(a, a);
      n >>= 1;
    }
    return result;
  }

private:
  static constexpr u64 modinv() {
    u64 result = 1;
    for (int i = 0; i < 6; ++i) {
      result *= 2 - MOD * result;
    }
    return -result;
  }

  static constexpr u64 rpower(int n) {
    u64 result = 1;
    for (int i = 0; i < n; ++i) {
      result += result;
      if (result >= MOD) {
        result -= MOD;
      }
    }
    return result;
  }

  static u64 reduce(u128 x) {
    u128 y = u128::multiply(u128::multiply(x.low, INV).low, MOD);
    u64 result = x.high + y.high + (x.low > ~y.low);
    if (result >= MOD) {
      result -= MOD;
    }
    return result;
  }

  static const u64 INV = modinv();
  static const u64 R = rpower(64);
  static const u64 R2 = rpower(128);

  u64 x;
};

} // namespace montgomery

using namespace montgomery;

const int N = 58;

const u64 MOD = 2000000000000000057;
using M = MontgomeryT<MOD>;

const u64 ONE = M::to_monty(1);
const u64 MINUS_ONE = M::to_monty(MOD - 1);

void add(u64 &x, u64 a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int n, q, v, b[N], r[N];
char s[N];
u64 mat[N][N << 1], c[N], x[N], y[N], balance[N];
bool visited[N];
std::vector<int> graph[N];

bool subtract(u64 &x, u64 a) {
  if (x < a) {
    return false;
  }
  x -= a;
  return true;
}

void dfs(int u) {
  if (!visited[u]) {
    visited[u] = true;
    for (int v : graph[u]) {
      dfs(v);
    }
  }
}

bool check() {
  for (int i = 0; i < n; ++i) {
    balance[i] = x[i] + y[i] + (i == v);
    if (!i) {
      if (!balance[i]) {
        return false;
      }
      balance[i]--;
    }
  }
  u64 to_n = 0;
  for (int i = 0; i < n; ++i) {
    if (b[i] < n) {
      if (!subtract(balance[b[i]], x[i])) {
        return false;
      }
    } else {
      to_n += x[i];
    }
    if (r[i] < n) {
      if (!subtract(balance[r[i]], y[i])) {
        return false;
      }
    } else {
      to_n += y[i];
    }
    if (to_n > 1) {
      return false;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (balance[i]) {
      return false;
    }
    graph[i].clear();
  }
  graph[n].clear();
  for (int i = 0; i < n; ++i) {
    graph[s[i] == 'B' ? b[i] : r[i]].push_back(i);
  }
  memset(visited, 0, sizeof(*visited) * n);
  dfs(v);
  for (int i = 0; i < n; ++i) {
    if (y[i] && !visited[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  std::cin >> n;
  n--;
  for (int i = 0; i < n; ++i) {
    std::cin >> b[i] >> r[i];
    mat[i][n + i] = ONE;
    add(mat[i][i], ONE);
    add(mat[i][i], ONE);
    add(mat[--b[i]][i], MINUS_ONE);
    add(mat[--r[i]][i], MINUS_ONE);
  }
  for (int j = 0; j < n; ++j) {
    int pivot = j;
    while (!mat[pivot][j]) {
      pivot++;
    }
    for (int k = 0; k < n << 1; ++k) {
      std::swap(mat[j][k], mat[pivot][k]);
    }
    {
      u64 t = M::inverse(mat[j][j]);
      for (int k = 0; k < n << 1; ++k) {
        mat[j][k] = M::multiply(mat[j][k], t);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (i != j && mat[i][j]) {
        u64 t = mat[i][j];
        for (int k = 0; k < n << 1; ++k) {
          add(mat[i][k], MOD - M::multiply(mat[j][k], t));
        }
      }
    }
  }
  std::cin >> q;
  while (q--) {
    std::cin >> v >> s;
    v--;
    memset(c, 0, sizeof(*c) * n);
    c[0] = ONE;
    add(c[v], MINUS_ONE);
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'R') {
        add(c[i], MINUS_ONE);
        add(c[r[i]], ONE);
      }
    }
    u64 result = 0;
    for (int i = 0; i < n; ++i) {
      x[i] = 0;
      for (int j = 0; j < n; ++j) {
        add(x[i], M::multiply(mat[i][n + j], c[j]));
      }
      x[i] = y[i] = M::from_monty(x[i]);
      if (s[i] == 'R') {
        y[i]++;
      }
      result += x[i] + y[i];
    }
    std::cout << (check() ? static_cast<std::int64_t>(result) : -1) << "\n";
  }
}