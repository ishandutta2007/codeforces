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

const int N = 100'000;
const int MOD = 1e9 + 7;

void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int inv(int a) {
  return a == 1 ? 1 : 1LL * (MOD - MOD / a) * inv(MOD % a) % MOD;
}

int n, l[N], r[N], weight[N], size[N], imbalance[N], depth[N];
bool resolved[N];
std::vector<int> tree[N], vertices;

void prepare(int p, int u) {
  vertices.push_back(u);
  size[u] = 1;
  imbalance[u] = 0;
  for (int v : tree[u]) {
    if (v != p && !resolved[v]) {
      prepare(u, v);
      size[u] += size[v];
      imbalance[u] = std::max(imbalance[u], size[v]);
    }
  }
}

void dfs(int p, int u) {
  vertices.push_back(u);
  for (int v : tree[u]) {
    if (v != p && !resolved[v]) {
      depth[v] = depth[u] + 1;
      dfs(u, v);
    }
  }
}

std::vector<std::pair<int, int>> events;

int count(int from, int to) {
  events.clear();
  for (int i = from; i < to; ++i) {
    int u = vertices[i];
    events.emplace_back(l[u], u << 1);
    events.emplace_back(r[u] + 1, u << 1 | 1);
  }
  std::sort(events.begin(), events.end());
  int last = 0, result = 0, sum_w = 0, sum_wd = 0;
  for (auto [x, enc] : events) {
    if (last && last < x) {
      add(result, 1LL * (x - last) * sum_wd % MOD * sum_w % MOD);
    }
    int u = enc >> 1;
    if (enc & 1) {
      add(sum_w, MOD - weight[u]);
      add(sum_wd, MOD - 1LL * weight[u] * depth[u] % MOD);
    } else {
      add(sum_w, weight[u]);
      add(sum_wd, 1LL * weight[u] * depth[u] % MOD);
    }
    last = x;
  }
  return result;
}

int divide(int root) {
  vertices.clear();
  prepare(-1, root);
  {
    std::pair<int, int> candidate{imbalance[root], root};
    for (int v : vertices) {
      candidate = std::min(candidate,
                           {std::max(imbalance[v], size[root] - size[v]), v});
    }
    root = candidate.second;
  }
  resolved[root] = true;
  int result = 0;
  vertices.clear();
  vertices.push_back(root);
  depth[root] = 0;
  for (int v : tree[root]) {
    if (!resolved[v]) {
      int old_sz = vertices.size();
      depth[v] = 1;
      dfs(root, v);
      add(result, MOD - count(old_sz, vertices.size()));
    }
  }
  add(result, count(0, vertices.size()));
  for (int v : tree[root]) {
    if (!resolved[v]) {
      add(result, divide(v));
    }
  }
  return result;
}

int main() {
  scanf("%d", &n);
  int prod = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", l + i, r + i);
    weight[i] = inv(r[i] - l[i] + 1);
    prod = 1LL * prod * (r[i] - l[i] + 1) % MOD;
  }
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  printf("%d\n", static_cast<int>(1LL * prod * divide(0) % MOD));
}