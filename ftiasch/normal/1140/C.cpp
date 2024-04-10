#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<std::pair<int, int>> songs(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &songs[i].second, &songs[i].first);
  }
  std::sort(songs.begin(), songs.end(), std::greater<std::pair<int, int>>());
  long long sum_len = 0;
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  long long result = 0;
  for (auto &&[bty, len] : songs) {
    sum_len += len;
    pq.push(len);
    while (pq.size() > m) {
      sum_len -= pq.top();
      pq.pop();
    }
    result = std::max(result, 1LL * sum_len * bty);
  }
  printf("%lld\n", result);
}