#include <bits/stdc++.h>

struct Deque {
  void push(long long x) {
    prefix_sum = std::__gcd(prefix_sum, x);
    prefix.push_back(x);
  }

  void pop() {
    if (suffix_sum.empty()) {
      long long s = 0;
      for (int i = prefix.size(); i--;) {
        s = std::__gcd(s, prefix[i]);
        suffix_sum.push_back(s);
      }
      prefix_sum = 0;
      prefix.clear();
    }
    suffix_sum.pop_back();
  }

  long long gcd() const {
    return std::__gcd(suffix_sum.empty() ? 0 : suffix_sum.back(), prefix_sum);
  }

  // suffix | prefix
  long long prefix_sum = 0;
  std::vector<long long> suffix_sum, prefix;
};

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    long long a0;
    scanf("%d", &n);
    n--;
    int result = 1, size = 1;
    Deque q;
    scanf("%lld", &a0);
    for (int i = 0; i < n; ++i) {
      long long a;
      scanf("%lld", &a);
      long long d = std::abs(a - a0);
      size++;
      q.push(d);
      while (q.gcd() == 1) {
        size--;
        q.pop();
      }
      result = std::max(result, size);
      a0 = a;
    }
    printf("%d\n", result);
  }
}