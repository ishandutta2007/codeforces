#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

template <typename T = int> T read() {
  T v;
  std::cin >> v;
  return v;
}

template <typename T = int> std::vector<T> read_vector(size_t n) {
  std::vector<T> v(n);
  for (size_t i = 0; i < n; ++i) {
    v[i] = read<T>();
  }
  return v;
}

#define ALL(v) (v).begin(), (v).end()

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-169394NHZJcbNRhp3u.cpp"

#line 4 "/tmp/tmp-169394NHZJcbNRhp3u.cpp"

const int N = 200'000;

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    std::vector<int> count(N + 1);
    int n = read();
    for (int a : read_vector(n)) {
      count[a]++;
    }
    std::vector<int> dp(N + 1);
    for (int i = N; i >= 1; --i) {
      for (int j = i + i; j <= N; j += i) {
        dp[i] = std::max(dp[i], dp[j]);
      }
      dp[i] += count[i];
    }
    std::cout << n - *std::ranges::max_element(dp) << "\n";
  }
}