#include <bits/stdc++.h>
#include <limits>
#include <random>

const int N = 500000;

uint64_t left[N];
std::pair<uint64_t, uint64_t> right[N];

int main() {
  std::mt19937_64 gen;
  for (int i = 0; i < N; ++i) {
    left[i] = std::uniform_int_distribution<uint64_t>(
        0, std::numeric_limits<uint64_t>::max())(gen);
  }
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    memset(right, 0, sizeof(*right) * n);
    for (int i = 0; i < n; ++i) {
      std::cin >> right[i].second;
    }
    for (int i = 0, u, v; i < m; ++i) {
      std::cin >> u >> v;
      right[v - 1].first ^= left[u ^ 1];
    }
    std::sort(right, right + n);
    uint64_t result = 0;
    for (int i = 0; i < n;) {
      int j = i;
      uint64_t sum = 0;
      while (j < n && right[i].first == right[j].first) {
        sum += right[j++].second;
      }
      if (right[i].first) {
        result = std::__gcd(result, sum);
      }
      i = j;
    }
    std::cout << result << "\n";
  }
}