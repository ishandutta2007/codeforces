#include <bits/stdc++.h>

bool is_prime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

const int D = 10000;

std::vector<int> primes{2};

int next_prime() {
  int p = primes.back() + 1;
  while (!is_prime(p)) {
    p++;
  }
  primes.push_back(p);
  return p;
}
int main() {
  {
    while (next_prime() < 1 + D)
      ;
    int p = primes.back();
    while (next_prime() < p + D)
      ;
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    int d;
    scanf("%d", &d);
    int p = *std::lower_bound(primes.begin(), primes.end(), 1 + d);
    long long result = 1LL * p * p * p;
    int q = *std::lower_bound(primes.begin(), primes.end(), p + d);
    result = std::min(result, 1LL * p * q);
    std::cout << result << "\n";
  }
}