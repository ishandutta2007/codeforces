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

using Long = long long;

Long solve(int n, const std::vector<Long> &cnt, int x, Long target) {
  Long below_cost = target;
  Long below_cnt = 0;
  for (int i = 0; i <= x; ++i) {
    below_cost -= cnt[i];
    below_cnt += cnt[i] << i;
  }
  if (below_cost <= 0) {
    return 0;
  }
  Long extra_cost = 0;
  for (int i = x + 1; i < n; ++i) {
    Long c = cnt[i];
    Long add = 1LL << (i - x);

    Long m = std::min(below_cost / add, c);
    below_cost -= add * m;
    extra_cost += (add - 1) * m;
    below_cnt += m << i;

    if (m < c && below_cnt < target) {
      // std::cerr << KV(i) << KV(below_cnt) << KV(below_cost) << std::endl;
      assert(below_cnt + (1LL << i) > target);
      Long c = 1;
      for (int j = i; j >= x; --j) {
        Long add = 1LL << (j - x);
        Long m = below_cost / add;
        below_cost -= add * m;
        extra_cost += (add - 1) * m;
        below_cnt += m << j;
        if (below_cnt < target) {
          extra_cost++;
        } else {
          break;
        }
      }
      break;
    }
  }

  return below_cnt < target ? -1 : below_cost + extra_cost;
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  std::vector<Long> cnt(n);
  for (int i = 0, c; i < n; ++i) {
    scanf("%d", &c);
    cnt[i] = c;
  }
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int pos, val;
      scanf("%d%d", &pos, &val);
      cnt[pos] = val;
    } else {
      int x;
      Long k;
      scanf("%d%lld", &x, &k);
      printf("%lld\n", solve(n, cnt, x, k));
    }
  }
}