// #include "debug.h"

#include <bits/stdc++.h>

const int MAXK = 20;

int main() {
  int n;
  scanf("%d", &n);
  std::vector<std::pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i].first, &a[i].second);
  }
  std::vector<int> topics;
  topics.reserve(n);
  for (int i = 0; i < n; ++i) {
    topics.push_back(a[i].first);
  }
  std::sort(topics.begin(), topics.end());
  topics.erase(std::unique(topics.begin(), topics.end()), topics.end());
  int m = topics.size();
  for (int i = 0; i < n; ++i) {
    a[i].first = std::lower_bound(topics.begin(), topics.end(), a[i].first) -
                 topics.begin();
  }
  std::vector<std::pair<int, int>> candidates(m);
  std::vector<int> plan;
  int resultp = 0, resultq = 1;
  for (int maxk = 1; maxk <= MAXK && maxk <= m; ++maxk) {
    for (int i = 0; i < m; ++i) {
      candidates[i] = {0, i};
    }
    for (int i = 0; i < n; ++i) {
      auto [m, k] = a[i];
      candidates[m].first += std::min(k, maxk);
    }
    std::nth_element(candidates.begin(), candidates.begin() + (m - maxk),
                     candidates.end());
    int sum = 0;
    for (int i = m - maxk; i < m; ++i) {
      sum += candidates[i].first;
    }
    // std::cerr << KV(maxk) << " " << KV(sum) << " " << candidates << std::endl;
    if (resultp * maxk < sum * resultq) {
      resultp = sum;
      resultq = maxk;
      plan.clear();
      for (int i = m - maxk; i < m; ++i) {
        plan.push_back(topics[candidates[i].second]);
      }
    }
  }
  int sz = plan.size();
  printf("%d\n", sz);
  for (int i = 0; i < sz; ++i) {
    printf("%d%c", plan[i], " \n"[i + 1 == sz]);
  }
}