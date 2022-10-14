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

const int N = 300'000;

int lim, head[N], to[N << 1], len[N], nxt[N << 1], back[N];
long long dist[N];

template <typename T>
using PQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;

std::vector<int> tree[N], plan;

void pick(int u) {
  for (int e : tree[u]) {
    int v = to[e];
    if (static_cast<int>(plan.size()) < lim) {
      plan.push_back(e);
      pick(v);
    }
  }
}

int main() {
  int n, m;
  scanf("%d%d%d", &n, &m, &lim);
  memset(head, -1, sizeof(head));
  for (int i = 0; i < m << 1; ++i) {
    scanf("%d", to + i);
    to[i]--;
    if (i & 1) {
      scanf("%d", len + (i >> 1));
    }
  }
  for (int i = 0; i < m << 1; ++i) {
    nxt[i] = head[to[i ^ 1]];
    head[to[i ^ 1]] = i;
  }
  std::fill(dist, dist + n, N * 1'000'000'000LL);
  dist[0] = 0;
  PQ<std::pair<long long, int>> pq;
  pq.emplace(0, 0);
  while (!pq.empty()) {
    auto [dist_u, u] = pq.top();
    pq.pop();
    if (dist_u == dist[u]) {
      for (int iterator = head[u]; ~iterator; iterator = nxt[iterator]) {
        int v = to[iterator];
        int w = len[iterator >> 1];
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          back[v] = iterator;
          pq.emplace(dist[v], v);
        }
      }
    }
  }
  for (int i = 1; i < n; ++i) {
    auto e = back[i];
    tree[to[e ^ 1]].push_back(e);
  }
  pick(0);
  printf("%d\n", static_cast<int>(plan.size()));
  for (int e : plan) {
      printf("%d ", (e >> 1) + 1);
  }
  puts("");
}