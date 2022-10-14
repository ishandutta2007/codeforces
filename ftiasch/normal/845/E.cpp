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

const int N = 500;

using Event = std::tuple<int, int, int>;

bool check(int dim_x, int dim_y, const std::vector<std::pair<int, int>> &p,
           int length) {
//   std::vector<std::vector<char>> grid(dim_x, std::vector<char>(dim_y + 1));
//   for (auto [x, y] : p) {
//     for (int i = std::max(x - length, 0); i <= std::min(x + length, dim_x - 1);
//          ++i) {
//       for (int j = std::max(y - length, 0);
//            j <= std::min(y + length, dim_y - 1); ++j) {
//         grid[i][j] = '*';
//       }
//     }
//   }
//   for (auto row : grid) {
//       std::cout << row.data() << std::endl;
//   }

  int min_x = dim_x;
  int max_x = -1;

  std::vector<Event> events;
  events.reserve((p.size() + 1) << 1);
  events.emplace_back(0, 0, -1);
  events.emplace_back(dim_y, 0, -1);
  for (auto [x, y] : p) {
    events.emplace_back(std::max(y - length, 0), 1, x);
    events.emplace_back(std::min(y + length + 1, dim_y), -1, x);
  }
  std::sort(events.begin(), events.end(), std::greater<Event>());
  auto check_x = [&](int x0) {
    int sum = 0;
    int last_y = dim_y;
    for (auto [y, delta, x] : events) {
      if (!~x || std::abs(x - x0) <= length) {
        if (y < last_y && !sum) {
          min_x = std::min(min_x, x0);
          max_x = std::max(max_x, x0);
          return;
        }
        sum -= delta;
        last_y = y;
      }
    }
  };

  check_x(0);
  check_x(dim_x - 1);
  for (auto [x, _] : p) {
    if (x - length > 0) {
      check_x(x - length - 1);
    }
    if (x + length + 1 < dim_x) {
      check_x(x + length + 1);
    }
  }
  return max_x - min_x <= 2 * length;
}

int main() {
  int dim_x, dim_y, n;
  scanf("%d%d%d", &dim_x, &dim_y, &n);
  std::vector<std::pair<int, int>> p(n), q(n);
  for (int i = 0, x, y; i < n; ++i) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    p[i] = {x, y};
    q[i] = {y, x};
  }
  check(dim_x, dim_y, p, 2);
  int low = 0;
  int high = std::max(dim_x, dim_y) >> 1;
  while (low < high) {
    int middle = (low + high) >> 1;
    if (check(dim_x, dim_y, p, middle) && check(dim_y, dim_x, q, middle)) {
      high = middle;
    } else {
      low = middle + 1;
    }
  }
  printf("%d\n", high);
}