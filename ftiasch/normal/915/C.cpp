#line 1 "sol.cpp"
#include <bits/stdc++.h>

template <int offset> std::vector<int> read() {
  long long n;
  scanf("%lld", &n);
  n += offset;
  std::vector<int> d;
  while (n) {
    d.push_back(n % 10);
    n /= 10;
  }
  std::reverse(d.begin(), d.end());
  return d;
}

std::vector<int> work(const std::vector<int> &a, const std::vector<int> &b) {
  std::array<int, 10> count_a{}, count_b{};
  for (int d : a) {
    count_a[d]++;
  }
  for (int d : b) {
    count_b[d]++;
  }
  for (int i = b.size(); i--;) {
    count_b[b[i]]--;
    for (int d = b[i] - 1; d >= !i; --d) {
      bool ok = true;
      for (int j = 0; j < 10; ++j) {
        ok &= count_b[j] + (j == d) <= count_a[j];
      }
      if (ok) {
        std::vector<int> result;
        for (int j = 0; j < i; ++j) {
          result.push_back(b[j]);
          count_a[b[j]]--;
        }
        result.push_back(d);
        count_a[d]--;
        for (int j = 10; j--;) {
          while (count_a[j]--) {
            result.push_back(j);
          }
        }
        return result;
      }
    }
  }
}

int main() {
  auto a = read<0>();
  auto b = read<1>();
  if (a.size() < b.size()) {
    std::sort(a.begin(), a.end(), std::greater<int>());
  } else {
    a = work(a, b);
  }
  for (int d : a) {
    printf("%d", d);
  }
  puts("");
}