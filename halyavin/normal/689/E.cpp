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

const int p = 1000000007;

int mul32(int x, int y) {
  return int(int64_t(x) * y % p);
}

int add32(int x, int y) {
  int res = x + y;
  if (res >= p) res -= p;
  return res;
}

std::vector<int> getBin(int k, int n) {
  std::vector<int> res(n + 1);
  res[k] = 1;
  int cur = 1;
  std::vector<int> inv(n + 1);
  inv[1] = 1;
  for (int i = 2; i <= n; i++) {
    inv[i] = p - mul32(inv[p % i], p / i);
  }
  for (int i = k + 1; i <= n; i++) {
    cur = mul32(cur, i);
    cur = mul32(cur, inv[i - k]);
    res[i] = cur;
  }
  return res;
}

void run(std::istream& in, std::ostream& out) {
  int k, n;
  in >> n >> k;
  std::vector<int> bins = getBin(k, n);
  std::vector<std::pair<int, int>> ends;
  for (int i = 0; i < n; i++) {
    int l, r;
    in >> l >> r;
    ends.emplace_back(l, 0);
    ends.emplace_back(r, 1);
  }
  std::sort(ends.begin(), ends.end());
  int ans = 0;
  int weight = 0;
  int x = ends[0].first;
  int sign = 0;
  for (std::pair<int, int>& point : ends) {
    if (point.first > x) {
      if (sign == 0) {
        ans = add32(ans, mul32((point.first - x) % p, bins[weight]));
        x = point.first;
      } else {
        ans = add32(ans, mul32((point.first - x - 1) % p, bins[weight]));
        x = point.first;
        sign = 0;
      }
    }
    if (point.second == 0) {
      weight++;
      continue;
    }
    if (point.second == 1) {
      if (sign == 0) {
        ans = add32(ans, bins[weight]);
        sign = 1;
      }
      weight--;
    }
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}