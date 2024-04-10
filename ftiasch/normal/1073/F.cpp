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

using P = std::pair<int, int>;
using PP = std::pair<P, P>;

P operator+(const P &p, const P &q) {
  return {p.first + q.first, p.second + q.second};
}

const int N = 200'000;

int n, parent[N];
std::vector<int> tree[N], order;

P down1[N], up[N];

PP down2[N];

void prepare(int u) {
  order.push_back(u);
  int p = parent[u];
  if (~p) {
    tree[u].erase(std::find(tree[u].begin(), tree[u].end(), p));
  }
  for (int v : tree[u]) {
    parent[v] = u;
    prepare(v);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  parent[0] = -1;
  prepare(0);
//   std::cout << KV(order) << std::endl;
  std::pair<P, PP> result{{-n, -n}, {{-1, -1}, {-1, -1}}};
  for (int i = n; i--;) {
    int u = order[i];
    down2[u] = {{-n, -n}, {-1, -1}};
    for (int v : tree[u]) {
      auto [down2_sofar, plan_sofar] = down2[u];
      auto [down2_v, plan_v] = down2[v];
      if (~plan_sofar.first) {
        result = std::max(
            result, {down2_sofar + (down2_v + P{1, 0}), {plan_sofar, plan_v}});
      }
      down2[u] = std::max(down2[u], {down2_v + P{1, 0}, plan_v});
    }
    down1[u] = {-n, -1};
    for (int v : tree[u]) {
      {
        auto [down1_sofar, plan_sofar] = down1[u];
        auto [down1_v, plan_v] = down1[v];
        if (~plan_sofar) {
          down2[u] = std::max(down2[u], {{0, down1_sofar + (1 + down1_v)},
                                         {plan_sofar, plan_v}});
        }
      }
      down1[u] = std::max(down1[u], down1[v] + P{1, 0});
    }
    down1[u] = std::max(down1[u], {0, u});
    // std::cout << KV(u) << KV(down1[u]) << KV(down2[u]) << std::endl;
  }
  up[0] = {-n, -1};
  for (int i = 0; i < n; ++i) {
    int u = order[i];
    // std::cout << KV(u) << KV(up[u]) << std::endl;
    std::pair<P, int> best[3]{{up[u], -1}, {{-n, -1}, -1}};
    for (int v : tree[u]) {
      std::pair<P, int> c{{down1[v].first + 1, down1[v].second}, v};
      if (c > best[0]) {
        best[2] = best[1];

        best[1] = best[0];
        best[0] = c;
      } else if (c > best[1]) {
        best[2] = best[1];
        best[1] = c;
      } else if (c > best[2]) {
        best[2] = c;
      }
    }
    for (int v : tree[u]) {
      {
        auto [stat, plan] = best[best[0].second == v].first;
        up[v] = {stat + 1, plan};
      }
      {
        int i0 = best[0].second == v;
        int i1 = i0 + 1;
        if (best[i1].second == v) {
          i1++;
        }
        auto [best0, best0_plan] = best[i0].first;
        auto [best1, best1_plan] = best[i1].first;
        if (~best1_plan) {
          auto [down2_v, down2_plan] = down2[v];
          result =
              std::max(result, {{down2_v + P{1, 0} + P{0, best0} + P{0, best1}},
                                {down2_plan, {best0_plan, best1_plan}}});
        }
      }
    }
  }
  auto [p, q] = result.second;
  printf("%d %d\n", p.first + 1, q.first + 1);
  printf("%d %d\n", p.second + 1, q.second + 1);
}