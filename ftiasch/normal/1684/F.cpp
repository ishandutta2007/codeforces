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

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::deque<T> &v) {
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
#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

template <typename T = int> T read() {
  T v;
  std::cin >> v;
  return v;
}

template <typename T = int> std::vector<T> read_vector(size_t n) {
  std::vector<T> v(n);
  for (size_t i = 0; i < n; ++i) {
    v[i] = read<T>();
  }
  return v;
}

#define ALL(v) (v).begin(), (v).end()

template <typename T> using Vector2D = std::vector<std::vector<T>>;

template <typename T = int> Vector2D<T> vector_2d(int n, int m) {
  return Vector2D<T>(n, std::vector<T>(m));
}

template <typename T = int> Vector2D<T> vector_2d(int n, int m, T d) {
  return Vector2D<T>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 3 "/tmp/tmp-696031i09h6ssHjer2.cpp"

#line 5 "/tmp/tmp-696031i09h6ssHjer2.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    int m = read();
    auto a = read_vector(n);
    {
      auto values = a;
      std::ranges::sort(values);
      values.erase(std::unique(ALL(values)), values.end());
      for (int i = 0; i < n; ++i) {
        a[i] = std::ranges::lower_bound(values, a[i]) - values.begin();
      }
    }
    std::vector<int> cover(n);
    for (int i = 0; i < m; ++i) {
      int l = read() - 1;
      cover[l] = std::max(cover[l], read());
    }
    for (int i = 1; i < n; ++i) {
      cover[i] = std::max(cover[i - 1], cover[i]);
    }
    int suffix = n;
    std::vector<int> last(n, n);
    while (suffix > 0) {
      int i = suffix - 1;
      if (last[a[i]] < cover[i]) {
        break;
      }
      suffix--;
      last[a[i]] = i;
    }
    int result = n;
    std::vector<std::vector<int>> indices(n);
    for (int i = 0; i < n; ++i) {
      indices[a[i]].push_back(i);
    }
    std::vector<int> minr(n);
    for (int v = 0; v < n; ++v) {
      const auto &is = indices[v];
      int m = is.size();
      for (int i = 0, j = 0; i < m; ++i) {
        j = std::max(i, j);
        while (j + 1 < m && is[j + 1] < cover[is[i]]) {
          j++;
        }
        minr[is[i]] = std::max(minr[is[i]], is[j] + 1);
        // std::cerr << "\t" << KV(is[i]) << KV(is[j]) << std::endl;
      }
    }
    std::ranges::fill(last, -1);
    for (int i = 0, r = 0; i < n; ++i) {
      result = std::min(std::max({i, r, suffix}) - i, result);
      r = std::max(r, minr[i]);
      if (~last[a[i]] && i < cover[last[a[i]]]) {
        break;
      }
      last[a[i]] = i;
    }
    std::cout << result << "\n";
  }
}