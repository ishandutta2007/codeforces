// #include "debug.h"

#include <bits/stdc++.h>

bool is_prime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int power[9];
std::vector<int> primes[9];

int main() {
  for (int i = 0, start = 1; i < 9; i++, start *= 10) {
    power[i] = start;
    int p = start;
    while (static_cast<int>(primes[i].size()) < 2) {
      if (is_prime(p)) {
        primes[i].push_back(p);
      }
      p++;
    }
    // std::cout << primes[i] << std::endl;
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d %d\n", primes[a - c][0] * power[c - 1],
           primes[b - c][1] * power[c - 1]);
  }
}