#include <bits/stdc++.h>

/*sage
F = GF(998244353)

def solve1(n, m):
    result = F(0)
    binom = F(1)
    for i in range(1, n + 1):
        binom = binom * (n - i + 1) / i
        entry = binom / (1 - (F(m) / (m + i)))
        if i % 2 == 1:
            result += entry
        else:
            result -= entry
    return result * (F(n) / (m + 1) + 1)

def solve2(n, m):
    result = F(1)
    for i in range(1, n + 1):
        # dp[i] = m / (m + i) (dp[i] + 1) + (i / (m + i)) dp[i - 1]
        # <=> (m + i) dp[i] = m * (dp[i] + 1) + i * dp[i - 1]
        # <=> i * dp[i] = m + i * dp[i - 1]
        # <=> dp[i] = m / i + dp[i - 1]
        result += F(m) / i
    return result * (F(n) / (m + 1) + 1)

assert(solve(2, 1) == 5)
assert(solve(3, 2) == 332748127)
assert(solve(14, 9) == 969862773)
*/

static const int MOD = 998244353;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> inverse(std::max(n, m + 1) + 1);
  inverse[1] = 1;
  for (int i = 2; i <= std::max(n, m + 1); ++i) {
    inverse[i] = 1LL * (MOD - MOD / i) * inverse[MOD % i] % MOD;
  }
  int result = 0;
  for (int i = 1; i <= n; ++i) {
    result += inverse[i];
    if (result >= MOD) {
      result -= MOD;
    }
  }
  printf("%d\n", static_cast<int>((1LL * result * m % MOD + 1) *
                                  (1LL * n * inverse[m + 1] % MOD + 1) % MOD));
}