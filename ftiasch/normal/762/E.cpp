#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int F = 10'000;

struct DS {
  void pre_add(int x) { xs.push_back(x); }

  void init() {
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    fenwick.resize(xs.size());
  }

  void add(int x) {
    for (int i = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin(); ~i;
         i -= ~i & i + 1) {
      fenwick[i]++;
    }
  }

  int ask(int x) const {
    int result = 0;
    for (int i = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();
         i < xs.size(); i += ~i & i + 1) {
      result += fenwick[i];
    }
    return result;
  }

  int ask(int x, int r) const { return ask(x - r) - ask(x + r + 1); }

  std::vector<int> xs, fenwick;
};

int main() {
  int n, limit;
  scanf("%d%d", &n, &limit);
  std::vector<std::tuple<int, int, int>> s(n);
  std::vector<DS> ds(F + 1);
  for (int i = 0, x, r, f; i < n; ++i) {
    scanf("%d%d%d", &x, &r, &f);
    s[i] = {r, x, f};
    ds[f].pre_add(x);
  }
  for (int f = 1; f <= F; ++f) {
    ds[f].init();
  }
  std::sort(s.begin(), s.end(), std::greater<std::tuple<int, int, int>>());
  long long result = 0;
  for (auto [r, x, f] : s) {
    for (int ff = std::max(f - limit, 0); ff <= f + limit && ff <= F; ++ff) {
      result += ds[ff].ask(x, r);
    }
    ds[f].add(x);
  }
  printf("%lld\n", result);
}