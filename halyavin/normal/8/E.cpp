#include <iostream>
#include <cstdint>
#include <algorithm>

int64_t fsym(int n) {
  if (n == 0) return 1LL;
  if (n % 2 == 0) return (1LL << (n - 1)) + (1LL << (n / 2 - 1));
  return (1LL << (n - 1)) + (1LL << (n / 2));
}

int64_t fanti(int n) {
  if (n == 0) return 1LL;
  if (n % 2 == 0) return (1LL << (n - 1)) + (1LL << (n / 2 - 1));
  return 1LL << (n - 1);
}

int64_t calc_variants1(int64_t a, int len, int n) {
  int64_t small = (2 * ((1LL << len) - a - 1)) << (n - 2 * len - 2);
  int64_t equal = fsym(n - 2 * len - 2) + fanti(n - 2 * len - 2);
  return small + equal;
}

int64_t inverse(int64_t x, int n) {
  int64_t res = 0;
  for (int i = 0; i < n; i++) {
    res = 2 * res + (x & 1);
    x >>= 1;
  }
  return res;
}

int64_t flip(int64_t x, int n) {
  return x ^ ((1LL << n) - 1);
}

int64_t round_up(int64_t a, int bits) {
  return (a + (1LL << bits) - 1) >> bits;
}

bool check_sym(int64_t a, int n) {
  int64_t rev = inverse(a, n - 2);
  return a <= rev;
}

bool check_anti(int64_t a, int n) {
  int64_t rev = flip(inverse(a, n - 2), n - 2);
  return a <= rev;
}

bool check(int64_t a, int n) {
  if (a % 2 == 0) return check_sym(a / 2, n);
  return check_anti(a / 2, n);
}

int64_t calc_variants2(int64_t a, int len, int n) {
  int rest = n - len - 2;
  int64_t bound = round_up((a + 1) << rest, len);
  int64_t res = 2 * ((1LL << rest) - bound);
  if (bound > 0 && check_sym((a << rest) + inverse(bound - 1, rest), n)) {
    res++;
  }
  if (bound > 0 && check_anti((a << rest) + flip(inverse(bound - 1, rest), rest), n)) {
    res++;
  }
  return res;
}

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  int64_t k;
  in >> k;
  int64_t total = fsym(n - 2) + fanti(n - 2);
  if (k >= total) {
    out << -1 << std::endl;
    return;
  }
  int64_t a = 0;
  int len = 0;
  for (int i = 0; i < n / 2 - 1; i++) {
    a = 2 * a;
    len++;
    int64_t variants = calc_variants1(a, len, n);
    if (k >= variants) {
      k -= variants;
      a++;
    }
  }
  for (; len < n - 2; ) {
    a = 2 * a;
    len++;
    int64_t variants = calc_variants2(a, len, n);
    if (k >= variants) {
      k -= variants;
      a++;
    }
  }
  a = 2 * a;
  len++;
  if ((k == 0 && !check(a, n)) || k == 1) {
    a++;
  }
  std::string res;
  for (int i = 0; i < n; i++) {
    res.append(1, (a & 1) ? '1' : '0');
    a >>= 1;
  }
  std::reverse(res.begin(), res.end());
  out << res << std::endl;
}

int main() {
  run(std::cin, std::cout);
  return 0;
}