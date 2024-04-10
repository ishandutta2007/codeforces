#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

struct line {
  i64 k, b;

  i64 apply(i64 x) const {
    return k * x + b;
  }
};

//  first x0: y(x0) < x(x0)
i64 inter(line x, line y) {
  assert(y.k < x.k);
  auto point = (y.b - x.b) / (x.k - y.k);
  while (x.apply(point) <= y.apply(point)) ++point;
  while (y.apply(point - 1) < x.apply(point - 1)) --point;
  return point;
}

//  slopes are non-increasing
struct cht_min {
  i64 const INF = 1e9;
  vector<pair<line, i64>> lines;

  void add_line(line const& l) {
    if (!lines.empty() && lines.back().first.k == l.k) {
      if (lines.back().first.b <= l.b) return;
      lines.pop_back();
      if (!lines.empty()) {
        lines.back().second = INF;
      }
    }
    while (lines.size() >= 2) {
      auto x_my = inter(lines.back().first, l);
      auto x_they = inter(lines[lines.size() - 2].first, lines.back().first);
      if (x_my <= x_they) {
        lines.pop_back();
      } else {
        break;
      }
    }
    if (lines.empty()) {
      lines.emplace_back(l, INF);
    } else {
      auto x = inter(lines.back().first, l);
      lines.back().second = x;
      lines.emplace_back(l, INF);
    }
  }

  i64 query(i64 x) const {
    auto it = upper_bound(lines.begin(), lines.end(), x, [](i64 a, auto b) {
      return a < b.second;
    });
    return it->first.apply(x);
  }

  //  <x, y>: f(x) <= y, x -> min
  pair<i64, i64> findFirst(i64 y) const {
    int left = -1;
    int right = int(lines.size());
    while (left + 1 != right) {
      int middle = (left + right) / 2;
      auto value = lines[middle].first.apply(lines[middle].second - 1);
      if (value <= y) {
        right = middle;
      } else {
        left = middle;
      }
    }
    auto l = lines[right].first;
    auto point = (y - l.b) / l.k;
    while (l.apply(point) > y) ++point;
    while (l.apply(point - 1) <= y) --point;
    return make_pair(point, l.apply(point));
  }
};

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<tuple<i64, i64, i64>> a(n);
  for (auto&[x, y, w] : a) {
    cin >> x >> y >> w;
  }
  sort(a.begin(), a.end());

  cht_min cht;
  cht.add_line({0, 0});

  i64 answer = 0;
  for (auto[x, y, w] : a) {
    i64 cur = x * y - w - cht.query(-y);
    answer = max(answer, cur);
    cht.add_line({-x, -cur});
  }
  cout << answer << '\n';
}