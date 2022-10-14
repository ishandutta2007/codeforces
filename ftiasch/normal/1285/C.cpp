#include <bits/stdc++.h>

using LL = long long;

LL x;
std::pair<LL, LL> best;
std::vector<std::pair<LL, int>> factors;

void dfs(int i, LL b, LL a) {
  if (i < static_cast<int>(factors.size())) {
    LL pe = 1;
    for (int j = 0; j < factors[i].second; ++j) {
      pe *= factors[i].first;
    }
    LL pj = 1;
    for (int j = 0; j < factors[i].second; ++j) {
      dfs(i + 1, b * pj, a * pe);
      pj *= factors[i].first;
    }
    dfs(i + 1, b * pe, a);
  } else if (b >= a) {
    best = std::min(best, std::make_pair(b, a));
  }
}

int main() {
  scanf("%lld", &x);
  best = {x, 1};
  for (int p = 2; 1LL * p * p <= x; ++p) {
    if (x % p == 0) {
      int e = 0;
      while (x % p == 0) {
        e++, x /= p;
      }
      factors.emplace_back(p, e);
    }
  }
  if (x > 1) {
    factors.emplace_back(x, 1);
  }
  dfs(0, 1, 1);
  printf("%lld %lld\n", best.second, best.first);
}