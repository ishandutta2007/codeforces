#line 1 "/home/ftiasch/Documents/shoka/debug.h"
#include <iostream>
#include <list>
#include <map>
#include <queue>
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

template <typename T, typename S, typename C>
std::ostream &operator<<(std::ostream &out, std::priority_queue<T, S, C> pq) {
  std::vector<T> v;
  while (!pq.empty()) {
    v.push_back(pq.top());
    pq.pop();
  }
  return out << v;
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

int dist(int n, int x, int y) {
  int d = std::abs(x - y);
  return std::min(d, n - d);
}

int clockwise_dist(int n, int x, int y) { return x <= y ? y - x : y + n - x; }

int cyclic_next(int l, int r, int x) { return x + 1 == r ? l : x + 1; }

int cyclic_prev(int l, int r, int x) { return x == l ? r - 1 : x - 1; }

int main() {
  int n, s;
  scanf("%d%d", &n, &s);
  std::vector<std::pair<int, int>> a(n + 1);
  a[0] = {INT_MIN, s - 1};
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i - 1;
  }
  std::sort(a.begin(), a.end());
  std::vector<std::pair<int, int>> cost_first(n + 1), cost_last(n + 1);
  int prel = 0;
  int prer = 1;
  for (int l = 1; l <= n;) {
    int r = l;
    while (r <= n && a[l].first == a[r].first) {
      r++;
    }
    for (int i = l; i < r; ++i) {
      cost_first[i] = {INT_MAX, 0};
      for (int j = prel; j < prer; ++j) {
        cost_first[i] = std::min(
            cost_first[i],
            {std::get<0>(cost_last[j]) + dist(n, a[j].second, a[i].second), j});
      }
    }
    int length = r - l;
    for (int i = l; i < r; ++i) {
      {
        int j = cyclic_prev(l, r, i);
        cost_last[i] = {
            cost_first[j].first + clockwise_dist(n, a[i].second, a[j].second),
            false,
        };
      }
      {
        int j = cyclic_next(l, r, i);
        cost_last[i] = std::min(
            cost_last[i], {
                              cost_first[j].first +
                                  clockwise_dist(n, a[j].second, a[i].second),
                              true,
                          });
      }
    }
    prel = l;
    prer = r;
    l = r;
  }
  //   for (int i = 0; i <= n; ++i) {
  //     std::cout << KV(i) << KV(a[i]) << KV(cost_first[i]) << KV(cost_last[i])
  //               << std::endl;
  //   }
  int v = std::min_element(cost_last.begin() + prel, cost_last.begin() + prer) -
          cost_last.begin();
  printf("%d\n", std::get<0>(cost_last[v]));
  std::vector<int> plan;
  for (int r = n + 1; r > 1;) {
    int l = r - 1;
    while (l > 0 && a[l - 1].first == a[r - 1].first) {
      l--;
    }
    int length = r - l;
    if (length > 1) {
      bool is_clockwise = cost_last[v].second;
      if (is_clockwise) {
        int u = cyclic_next(l, r, v);
        // u->v
        int i = v;
        while (i != u) {
          int j = cyclic_prev(l, r, i);
          plan.push_back(clockwise_dist(n, a[j].second, a[i].second));
          i = j;
        }
        v = u;
      } else {
        int u = cyclic_prev(l, r, v);
        int i = v;
        while (i != u) {
          int j = cyclic_next(l, r, i);
          plan.push_back(-clockwise_dist(n, a[i].second, a[j].second));
          i = j;
        }
        v = u;
      }
    }
    int u = cost_first[v].second;
    int d = dist(n, a[u].second, a[v].second);
    if (clockwise_dist(n, a[u].second, a[v].second) == d) {
      plan.push_back(d);
    } else {
      plan.push_back(-d);
    }
    v = u;
    r = l;
  }
  for (int i = n; i--;) {
    if (plan[i] >= 0) {
      printf("+%d\n", plan[i]);
    } else {
      printf("-%d\n", -plan[i]);
    }
  }
}