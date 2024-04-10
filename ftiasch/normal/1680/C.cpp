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

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-418191zwhj6hrxUuxF.cpp"

#line 4 "/tmp/tmp-418191zwhj6hrxUuxF.cpp"

struct Check {
  Check(int n, const std::string &s) : n(n), s(s), zeros(n + 1), ones(n + 1) {
    for (int i = n; i--;) {
      zeros[i] = (s[i] == '0') + zeros[i + 1];
      ones[i] = (s[i] == '1') + ones[i + 1];
    }
  }

  bool operator()(int limit) {
    // [i, j)
    // zeros[i] - zeros[j] <= limit
    // ones[0] - (ones[i] - ones[j]) <= limit
    if (ones[0] <= limit) {
      return true;
    }
    for (int i = n, j = n; i--;) {
      while (zeros[i] - zeros[j] > limit) {
        j--;
      }
      if (ones[0] - (ones[i] - ones[j]) <= limit) {
        return true;
      }
    }
    return false;
  }

  int n;
  const std::string &s;
  std::vector<int> zeros, ones;
};

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    auto s = read<std::string>();
    int n = s.size();
    Check check(n, s);
    int low = 0;
    int high = n;
    while (low < high) {
      int middle = (low + high) >> 1;
      if (check(middle)) {
        high = middle;
      } else {
        low = middle + 1;
      }
    }
    std::cout << high << "\n";
  }
}