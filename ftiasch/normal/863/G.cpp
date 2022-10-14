#line 1 "/home/ftiasch/Documents/shoka/debug.h"
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <vector>

namespace {

template <typename Tuple, size_t... Index>
std::ostream &serialize_tuple(std::ostream &out, const Tuple &t,
                              std::index_sequence<Index...>) {
  out << "(";
  (..., (out << (Index == 0 ? "" : ", ") << std::get<Index>(t)));
  return out << ")";
}

} // namespace

template <typename A, typename B>
std::ostream &operator<<(std::ostream &out, const std::pair<A, B> &v) {
  return out << "(" << v.first << ", " << v.second << ")";
}

template <typename... T>
std::ostream &operator<<(std::ostream &out, const std::tuple<T...> &t) {
  return serialize_tuple(out, t, std::make_index_sequence<sizeof...(T)>());
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  out << "[";
  bool first = true;
  for (auto &&e : v) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << e;
  }
  return out << "]";
}

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &out, const std::array<T, N> &v) {
  return out << std::vector<T>(v.begin(), v.end());
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::list<T> &v) {
  out << "[";
  bool first = true;
  for (auto &&e : v) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << e;
  }
  return out << "]";
}

template <typename K>
std::ostream &operator<<(std::ostream &out, const std::set<K> &s) {
  out << "{";
  bool first = true;
  for (auto &&k : s) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << k;
  }
  return out << "}";
}

template <typename K, typename V>
std::ostream &operator<<(std::ostream &out, const std::map<K, V> &m) {
  out << "{";
  bool first = true;
  for (auto &&[k, v] : m) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << k << ": " << v;
  }
  return out << "}";
}

#define KV(x) #x << "=" << x << ";"
#line 2 "sol.cpp"

#include <bits/stdc++.h>

using Vec = std::array<int, 6>;

using Point = std::pair<int, int>;

struct Mapper {
  Mapper(int m_, const Vec &dim_) : m(m_), offset(m_ - 1), size(1), dim(dim_) {
    assert(m > 1);
    while (offset && (dim[offset] & 1)) {
      offset--;
    }
    for (int iteration = 1; iteration < m; ++iteration) {
      int i = (offset + iteration) % m;
      if (iteration == 1) {
        for (int j = 0; j < dim[i]; ++j) {
          cache.emplace_back();
          cache.back()[i] = j;
        }
      } else {
        for (int j = 1; j < dim[i]; ++j) {
          for (int k = 0; k < size; ++k) {
            cache.push_back(cache[j * size - 1 - k]);
            cache.back()[i] = j;
          }
        }
      }
      size *= dim[i];
    }
  }

  std::pair<int, int> get_dim() const { return {dim[offset], size}; }

  Vec get(const Point &p) const {
    auto [x, y] = p;
    Vec result = cache[y];
    result[offset] = x;
    return result;
  }

  Point get(const Vec &v) const {
    auto [dim_x, dim_y] = get_dim();
    for (int x = 0; x < dim_x; ++x) {
      for (int y = 0; y < dim_y; ++y) {
        if (v == get(Point{x, y})) {
          return {x, y};
        }
      }
    }
  }

  int m, offset, size;
  Vec dim;
  std::vector<Vec> cache;
};

struct Plan : public std::vector<Point> {
  template <int DX, int DY> void line(int n, int x0, int y0) {
    for (int i = 0; i < n; ++i) {
      emplace_back(x0 + DX * i, y0 + DY * i);
    }
  }

  template <int DX, int DY> void xzigzag(int n, int m, int x0, int y0) {
    for (int i = 0; i < n; ++i) {
      int x = x0 + DX * i;
      if (~i & 1) {
        line<0, DY>(m, x, y0);
      } else {
        line<0, -DY>(m, x, y0 + DY * (m - 1));
      }
    }
  }

  template <int DX, int DY> void yzigzag(int n, int m, int x0, int y0) {
    for (int j = 0; j < m; ++j) {
      int y = y0 + DY * j;
      if (~j & 1) {
        line<DX, 0>(n, x0, y);
      } else {
        line<-DX, 0>(n, x0 + DX * (n - 1), y);
      }
    }
  }
};

struct Cycle2D : public Plan {
  Cycle2D(int n, int m, int x0, int y0) {
    xzigzag<1, 1>(n, m - 1, 0, 1);
    line<-1, 0>(n, n - 1, 0);
    std::rotate(begin(), std::find(begin(), end(), std::make_pair(x0, y0)),
                end());
    push_back(front());
  }
};

struct Path2D : public Plan {
  Path2D(int n, int m, int x0, int y0) {
    bool x_flipped = false, y_flipped = false, xy_swapped = false;
    if (x0 > n - 1 - x0) {
      x_flipped = true;
      x0 = n - 1 - x0;
    }
    if (y0 > m - 1 - y0) {
      y_flipped = true;
      y0 = m - 1 - y0;
    }
    if (x0 > y0) {
      xy_swapped = true;
      std::swap(n, m);
      std::swap(x0, y0);
    }
    // std::cout << KV(n) << KV(m) << KV(x0) << KV(y0) << std::endl;
    if (x0 == 0) {
      if (y0 == 0) {
        xzigzag<1, 1>(n, m, 0, 0);
      } else {
        yzigzag<1, -1>(n - 1, y0 + 1, 0, y0);
        line<0, 1>(m, n - 1, 0);
        yzigzag<-1, -1>(n - 1, m - y0 - 1, n - 2, m - 1);
      }
    } else if (~x0 & 1) {
      line<-1, 0>(x0, x0, y0);
      xzigzag<1, -1>(n - 1, y0, 1, y0 - 1);
      yzigzag<-1, 1>(n - x0 - 1, m - y0, n - 1, y0);
      xzigzag<-1, -1>(x0, m - y0 - 1, x0, m - 1);
      line<0, -1>(m, 0, m - 1);
    } else {
      emplace_back(x0, y0);
      xzigzag<1, -1>(n - x0, y0, x0, y0 - 1);
      xzigzag<-1, 1>(n - x0 - 1, m - y0, n - 1, y0);
      yzigzag<-1, -1>(x0 + 1, m - y0 - 1, x0, m - 1);
      yzigzag<1, -1>(x0, y0 + 1, 0, y0);
    }
    if (xy_swapped) {
      std::swap(n, m);
    }
    for (auto &p : *this) {
      auto [x, y] = p;
      if (xy_swapped) {
        std::swap(x, y);
      }
      if (y_flipped) {
        y = m - 1 - y;
      }
      if (x_flipped) {
        x = n - 1 - x;
      }
      p = std::make_pair(x, y);
    }
  }
};

bool check(int n, int m, int x, int y) {
  Path2D plan(n, m, x, y);
  if (plan.size() != n * m) {
    return false;
  }
  std::cout << KV(plan) << std::endl;
  std::set<Point> points;
  for (auto [x, y] : plan) {
    if (x < 0 || x >= n) {
      return false;
    }
    if (y < 0 || y >= m) {
      return false;
    }
  }
  for (auto &&p : plan) {
    points.insert(p);
  }
  if (points.size() != n * m) {
    return false;
  }
  if (plan[0] != Point{x, y}) {
    return false;
  }
  for (size_t i = 1; i < plan.size(); ++i) {
    if (std::abs(plan[i - 1].first - plan[i].first) +
            std::abs(plan[i - 1].second - plan[i].second) !=
        1) {
      return false;
    }
  }
  return true;
}

std::pair<std::string, Plan> solve_2d(int n, int m, int x0, int y0) {
  if (~n & 1) {
    return {"Cycle", Cycle2D(n, m, x0, y0)};
  }
  if ((x0 + y0) & 1) {
    return {"No", {}};
  }
  return {"Path", Path2D(n, m, x0, y0)};
}

std::pair<std::string, std::vector<int>> solve(int m, const Vec &dim,
                                               const Vec &v) {
  std::vector<int> plan;
  if (m == 1) {
    int v0 = v[0];
    int dim0 = dim[0];
    if (dim0 == 2) {
      if (v0 == 0) {
        return {"Cycle", {1, -1}};
      }
      return {"Cycle", {-1, 1}};
    }
    if (0 < v0 && v0 < dim0 - 1) {
      return {"No", {}};
    }
    for (int i = 0; i < dim0 - 1; ++i) {
      plan.push_back(v0 == 0 ? 1 : -1);
    }
    return {"Path", plan};
  }
  Mapper mapper{m, dim};
  auto [dim_x, dim_y] = mapper.get_dim();
  auto [x0, y0] = mapper.get(v);
  auto [type, plan_2d] = solve_2d(dim_x, dim_y, x0, y0);
  if (type == "No") {
    return {type, {}};
  }
  auto u = mapper.get(plan_2d[0]);
  for (size_t i = 1; i < plan_2d.size(); ++i) {
    auto v = mapper.get(plan_2d[i]);
    int j = 0;
    while (u[j] == v[j]) {
      j++;
    }
    plan.push_back(u[j] < v[j] ? j + 1 : -(j + 1));
    std::swap(u, v);
  }
  return {type, plan};
}

int main() {
  // const int N = 10;
  // for (int n = 3; n < N; n += 2) {
  //   for (int m = 3; m < N; m += 2) {
  //     for (int x = 0; x < n; ++x) {
  //       for (int y = 0; y < m; ++y) {
  //         if (~(x + y) & 1) {
  //           if (!check(n, m, x, y)) {
  //             std::cout << "WA " << KV(n) << KV(m) << KV(x) << KV(y)
  //                       << std::endl;
  //             return -1;
  //           }
  //         }
  //       }
  //     }
  //   }
  // }
  int m;
  scanf("%d", &m);
  Vec dim{}, v{};
  for (int i = 0; i < m; ++i) {
    scanf("%d", &dim[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &v[i]);
    v[i]--;
  }
  auto [type, plan] = solve(m, dim, v);
  puts(type.c_str());
  for (auto &&p : plan) {
    printf("%s %d\n", p > 0 ? "inc" : "dec", std::abs(p));
  }
}