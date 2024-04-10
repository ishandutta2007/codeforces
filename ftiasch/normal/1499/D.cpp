#include <bits/stdc++.h>

const int N = 20'000'000;

int ways[N + 1];

int count(int c, int rhs) { return rhs % c == 0 ? ways[rhs / c] : 0; }

int main() {
  std::vector<int> primes;
  ways[1] = 1;
  for (int d = 2; d <= N; ++d) {
    if (!ways[d]) {
      ways[d] = 2;
      primes.push_back(d);
    }
    for (int p : primes) {
      if (d * p > N) {
        break;
      }
      ways[p * d] = ways[d] * 2;
      if (d % p == 0) {
        ways[p * d] = ways[d];
        break;
      }
    }
  }
  // c * lcm - d * gcd = x
  // lcm = a * b / gcd
  // (c * a / gcd * b / gcd - d) = x / gcd
  // c * (a / gcd) * (b / gcd) = x / gcd + d
  int T;
  scanf("%d", &T);
  while (T--) {
    int c, d, x;
    scanf("%d%d%d", &c, &d, &x);
    int result = 0;
    for (int i = 1; i * i <= x; ++i) {
      if (x % i == 0) {
        result += count(c, x / i + d);
        if (i * i != x) {
          result += count(c, i + d);
        }
      }
    }
    printf("%d\n", result);
  }
}