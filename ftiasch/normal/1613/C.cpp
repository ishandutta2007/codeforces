#include <bits/stdc++.h>

const int N = 100;

int n;
long long h, a[N];

long long count(long long k) {
  long long result = k;
  for (int i = n - 2; i >= 0; --i) {
    result = std::min(result + std::min(a[i + 1] - a[i], k), h);
  }
  return result;
}

int main() {
  std::ios::sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    std::cin >> n >> h;
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    long long low = 0, high = h;
    while (low < high) {
      long long middle = (low + high) >> 1;
      if (count(middle) >= h) {
        high = middle;
      } else {
        low = middle + 1;
      }
    }
    std::cout << high << "\n";
  }
}