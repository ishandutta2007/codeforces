#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

struct colorcount_t {
  int many[3];
  colorcount_t() {
    for (int i = 0; i < 3; ++i)
      many[i] = 0;
  }
};

struct separator_t {
  struct query_t {
    int low, high;
    int many_low, many_high;
    map<int, colorcount_t>::iterator it;

    void update(map<int, colorcount_t> &counts) {
      while (many_low > many_high && it != counts.begin()) {
        --it;
        many_low -= it->second.many[low];
        many_high += it->second.many[high];
      }
      while (many_low < many_high && it != counts.end()) {
        many_high -= it->second.many[high];
        many_low += it->second.many[low];
        ++it;
      }
      if (it != counts.begin()) {
        auto it2 = it;
        --it2;
        int many_low2 = many_low - it2->second.many[low];
        int many_high2 = many_high + it2->second.many[high];
        if (min(many_low2, many_high2) > result()) {
          it = it2;
          many_low = many_low2;
          many_high = many_high2;
        }
      }
    }

    int result() const {
      return min(many_low, many_high);
    }
  };
  vector<query_t> queries;
  map<int, colorcount_t> counts;
  separator_t() {
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        if (i != j)
          queries.push_back({i, j, 0, 0, counts.end()});
  }
  void add(int pos, int added_color) {
    counts[pos].many[added_color] += 1;
    for (query_t &q : queries) {
      if (q.it == counts.end() || pos < q.it->first) {
        if (q.low == added_color) q.many_low += 1;
      } else {
        if (q.high == added_color) q.many_high += 1;
      }
      q.update(counts);
    }
  }
};

int main() {
  int n;
  scanf("%d", &n);
  struct point_t {
    int x, y, c;
  };
  vector<point_t> points(n);
  for (int i = 0; i < n; ++i)
    scanf("%d %d %d", &points[i].x, &points[i].y, &points[i].c), --points[i].c;

  int result = 0;
  for (int rep = 0; rep < 2; ++rep) {
    colorcount_t cc;

    for (int i = 0; i < n; ++i)
      cc.many[points[i].c] += 1;

    sort(points.begin(), points.end(),
         [](const point_t &lhs, const point_t &rhs) {
           return lhs.x < rhs.x;
         });

    separator_t sep;
    for (int i = 0, j = i; i != n; i = j) {
      while (j != n && points[j].x == points[i].x) ++j;
      for (int k = i; k < j; ++k) {
        sep.add(points[k].x, points[k].c);
        cc.many[points[k].c] -= 1;
      }

      for (const separator_t::query_t &q : sep.queries) {
        int other = 0 ^ 1 ^ 2 ^ q.low ^ q.high;
        int res = min(q.result(), cc.many[other]);
        result = max(result, res);
      }
    }

    for (int i = 0; i < n; ++i)
      swap(points[i].x, points[i].y);
  }

  for (int rep1 = 0; rep1 < 2; ++rep1) {
    for (int rep2 = 0; rep2 < 2; ++rep2) {

      //
      colorcount_t cc;

      for (int i = 0; i < n; ++i)
        cc.many[points[i].c] += 1;

      sort(points.begin(), points.end(),
           [](const point_t &lhs, const point_t &rhs) {
             return lhs.x < rhs.x;
           });

      separator_t sep;
      for (int i = 0, j = i; i != n; i = j) {
        while (j != n && points[j].x == points[i].x) ++j;
        for (int k = i; k < j; ++k) {
          sep.add(points[k].y, points[k].c);
          cc.many[points[k].c] -= 1;
        }

        for (const separator_t::query_t &q : sep.queries) {
          int other = 0 ^ 1 ^ 2 ^ q.low ^ q.high;
          int res = min(q.result(), cc.many[other]);
          result = max(result, res);
        }
      }
      //

      for (int i = 0; i < n; ++i)
        points[i].x = -points[i].x;
    }

    for (int i = 0; i < n; ++i)
      swap(points[i].x, points[i].y);
  }

  printf("%d\n", result * 3);

  return 0;
}