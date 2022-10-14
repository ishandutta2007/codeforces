#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

const int Q = 300'001;

// a * x + b
struct Line {
  Long eval(int x) const { return 1LL * a * x + b; }

  int a, b;
};

bool check(const Line &u, const Line &v, const Line &w) {
  return 1LL * (u.b - v.b) * (w.a - v.a) < 1LL * (v.b - w.b) * (v.a - u.a);
}

struct Hull : public std::vector<Line> {
  void add(const Line &l) {
    while (size() >= 2 && !check(at(size() - 2), back(), l)) {
      pop_back();
    }
    push_back(l);
  }

  Long ask(int x) {
    if (empty()) {
      return std::numeric_limits<Long>::min();
    }
    while (i + 1 < size() && at(i).eval(x) < at(i + 1).eval(x)) {
      i++;
    }
    return at(i).eval(x);
  }

  int i = 0;
};

Hull tree[Q << 1];

int get_id(int l, int r) { return l + r | (l != r); }

void add_line(int l, int r, int a, int b, const Line &line) {
  if (b < l || r < a) {
    return;
  }
  if (a <= l && r <= b) {
    tree[get_id(l, r)].add(line);
  } else {
    int m = (l + r) >> 1;
    add_line(l, m, a, b, line);
    add_line(m + 1, r, a, b, line);
  }
}

Long ask(int l, int r, int k, int x) {
  Long result = tree[get_id(l, r)].ask(x);
  if (l < r) {
    int m = (l + r) >> 1;
    if (k <= m) {
      result = std::max(result, ask(l, m, k, x));
    } else {
      result = std::max(result, ask(m + 1, r, k, x));
    }
  }
  return result;
}

int main() {
  int q;
  scanf("%d", &q);
  int now = 0;
  std::map<int, std::tuple<int, int, int>> pmap;
  std::vector<std::tuple<int, int, int, int>> points;
  std::vector<std::tuple<int, int, int>> queries;
  for (int i = 0, op, x, y; i < q; ++i) {
    scanf("%d%d", &op, &x);
    if (op == 1) {
      scanf("%d", &y);
      pmap[i + 1] = {x, y, ++now};
    } else if (op == 2) {
      auto iterator = pmap.find(x);
      auto [a, b, enter] = iterator->second;
      points.emplace_back(a, b, enter, now++);
      pmap.erase(iterator);
    } else {
      queries.emplace_back(x, now, queries.size());
    }
  }
  for (auto iterator : pmap) {
    auto [a, b, enter] = iterator.second;
    points.emplace_back(a, b, enter, now);
  }
  std::sort(points.begin(), points.end());
  for (auto [a, b, enter, leave] : points) {
    add_line(0, now, enter, leave, Line{a, b});
  }
  std::sort(queries.begin(), queries.end());
  std::vector<Long> result(queries.size());
  for (auto [x, t, i] : queries) {
    result[i] = ask(0, now, t, x);
  }
  for (auto &&r : result) {
    if (r == std::numeric_limits<Long>::min()) {
      puts("EMPTY SET");
    } else {
      printf("%lld\n", r);
    }
  }
}