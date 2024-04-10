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
#line 2 "sol.cpp"

#include <bits/stdc++.h>

const int N = 500'000;

int n, a[N];
std::array<int, 2> result[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  int m = *std::max_element(a, a + n) + 1;
  PrimeGen primes(m);
  memset(result, -1, sizeof(result));
  for (int i = 0; i < n; ++i) {
    int p = primes.min_div(a[i]);
    int q = a[i];
    while (q % p == 0) {
      q /= p;
    }
    if (q != 1) {
      result[i] = {p, q};
    }
  }
  for (int t = 0; t < 2; ++t) {
    for (int i = 0; i < n; ++i) {
      printf("%d%c", result[i][t], " \n"[i + 1 == n]);
    }
  }
}