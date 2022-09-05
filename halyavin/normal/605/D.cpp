#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif

#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>

const int inf = 2000000000;

struct BinTree {
  size_t size;
  std::vector<int> t;

  BinTree(size_t N) :
      size(N),
      t(2 * N) { }

  BinTree(const std::vector<int>& other) :
      size(other.size()),
      t(2 * other.size()) {
    std::copy(other.begin(), other.end(), t.begin() + size);
    for (size_t i = size; i-- > 1;) {
      t[i] = combine(t[2 * i], t[2 * i + 1]);
    }
  }

  int get(size_t p) {
    return t[p + size];
  }

  void modify(size_t p) {
    p += size;
    t[p] = inf;
    while (p > 1) {
      p = p / 2;
      t[p] = combine(t[2 * p], t[2 * p + 1]);
    }
  }

  void resolve(size_t node, int v, std::vector<int>& res) {
    if (node >= size) {
      res.push_back(node - size);
      modify(node - size);
      return;
    }
    if (t[2 * node] <= v) {
      resolve(2 * node, v, res);
    }
    if (t[2 * node + 1] <= v) {
      resolve(2 * node + 1, v, res);
    }
  }

  void query(size_t r, int v, std::vector<int>& res) {
    res.resize(0);
    size_t l = size;
    r += size;
    while (r > l) {
      if (l & 1) {
        if (t[l] <= v) {
          resolve(l, v, res);
        }
        l++;
      }
      if (r & 1) {
        r--;
        if (t[r] <= v) {
          resolve(r, v, res);
        }
      }
      r /= 2;
      l /= 2;
    }
  }

private:
  int combine(int left, int right) {
    return std::min(left, right);
  }

  int init() {
    return 0;
  }
};

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  std::vector<std::array<int, 4>> data(n);
  for (int i = 0; i < n; i++) {
    in >> data[i][0] >> data[i][1] >> data[i][2] >> data[i][3];
  }
  std::vector<std::array<int, 3>> low_points(n);
  for (int i = 0; i < n; i++) {
    low_points[i][0] = data[i][0];
    low_points[i][1] = data[i][1];
    low_points[i][2] = i;
  }
  std::sort(low_points.begin(), low_points.end());
  std::vector<int> dist(n, -1);
  std::vector<int> prev(n, -1);
  std::vector<std::array<int, 3>> queue;
  queue.push_back(std::array<int, 3>{0, 0, -1});
  size_t bque = 0;
  std::vector<int> ys(n);
  for (int i = 0; i < n; i++) {
    ys[i] = low_points[i][1];
  }
  BinTree tree(ys);
  std::vector<int> points;
  while (bque < queue.size()) {
    std::array<int, 3> cur = queue[bque];
    int new_dist = cur[2] < 0 ? 1 : dist[cur[2]] + 1;
    bque++;
    int r =
        std::upper_bound(low_points.begin(), low_points.end(), std::array<int, 3>{cur[0], inf, 0}) - low_points.begin();
    tree.query(r, cur[1], points);
    for (size_t i = 0; i < points.size(); i++) {
      int idx = low_points[points[i]][2];
      queue.push_back(std::array<int, 3>{data[idx][2], data[idx][3], idx});
      dist[idx] = new_dist;
      prev[idx] = cur[2];
    }
  }
  if (dist[n - 1] < 0) {
    out << "-1" << std::endl;
    return;
  }
  std::vector<int> ans;
  int cur = n - 1;
  while (cur >= 0) {
    ans.push_back(cur);
    cur = prev[cur];
  }
  std::reverse(ans.begin(), ans.end());
  out << ans.size() << std::endl;
  for (int i = 0; i < ans.size(); i++) {
    out << (ans[i] + 1) << " ";
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}