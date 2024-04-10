#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int MAGIC = 100;
const int MOD = 998'244'353;

int inv(int a) {
  return a == 1 ? 1 : 1LL * (MOD - MOD / a) * inv(MOD % a) % MOD;
}

int m, fact[MAGIC], inv_fact[MAGIC];
std::vector<long long> primes;

std::vector<int> count(long long n) {
  std::vector<int> result(m);
  for (int i = 0; i < m; ++i) {
    while (n % primes[i] == 0) {
      n /= primes[i];
      result[i]++;
    }
  }
  return result;
}

int multinom(const std::vector<int> &cs) {
  int s = std::accumulate(cs.begin(), cs.end(), 0);
  int result = fact[s];
  for (int c : cs) {
    result = 1LL * result * inv_fact[c] % MOD;
  }
  return result;
}

int main() {
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i < MAGIC; ++i) {
    fact[i] = 1LL * i * fact[i - 1] % MOD;
    inv_fact[i] = inv(fact[i]);
  }
  long long d;
  scanf("%lld", &d);
  for (int p = 2; 1LL * p * p <= d; ++p) {
    if (d % p == 0) {
      while (d % p == 0) {
        d /= p;
      }
      primes.push_back(p);
    }
  }
  if (d > 1) {
    primes.push_back(d);
  }
  m = primes.size();
  int q;
  scanf("%d", &q);
  std::vector<int> as(m), bs(m);
  while (q--) {
    long long u, v;
    scanf("%lld%lld", &u, &v);
    auto uc = count(u);
    auto vc = count(v);
    for (int i = 0; i < m; ++i) {
      as[i] = bs[i] = 0;
      if (uc[i] < vc[i]) {
        bs[i] = vc[i] - uc[i];
      } else {
        as[i] = uc[i] - vc[i];
      }
    }
    printf("%d\n", static_cast<int>(1LL * multinom(as) * multinom(bs) % MOD));
  }
}