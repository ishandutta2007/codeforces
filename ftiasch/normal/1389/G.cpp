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

const int N = 300'000;

bool vspec[N], used[N];
int vprofit[N], ecost[N], to[N << 1], head[N], next[N << 1], bcc_cnt, bcc_id[N],
    depth[N], low[N], cspec[N], subtree_spec[N];
long long cprofit[N], down[N], up[N];

std::vector<int> stack;

void prepare(int u) {
  stack.push_back(u);
  for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
    if (!used[iterator >> 1]) {
      used[iterator >> 1] = true;
      int v = to[iterator];
      if (~depth[v]) {
        low[u] = std::min(low[u], depth[v]);
      } else {
        depth[v] = low[v] = depth[u] + 1;
        prepare(v);
        low[u] = std::min(low[u], low[v]);
      }
    }
  }
  if (depth[u] == low[u]) {
    int v;
    do {
      v = stack.back();
      stack.pop_back();
      bcc_id[v] = bcc_cnt;
    } while (v != u);
    bcc_cnt++;
  }
}

std::vector<std::pair<int, int>> tree[N];

int main() {
  int n, m, l;
  scanf("%d%d%d", &n, &m, &l);
  for (int i = 0; i < l; ++i) {
    int v;
    scanf("%d", &v);
    vspec[v - 1] = true;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", vprofit + i);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", ecost + i);
  }
  for (int i = 0; i < m << 1; ++i) {
    scanf("%d", to + i);
    to[i]--;
  }
  memset(head, -1, sizeof(int) * n);
  for (int i = 0; i < m << 1; ++i) {
    next[i] = head[to[i ^ 1]];
    head[to[i ^ 1]] = i;
  }
  memset(depth, -1, sizeof(int) * n);
  depth[0] = low[0] = 0;
  prepare(0);
  for (int i = 0; i < n; ++i) {
    cspec[bcc_id[i]] += vspec[i];
    cprofit[bcc_id[i]] += vprofit[i];
  }
  for (int i = 0; i < m << 1; ++i) {
    int a = to[i];
    int b = to[i ^ 1];
    if (bcc_id[a] > bcc_id[b]) {
      tree[bcc_id[a]].emplace_back(bcc_id[b], ecost[i >> 1]);
    }
  }
  auto get_down = [&](int v, int w) -> long long {
    if (subtree_spec[v] == 0 || subtree_spec[v] == l) {
      return down[v];
    }
    return std::max(down[v] - w, 0LL);
  };
  for (int u = 0; u < bcc_cnt; ++u) {
    subtree_spec[u] = cspec[u];
    down[u] = cprofit[u];
    for (auto [v, w] : tree[u]) {
      subtree_spec[u] += subtree_spec[v];

      down[u] += get_down(v, w);
    }
  }
  //   std::cerr << KV(bcc_cnt) << std::vector<int>(bcc_id, bcc_id + n) <<
  //   std::endl; std::cerr << std::vector<int>(down, down + bcc_cnt) <<
  //   std::endl;
  up[bcc_cnt - 1] = 0;
  for (int u = bcc_cnt; u--;) {
    long long sum_down = 0;
    for (auto [v, w] : tree[u]) {
      sum_down += get_down(v, w);
    }
    for (auto [v, w] : tree[u]) {
      long long other_down = sum_down - get_down(v, w);
      long long dp_u = up[u] + cprofit[u] + other_down;
      int outside_spec = l - subtree_spec[v];
      up[v] = outside_spec == 0 || outside_spec == l ? dp_u
                                                     : std::max(dp_u - w, 0LL);
    }
  }
  for (int i = 0; i < n; ++i) {
    int u = bcc_id[i];
    printf("%lld%c", down[u] + up[u], " \n"[i + 1 == n]);
  }
}