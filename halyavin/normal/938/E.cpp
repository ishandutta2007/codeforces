#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

const int mod = 1'000'000'007;

int mul32(int x, int y) {
  return int(int64_t(x) * y % mod);
}

int add32(int x, int y) {
  int res = x + y;
  if (res >= mod) res -= mod;
  return res;
}

template<class T>
std::pair<T, T> gcd2(T x, T y) {
    if (x == 0) {
        return {0, 1};
    }
    T s = y / x;
    std::pair<T, T> res = gcd2(y % x, x);
    return {res.second - s * res.first, res.first};
}

template<class T>
T inv(T x, T p) {
    x = x % p;
    if (x < 0) {
        x += p;
    }
    std::pair<T, T> res = gcd2(x, p);
    if (res.first < 0) {
        res.first += p;
    }
    if (res.first >= p) {
        res.first -= p;
    }
    return res.first;
}

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    std::sort(as.begin(), as.end());
    std::vector<int> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = mul32(fact[i - 1], i);
    }
    int sum = 0;
    int prev = 0;
    int maxValue = as.back();
    for (int i = 0; i < n; i++) {
        if (i == 0 || as[i] != as[i - 1]) {
            prev = i;
        }
        if (as[i] != maxValue) {
            sum = add32(sum, mul32(as[i], mul32(fact[n], inv(n - prev, mod))));
        }
    }
    out << sum << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}