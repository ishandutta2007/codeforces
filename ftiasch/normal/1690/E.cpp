#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <iostream>
#include <vector>
#include <queue>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::cin.sync_with_stdio(false); }

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
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-11630KfnJg0pTyLGd.cpp"

#line 2 "/home/ftiasch/Documents/shoka/debug.h"
#include <list>
#include <map>
#line 5 "/home/ftiasch/Documents/shoka/debug.h"
#include <set>
#include <utility>
#line 8 "/home/ftiasch/Documents/shoka/debug.h"

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
#line 4 "/tmp/tmp-11630KfnJg0pTyLGd.cpp"

#include <bits/stdc++.h>

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    int k = io.read();
    Long result = 0;
    std::vector<int> r;
    r.reserve(n);
    for (int a : io.read_vector(n)) {
      result += a / k;
      r.push_back(a % k);
    }
    std::ranges::sort(r);
    std::cerr << KV(result) << KV(r) << std::endl;
    for (int i = n, j = 0; i--;) {
      while (j < i && r[j] + r[i] < k) {
        j++;
      }
      if (j >= i) {
        break;
      }
      result++;
      j++;
    }
    std::cout << result << "\n";
  }
}