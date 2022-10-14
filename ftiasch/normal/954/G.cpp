#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, r;
  long long m;
  scanf("%d%d%lld", &n, &r, &m);
  std::vector<long long> d(n + 1);
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    d[std::max(i - r, 0)] += a;
    d[std::min(i + r + 1, n)] -= a;
  }
  for (int i = 1; i < n; ++i) {
    d[i] += d[i - 1];
  }

  r = r * 2 + 1;

  std::vector<long long> delta(n + 1);
  auto solve = [&](long long limit) -> bool {
    std::fill(delta.begin(), delta.end(), 0LL);
    long long sum = 0, cost = 0;
    for (int i = 0; i < n; ++i) {
      sum += delta[i];
      long long extra = std::max(limit - (d[i] + sum), 0LL);
      cost += extra;
      if (cost > m) {
          return false;
      }
      sum += extra;
      delta[std::min(i + r, n)]-=extra;
    }
    return true;
  };
  long long low = 0;
  long long high = 1000500000000000000;
  while (low < high) {
    long long middle = (low + high + 1) >> 1;
    if (solve(middle)) {
      low = middle;
    } else {
      high = middle - 1;
    }
  }
  printf("%lld\n", low);
}