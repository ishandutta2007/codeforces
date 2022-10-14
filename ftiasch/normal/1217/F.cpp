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

const int N = 200'000;

struct PersistentDSU {
  void init(int n) {
    std::iota(parent, parent + n, 0);
    std::fill(size, size + n, 1);
  }

  int find(int u) const {
    while (parent[u] != u) {
      u = parent[u];
    }
    return u;
  }

  void merge(const std::pair<int, int> &e) {
    auto [u, v] = e;
    u = find(u);
    v = find(v);
    if (u != v) {
      if (size[u] < size[v]) {
        std::swap(u, v);
      }
      size[u] += size[v];
      parent[v] = u;
      history[len++] = {u, v};
    }
  }

  int checkpoint() const { return len; }

  void rollback(int to) {
    while (len > to) {
      auto [u, v] = history[--len];
      size[u] -= size[v];
      parent[v] = v;
    }
  }

  int parent[N], size[N], len = 0;
  std::pair<int, int> history[N];
} dsu;

std::vector<std::pair<int, int>> edges;

std::pair<int, int> make_edge(int x, int y) {
  return x < y ? std::make_pair(x, y) : std::make_pair(y, x);
}

std::tuple<int, int, int, int> changes[N];

using Queries = std::vector<std::tuple<int, int, int>>;
Queries queries;
Queries::iterator curq;

std::vector<char> result;

int last = 0;

int mark_clock, mark[N << 1];

void flip(int e) { mark[e] = mark[e] == mark_clock ? 0 : mark_clock; }

struct Dan : public std::vector<int> {};

std::ostream &operator<<(std::ostream &out, const Dan &d) {
  std::vector<std::pair<int, int>> buf;
  for (int e : d) {
    buf.push_back(edges[e]);
  }
  return out << buf;
}

Dan dans[20], buf;

// dan - dangling
void solve(int n, int l, int r, int level) {
  //   std::cout << KV(l) << KV(r) << KV(dan) << std::endl;
  if (l + 1 == r) {
    if (last) {
      auto [x, y, id0, id1] = changes[l];
      changes[l] = {x, y, id1, id0};
    }
    int f = std::get<2>(changes[l]);
    bool f_removed = false;
    int cp = dsu.checkpoint();
    for (int e : dans[level]) {
      if (e == f) {
        f_removed = true;
      } else {
        dsu.merge(edges[e]);
      }
    }
    if (!f_removed) {
      dsu.merge(edges[f]);
    }
    while (curq != queries.end() && std::get<0>(*curq) == l + 1) {
      auto [t, x, y] = *(curq++);
      if (last) {
        x = (x + 1) % n;
        y = (y + 1) % n;
      }
      last = dsu.find(x) == dsu.find(y);
      //   std::cout << KV(x) << KV(y) << KV(last) << std::endl;
      result.push_back("01"[last]);
    }
    dsu.rollback(cp);
  } else {
    int m = (l + r) >> 1;
    mark_clock++;
    for (int i = l; i < r; ++i) {
      auto [x, y, id0, id1] = changes[i];
      mark[id0] = mark[id1] = mark_clock;
    }
    int cp = dsu.checkpoint();
    Dan &left_dan = dans[level + 1];
    left_dan.clear();
    for (int e : dans[level]) {
      if (mark[e] != mark_clock) {
        // untouched in [l, r)
        dsu.merge(edges[e]);
      } else {
        left_dan.push_back(e);
      }
    }
    assert(left_dan.size() <= 2 * (r - l));
    solve(n, l, m, level + 1);
    mark_clock++;
    for (int e : left_dan) {
      flip(e);
    }
    for (int i = l; i < m; ++i) {
      flip(std::get<2>(changes[i]));
    }
    buf.clear();
    for (int e : left_dan) {
      if (mark[e] == mark_clock) {
        mark[e] = 0;
        buf.push_back(e);
      }
    }
    for (int i = l; i < m; ++i) {
      int e = std::get<2>(changes[i]);
      if (mark[e] == mark_clock) {
        mark[e] = 0;
        buf.push_back(e);
      }
    }
    std::swap(buf, dans[level + 1]);
    solve(n, m, r, level + 1);
    dsu.rollback(cp);
  }
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  int m = 0;
  for (int i = 0, op, x, y; i < q; ++i) {
    scanf("%d%d%d", &op, &x, &y);
    x--;
    y--;
    if (op == 1) {
      changes[m++] = {x, y, 0, 0};
      edges.push_back(make_edge(x, y));
      edges.push_back(make_edge((x + 1) % n, (y + 1) % n));
    } else {
      queries.emplace_back(m, x, y);
    }
  }
  std::sort(edges.begin(), edges.end());
  edges.erase(std::unique(edges.begin(), edges.end()), edges.end());
  for (int i = 0; i < m; ++i) {
    auto [x, y, _, __] = changes[i];
    int id[2];
    for (int t = 0; t < 2; ++t) {
      id[t] = std::lower_bound(edges.begin(), edges.end(),
                               make_edge((x + t) % n, (y + t) % n)) -
              edges.begin();
    }
    changes[i] = {x, y, id[0], id[1]};
  }
  curq = queries.begin();
  while (curq != queries.end() && std::get<0>(*curq) == 0) {
    auto [t, x, y] = *(curq++);
    result.push_back('0');
  }
  if (m > 0) {
    dsu.init(n);
    solve(n, 0, m, 0);
  }
  result.push_back('\0');
  puts(result.data());
}