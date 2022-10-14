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

const int N = 500'000;

int a[N], nxt[N], last[N], result[N];
std::vector<int> events[N];
std::pair<int, int> tree[N << 1];

int get_id(int l, int r) { return (l + r) | (l != r); }

void insert(int l, int r, int a, int b, int c) {
  if (b < l || r < a) {
    return;
  }
  if (a <= l && r <= b) {
    int id = get_id(l, r);
    tree[id] = std::max(tree[id], {a, c});
  } else {
    int m = (l + r) >> 1;
    insert(l, m, a, b, c);
    insert(m + 1, r, a, b, c);
  }
}

int query(int l, int r, int t, int k) {
  auto [removet, val] = tree[get_id(l, r)];
  if (t <= removet) {
      return val;
  }
  if (l < r) {
    int m = (l + r) >> 1;
    return k <= m ? query(l, m, t, k) : query(m + 1, r, t, k);
  }
  return 0;
}

int main() {
  int n, q;
  scanf("%d", &n);
  memset(last, -1, sizeof(last));
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    a[i]--;
    int prv = last[a[i]];
    last[a[i]] = i;
    events[prv + 1].push_back(i);
  }
  std::fill(last, last + N, n);
  for (int i = n; i--;) {
    nxt[i] = last[a[i]];
    last[a[i]] = i;
  }
  scanf("%d", &q);
  std::vector<std::tuple<int, int, int>> queries(q);
  for (int i = 0, l, r; i < q; ++i) {
    scanf("%d%d", &l, &r);
    queries[i] = {l - 1, r - 1, i};
  }
  std::sort(queries.begin(), queries.end());
  std::fill(tree, tree + (n << 1), std::make_pair(-1, 0));
  auto nxtq = queries.begin();
  for (int prv = 0; prv < n; ++prv) {
    for (int i : events[prv]) {
      insert(0, n - 1, i, nxt[i] - 1, a[i] + 1);
    }
    while (nxtq != queries.end() && std::get<0>(*nxtq) == prv) {
      auto [l, r, id] = *(nxtq++);
      result[id] = query(0, n - 1, prv, r);
    }
  }
  for (int i = 0; i < q; ++i) {
    printf("%d\n", result[i]);
  }
}