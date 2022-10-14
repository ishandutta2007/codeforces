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
#line 2 "/tmp/tmp-565589AdBQgUb1pmys.cpp"

#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::ios::sync_with_stdio(false); }

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
#line 4 "/tmp/tmp-565589AdBQgUb1pmys.cpp"

int take(std::vector<int> s, int bound) {
  std::ranges::sort(s);
  int result = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] <= bound) {
      bound -= s[i];
      result++;
    }
  }
  return result;
}

bool check(int a, int b, int ab, int ba, const std::string &s) {
  if (std::ranges::count(s, 'A') != a + ab + ba) {
    return false;
  }
  if (std::ranges::count(s, 'B') != b + ab + ba) {
    return false;
  }
  int sum = 0;
  std::vector<int> abs, bas;
  for (int i = 0; i < s.size();) {
    int j = i;
    while (j + 1 < s.size() && s[j] != s[j + 1]) {
      j++;
    }
    sum += (j - i) >> 1;
    if ((j - i) & 1) {
      (s[i] == 'A' ? abs : bas).push_back((j - i + 1) >> 1);
    }
    i = j + 1;
  }
  int abt = take(std::move(abs), ab);
  int bat = take(std::move(bas), ba);
  return sum + abt + bat >= ab + ba;
}

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int a = io.read();
    int b = io.read();
    int ab = io.read();
    int ba = io.read();
    auto s = io.read<std::string>();
    std::cout << (check(a, b, ab, ba, s) ? "YES" : "NO") << "\n";
  }
  // BAB
  // BABAB
  // 2BA
  // 1AB + 1BA
  // 2AB

  // ABABAB
  // 3 AB
  // 2 AB
  // 1 AB + 1 BA
  // 2 BA
}