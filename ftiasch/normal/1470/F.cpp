#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

struct Point {
  int x, y;
};

Point operator-(const Point &a, const Point &b) {
  return {a.x - b.x, a.y - b.y};
}

bool by_x(const Point &a, const Point &b) { return a.x < b.x; }

long long area(int a, int b) { return 1LL * a * b; }

long long det(const Point &a, const Point &b) {
  return area(a.x, b.y) - area(a.y, b.x);
}

long long dot(const Point &a, const Point &b) {
  return area(a.x, b.x) + area(a.y, b.y);
}

bool operator<(const Point &a, const Point &b) { return det(a, b) > 0; }

const int N = 200000;
const long long INF = 2e18;

int n, preymin[N + 1], preymax[N + 1], sufymin[N + 1], sufymax[N + 1];
Point p[N];
long long result;

static int get_id(int l, int r) { return l + r | l != r; }

struct SGT {
  void init() { std::fill(tree, tree + (n << 1), INF); }

  void update(int l, int r, int i, long long v) {
    if (l == r) {
      tree[get_id(l, r)] = v;
    } else {
      int m = l + r >> 1;
      if (i <= m) {
        update(l, m, i, v);
      } else {
        update(m + 1, r, i, v);
      }
      tree[get_id(l, r)] = std::min(tree[get_id(l, m)], tree[get_id(m + 1, r)]);
    }
  }

  long long get_min(int l, int r, int a, int b) const {
    if (b < l || r < a) {
      return INF;
    }
    if (a <= l && r <= b) {
      return tree[get_id(l, r)];
    }
    int m = l + r >> 1;
    return std::min(get_min(l, m, a, b), get_min(m + 1, r, a, b));
  }

  long long tree[N << 1];
};

struct CHSGT {
  void init() {
    std::fill(opt, opt + (n << 1), 0);
    for (int i = 0; i < n << 1; ++i) {
      tree[i].clear();
    }
  }

  void add(int l, int r, int a, int b, const Point &p) {
    if (b < l || r < a) {
      return;
    }
    if (a <= l && r <= b) {
      auto &h = tree[get_id(l, r)];
      while (static_cast<int>(h.size()) >= 2 &&
             det(h.back() - h[h.size() - 2], p - h.back()) <= 0) {
        h.pop_back();
      }
      h.push_back(p);
    } else {
      int m = l + r >> 1;
      add(l, m, a, b, p);
      add(m + 1, r, a, b, p);
    }
  }

  long long get_min(int l, int r, int i, const Point &p) {
    long long result = INF;
    int id = get_id(l, r);
    auto &o = opt[id];
    auto &h = tree[id];
    if (!h.empty()) {
      while (o + 1 < static_cast<int>(h.size()) &&
             dot(h[o], p) >= dot(h[o + 1], p)) {
        o++;
      }
      result = dot(h[o], p);
    }
    if (l < r) {
      int m = l + r >> 1;
      result = std::min(result,
                        i <= m ? get_min(l, m, i, p) : get_min(m + 1, r, i, p));
    }
    return result;
  }

  int opt[N << 1];
  std::vector<Point> tree[N << 1];
};

void prepare() {
  preymin[0] = sufymin[n] = 1e9;
  preymax[0] = sufymax[n] = 0;
  for (int i = 0; i < n; ++i) {
    preymin[i + 1] = std::min(preymin[i], p[i].y);
    preymax[i + 1] = std::max(preymax[i], p[i].y);
  }
  for (int i = n; i--;) {
    sufymin[i] = std::min(sufymin[i + 1], p[i].y);
    sufymax[i] = std::max(sufymax[i + 1], p[i].y);
  }
}

void update_result(long long a) { result = std::min(result, a); }

void solve_seperatable() {
  for (int i = 1; i < n; ++i) {
    update_result(area(p[i - 1].x - p[0].x, preymax[i] - preymin[i]) +
                  area(p[n - 1].x - p[i].x, sufymax[i] - sufymin[i]));
  }
}

std::pair<int, int> order[N];
int rank[N];
SGT lesser, greater;

void solve_cross() {
  const int width = p[n - 1].x - p[0].x;
  const int height = sufymax[0] - sufymin[0];
  for (int i = 0; i < n; ++i) {
    order[i] = {preymin[i], i};
  }
  std::sort(order, order + n);
  for (int i = 0; i < n; ++i) {
    rank[order[i].second] = i;
  }
  lesser.init();
  greater.init();
  for (int j = 0, i = 1; j + 1 < n; ++j) {
    int j_rank =
        static_cast<int>(std::lower_bound(order, order + n,
                                          std::make_pair(sufymin[j + 1], n)) -
                         order) -
        1;
    if (preymax[j] <= sufymax[j + 1]) {
      i = j;
      lesser.update(0, n - 1, rank[i],
                    -area(p[i].x, height) - area(preymin[i], width));
      greater.update(0, n - 1, rank[i], -area(p[i].x, height));
    }
    while (i && preymax[i] > sufymax[j + 1]) {
      lesser.update(0, n - 1, rank[i], INF);
      greater.update(0, n - 1, rank[i], INF);
      i--;
    }
    // fprintf(stderr, "la=%lld\n", area(p[j].x, height) + area(sufymax[j + 1],
    // width)); fprintf(stderr, "lq=%lld\n", lesser.get_min(0, n - 1, 0,
    // j_rank));
    update_result(area(p[j].x, height) + area(sufymax[j + 1], width) +
                  lesser.get_min(0, n - 1, 0, j_rank));
    update_result(area(p[j].x, height) +
                  area(sufymax[j + 1] - sufymin[j + 1], width) +
                  greater.get_min(0, n - 1, j_rank + 1, n));
  }
  // for (int j = 0; j + 1 < n; ++j) {
  //   for (int i = 1; i <= j; ++i) {
  //     if (preymax[i] <= sufymax[j + 1]) {
  //       if (preymin[i] <= sufymin[j + 1]) {
  //         auto a = (area(p[j].x - p[i].x, height) +
  //                   area(sufymax[j + 1] - preymin[i], width));
  //         // fprintf(stderr, "1 %d %d %lld\n", i, j, a);
  //         update_result(a);
  //       } else if (j + 1 < n) {
  //         auto a = (area(p[j].x - p[i].x, height) +
  //                   area(sufymax[j + 1] - sufymin[j + 1], width));
  //         // fprintf(stderr, "2 %d %d %lld\n", i, j, a);
  //         update_result(a);
  //       }
  //     }
  //   }
  // }
}

CHSGT ht;
std::pair<Point, int> queries[N];

void solve_corner() {
  ht.init();
  for (int i = n, j = n - 1; i--;) {
    while (i <= j && preymax[i] < sufymin[j + 1]) {
      j--;
    }
    if (i <= j) {
      ht.add(0, n - 1, i, j,
             Point{p[n - 1].x - p[i].x, preymax[i] - sufymin[0]});
    }
  }
  for (int j = 0; j < n; ++j) {
    queries[j] =
        std::make_pair(Point{sufymax[0] - sufymin[j + 1], p[j].x - p[0].x}, j);
  }
  std::sort(queries, queries + n);
  for (int j = 0; j < n; ++j) {
    update_result(ht.get_min(0, n - 1, queries[j].second, queries[j].first));
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &p[i].x, &p[i].y);
    }
    result = n == 1 ? 0 : INF;
    std::sort(p, p + n, by_x);
    prepare();
    solve_seperatable();
    solve_cross();
    solve_corner();
    for (int i = 0; i < n; ++i) {
      p[i] = {p[n - 1].x - p[i].x, p[i].y};
    }
    std::reverse(p, p + n);
    prepare();
    solve_cross();
    solve_corner();
    for (int i = 0; i < n; ++i) {
      p[i] = {p[i].y, p[i].x};
    }
    std::sort(p, p + n, by_x);
    prepare();
    solve_seperatable();
    printf("%lld\n", result);
  }
}