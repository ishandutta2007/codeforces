#line 1 "/home/ftiasch/Documents/shoka/sieve.h"
#include <vector>

struct PrimeGen : public std::vector<int> {
  PrimeGen(int m) : std::vector<int>(), min_div_(m, -1) {
    for (int d = 2; d < m; ++d) {
      if (min_div_[d] == -1) {
        min_div_[d] = d;
        push_back(d);
      }
      for (int p : *this) {
        if (d * p >= m) {
          break;
        }
        min_div_[p * d] = p;
        if (d % p == 0) {
          break;
        }
      }
    }
  }

  int min_div(int n) const { return min_div_[n]; }

private:
  std::vector<int> min_div_;
};
#line 2 "E_You.cpp"

#include <bits/stdc++.h>

namespace {

const int N = 100000;
const int MOD = 998244353;

PrimeGen primes(N);

bool ok[N + 1];
std::vector<int> tree[N];

std::pair<bool, int> dfs(int d, int p, int u) {
  int indeg = 0;
  int gcd = 0;
  for (int v : tree[u]) {
    if (v != p) {
      auto [vup, vgcd] = dfs(d, u, v);
      indeg += vup;
      gcd = std::__gcd(gcd, vgcd);
    }
  }
  if (indeg % d == 0) {
    return {true, std::__gcd(gcd, indeg)};
  }
  if ((indeg + 1) % d == 0) {
    return {false, std::__gcd(gcd, indeg + 1)};
  }
  return {true, 1};
}

} // namespace

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      tree[i].clear();
    }
    for (int i = 0, a, b; i < n - 1; ++i) {
      scanf("%d%d", &a, &b);
      a--, b--;
      tree[a].push_back(b);
      tree[b].push_back(a);
    }
    memset(ok, 0, sizeof(*ok) * (n + 1));
    int result1 = 1;
    for (int i = 0; i < n - 1; ++i) {
      result1 += result1;
      if (result1 >= MOD) {
        result1 -= MOD;
      }
    }
    for (int x = n - 1; x > 1;) {
      int p = primes.min_div(x);
      auto [up, gcd] = dfs(p, -1, 0);
      if (up && gcd > 1) {
        if (!ok[gcd]) {
          result1 = result1 ? result1 - 1 : MOD - 1;
        }
        ok[gcd] = true;
      }
      while (x % p == 0) {
        x /= p;
      }
    }
    printf("%d ", result1);
    for (int i = 2; i <= n; ++i) {
      printf("%d%c", ok[i], " \n"[i == n]);
    }
  }
}