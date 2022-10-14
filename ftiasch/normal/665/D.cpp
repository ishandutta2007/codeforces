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

  bool is_prime(int n) const { return min_div(n) == n; }

private:
  std::vector<int> min_div_;
};
#line 2 "sol.cpp"

#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int ones = std::count(a.begin(), a.end(), 1);
  std::sort(a.begin(), a.end());
  PrimeGen primes(2 * a.back() + 1);
  int plus = 0;
  for (int i = 0; i < n && !plus; ++i) {
    if (a[i] > 1 && primes.is_prime(1 + a[i])) {
      plus = a[i];
    }
  }
  std::pair<int, int> found{0, 0};
  for (int i = 0; i < n && !found.first; ++i) {
    for (int j = i + 1; j < n && !found.first; ++j) {
      if (primes.is_prime(a[i] + a[j])) {
        found = {a[i], a[j]};
      }
    }
  }
  if (ones + !!plus > 2) {
    printf("%d\n", ones + !!plus);
    for (int i = 0; i < ones; ++i) {
      printf("1 ");
    }
    if (plus) {
      printf("%d\n", plus);
    }
  } else if (found.first) {
    printf("2\n%d %d\n", found.first, found.second);
  } else {
    printf("1\n%d\n", a[0]);
  }
}