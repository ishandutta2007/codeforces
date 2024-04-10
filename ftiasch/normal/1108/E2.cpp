#include <bits/stdc++.h>

const int N = 100000;
const int M = 300;

struct Segment {
  int min = INT_MAX, max = INT_MIN;
};

int n, m, a[N], l[M], r[M];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  std::vector<int> cuts{0, n};
  // 0 1 2 3 4
  //  1 2 3 4
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", l + i, r + i);
    cuts.push_back(l[i] - 1);
    cuts.push_back(r[i]);
  }
  std::sort(cuts.begin(), cuts.end());
  cuts.erase(std::unique(cuts.begin(), cuts.end()), cuts.end());
  std::vector<Segment> segments;
  int c = static_cast<int>(cuts.size()) - 1;
  for (int i = 0; i < c; ++i) {
    Segment s;
    for (int j = cuts[i]; j < cuts[i + 1]; ++j) {
      s.min = std::min(s.min, a[j]);
      s.max = std::max(s.max, a[j]);
    }
    segments.push_back(s);
  }
  std::tuple<int, int, int> result{-1, 0, 0};
  for (int i = 0; i < c; ++i) {
    for (int j = 0; j < c; ++j) {
      int count_j = 0;
      for (int k = 0; k < m; ++k) {
        bool contains_i = l[k] - 1 <= cuts[i] && cuts[i] <= r[k] - 1;
        bool contains_j = l[k] - 1 <= cuts[j] && cuts[j] <= r[k] - 1;
        count_j += !contains_i && contains_j;
      }
      result = std::max(
          result,
          std::make_tuple(segments[i].max - (segments[j].min - count_j), i, j));
    }
  }
  printf("%d\n", std::get<0>(result));
  std::vector<int> plan;
  {
    int i = std::get<1>(result);
    int j = std::get<2>(result);
    for (int k = 0; k < m; ++k) {
      bool contains_i = l[k] - 1 <= cuts[i] && cuts[i] <= r[k] - 1;
      bool contains_j = l[k] - 1 <= cuts[j] && cuts[j] <= r[k] - 1;
      if (!contains_i && contains_j) {
        plan.push_back(k);
      }
    }
  }
  int size = plan.size();
  printf("%d\n", size);
  for (int i = 0; i < size; ++i) {
    printf("%d%c", plan[i] + 1, " \n"[i + 1 == size]);
  }
}