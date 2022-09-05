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

bool check(const std::vector<int>& d, int k) {
  for (int i = 0; i < d.size(); i++) {
    if (i / k > d[i]) {
      return false;
    }
  }
  return true;
}

void run(std::istream& in, std::ostream& out) {
  int n, m, k;
  in >> n >> m >> k;
  std::vector<int> f(n);
  for (int i = 0; i < n; i++) {
    in >> f[i];
  }
  std::vector<std::pair<int, int>> s(m);
  for (int i = 0; i < m; i++) {
    in >> s[i].first;
    s[i].second = i + 1;
  }
  std::sort(f.begin(), f.end());
  std::sort(s.begin(), s.end());
  std::vector<int> ss(m);
  for (int i= 0; i <m; i++) {
    ss[i] = s[i].first;
  }
  if (!check(f, k)) {
    out << -1 << std::endl;
    return;
  }
  int left = 0;
  int right = s.size() + 1;
  while (right - left > 1) {
    int middle = (left + right) / 2;
    std::vector<int> all(n + middle);
    std::merge(f.begin(), f.end(), ss.end() - middle, ss.end(), all.begin());
    if (check(all, k)) {
      left = middle;
    } else {
      right = middle;
    }
  }
  out << left << std::endl;
  for (int i = 0; i < left; i++) {
    out << s[m - i - 1].second << " ";
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}