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

const int mod = 1000000007;

int add32(int x, int y) {
  int res = x + y;
  if (res >= mod) res -= mod;
  return res;
}

int sub32(int x, int y) {
  int res = x - y;
  if (res < 0) res += mod;
  return res;
}

int mul32(int x, int y) {
  return int(int64_t(x) * y % mod);
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

void addBin(std::vector<int>& stat, int offset, int len) {
  int c = 1;
  for (int i = 0; i < len; i++) {
    stat[i + offset] = add32(stat[i + offset], c);
    c = mul32(c, len - i);
    c = mul32(c, inv(i + 1, mod));
  }
  stat[offset + len] = add32(stat[offset + len], c);
}


void run(std::istream &in, std::ostream &out) {
  std::string s;
  in >> s;
  int k;
  in >> k;
  if (k == 0) {
    out << "1\n";
    return;
  }
  std::vector<int> stat(s.length() + 1);
  int offset = 0;
  int len = s.length();
  for (size_t i = 0; i < s.length(); i++) {
    if (s[i] == '1') {
        addBin(stat, offset, len - 1);
        offset++;
    }
    len--;
  }
  stat[offset] = add32(stat[offset], 1);
  stat[1] = sub32(stat[1], 1);
  std::vector<int> counts(s.length() + 1);
  counts[1] = 0;
  for (size_t i = 2; i < counts.size(); i++) {
    counts[i] = counts[__builtin_popcount(i)] + 1;
  }
  int ans = 0;
  for (size_t i = 1; i < counts.size(); i++) {
    if (counts[i] == k - 1) {
      ans = add32(ans, stat[i]);
    }
  }
  out << ans << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}