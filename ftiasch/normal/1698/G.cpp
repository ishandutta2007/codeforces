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
#line 2 "/tmp/tmp-2190974PJS3mOUQ3S3.cpp"

#include <bits/stdc++.h>

using u64 = uint64_t;
using u128 = __int128;

struct Multiplier {
  Multiplier(u64 p_) : m{0}, p{p_} {
    while (p >> m) {
      m++;
    }
  }

  u64 mul(u64 a, u64 b) const {
    u128 r = 0;
    for (int i = 0; i < m; ++i) {
      if (a >> i & 1) {
        r ^= static_cast<u128>(b) << i;
      }
    }
    for (int i = m + m - 2; i >= m; --i) {
      if (r >> i & 1) {
        r ^= static_cast<u128>(p) << (i - (m - 1));
      }
    }
    return r;
  }

  int m;
  u64 p;
};

u64 bsgs(u64 p) {
  Multiplier m(p);
  // x^k = -1 (mod p)
  int half = (m.m + 1) >> 1;
  // x^{2^half * i - j} = -1 (mod p)
  std::map<u64, int> s;
  {
    u64 y = p - 1;
    for (int i = 0; i < 1 << half; ++i) {
      s[y] = i;
      y = m.mul(y, 2);
    }
  }
  u64 g = 2;
  for (int _ = 0; _ < half; ++_) {
    g = m.mul(g, g);
  }
  // x^2 x^2 = x^4
  u64 x = g;
  for (int i = 1; i <= 1 << half; ++i) {
    auto iterator = s.find(x);
    if (iterator != s.end()) {
      return (static_cast<u64>(i) << half) - iterator->second;
    }
    x = m.mul(x, g);
  }
  assert(false);
}

std::pair<u64, u64> solve(const std::string &s_) {
  u64 p = 0;
  for (int i = 0; i < s_.size(); ++i) {
    p |= static_cast<u64>(s_[i] - '0') << i;
  }
  if (!p) {
    return {-1, -1};
  }
  int tz = 1;
  while (~p & 1) {
    tz++;
    p >>= 1;
  }
  if (p == 1) {
    return {tz, tz + 1};
  }
  auto i = bsgs(p);
  return {tz, tz + i};
}

int main() {
  std::string s;
  std::cin >> s;
  auto [a, b] = solve(s);
  if (~a) {
    std::cout << a << " " << b << "\n";
  } else {
    std::cout << "-1\n";
  }
}