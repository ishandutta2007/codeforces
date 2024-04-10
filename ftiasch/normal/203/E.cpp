#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

int n, d, s;
std::vector<int> f0, f1;

void update(std::pair<int, int> &result, int c, int f) {
  result = std::max(result, std::make_pair(c, -f));
}

int main() {
  while (scanf("%d%d%d", &n, &d, &s) == 3) {
    long long sumc = 0;
    for (int i = 0, c, f, l; i < n; ++i) {
      scanf("%d%d%d", &c, &f, &l);
      sumc += c;
      if (l >= d) {
        f0.push_back(f);
        if (c) {
          f1.push_back(f);
        }
      }
    }
    std::sort(f0.begin(), f0.end());
    std::pair<int, int> result{0, 0};
    if (!f1.empty()) {
      long long sumf = *std::min_element(ALL(f1));
      f0.erase(std::find(ALL(f0), sumf));
      sumc++;
      for (auto f : f0) {
        if (sumf <= s) {
          update(result, std::min(sumc, 1LL * n), sumf);
        } else {
          break;
        }
        sumc++;
        sumf += f;
      }
      if (sumf <= s) {
        update(result, std::min(sumc, 1LL * n), sumf);
      }
    }
    sumc = 0;
    long long sumf = 0;
    for (auto f : f0) {
      sumc++;
      sumf += f;
      if (sumf <= s) {
        update(result, sumc, sumf);
      }
    }
    printf("%d %d\n", result.first, -result.second);
  }
}