#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<std::pair<int, int>> v(n);
    long long sum_p = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &v[i].first, &v[i].second);
      sum_p += v[i].second;
    }
    std::sort(v.begin(), v.end());
    std::priority_queue<int> pq;
    for (int i = 0, j = 0; i < n; ++i) {
      while (j < n && v[j].first <= i) {
        pq.push(v[j++].second);
      }
      if (!pq.empty()) {
        sum_p -= pq.top();
        pq.pop();
      }
    }
    printf("%lld\n", sum_p);
  }
}