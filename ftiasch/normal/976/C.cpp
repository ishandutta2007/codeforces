#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<std::tuple<int, int, int>> segments(n);
  for (int i = 0, l, r; i < n; ++i) {
    scanf("%d%d", &l, &r);
    segments[i] = {l, -r, i + 1};
  }
  std::sort(segments.begin(), segments.end());
  std::pair<int, int> candidate;
  for (auto [l, neg_r, i] : segments) {
    int r = -neg_r;
    if (r <= candidate.first) {
      printf("%d %d\n", i, candidate.second);
      return 0;
    }
    candidate = std::max(candidate, {r, i});
  }
  puts("-1 -1");
}