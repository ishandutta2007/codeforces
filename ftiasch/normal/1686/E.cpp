#line 2 "/home/ftiasch/Documents/shoka/sparse_table.h"

#include <algorithm>
#include <cstring>
#include <vector>

template <typename T> struct SparseTable {
  SparseTable(const std::vector<T> &value)
      : n(value.size()), l(log2n(n)), log(n), table(l, std::vector<T>(n)) {
    log[0] = 0;
    for (int i = 1; i < n; ++i) {
      log[i] = log[i - 1] + (1 << (log[i - 1] + 1) < i + 1);
    }
    table[0] = value;
    for (int i = 1; i < l; ++i) {
      for (int j = 0; j + (1 << i) <= n; ++j) {
        table[i][j] =
            std::min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  T operator()(int l, int r) const {
    const int lv = log[r - l];
    return std::min(table[lv][l], table[lv][r - (1 << lv) + 1]);
  }

private:
  static constexpr int log2n(int n) {
    return n > 1 ? 32 - __builtin_clz(n - 1) : 1;
  }

  int n, l;
  std::vector<int> log;
  std::vector<std::vector<T>> table;
};
#line 2 "/tmp/tmp-784387fCovL25arT5B.cpp"

#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::ios::sync_with_stdio(false); }

  template <typename T = int> T read() const {
    T v;
    std::cin >> v;
    return v;
  }

  template <typename T = int> std::vector<T> read_vector(size_t n) const {
    std::vector<T> v(n);
    for (size_t i = 0; i < n; ++i) {
      v[i] = read<T>();
    }
    return v;
  }
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 4 "/tmp/tmp-784387fCovL25arT5B.cpp"

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
#line 6 "/tmp/tmp-784387fCovL25arT5B.cpp"

std::vector<std::pair<int, int>> solve(int n, const std::string &s) {
  std::vector<int> ss((n << 1) + 1); // suffix sum
  for (int i = n << 1; i--;) {
    ss[i] = (s[i] == '(' ? 1 : -1) + ss[i + 1];
  }
  if (*std::ranges::max_element(ss) <= 0) {
    return {};
  }
  int max_l = 0;
  while (ss[max_l + 1] <= 0) {
    max_l++;
  }
  int min_r = n << 1;
  while (ss[min_r - 1] <= 0) {
    min_r--;
  }
  std::vector<int> left(n << 1), right(n << 1);
  for (int i = 0; i < n << 1; ++i) {
    left[i] = i - 1;
    while (~left[i] && ss[left[i]] >= ss[i]) {
      left[i] = left[left[i]];
    }
  }
  for (int i = n << 1; i--;) {
    right[i] = i + 1;
    while (right[i] < (n << 1) && ss[right[i]] >= ss[i]) {
      right[i] = right[right[i]];
    }
  }
  std::vector<std::pair<int, int>> indexed_ss((n << 1) + 1);
  for (int i = 0; i <= n << 1; ++i) {
    indexed_ss[i] = {ss[i], i};
  }
  SparseTable rmq(indexed_ss);
  for (int i = 0; i < n << 1; ++i) {
    if (left[i] + 1 <= max_l && min_r <= right[i]) {
      auto [ss_l, l] = rmq(left[i] + 1, std::min(max_l, i));
      auto [ss_r, r] = rmq(std::max(i + 1, min_r), right[i]);
      if (ss[i] >= ss_l + ss_r) {
        return {{l, r}};
      }
    }
  }
  int i_min = std::ranges::min_element(ss) - ss.begin();
  return {{0, i_min}, {i_min, n << 1}};
}

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    auto s = io.read<std::string>();
    auto plan = solve(n, s);
    std::cout << plan.size() << "\n";
    for (auto [l, r] : plan) {
      std::cout << l + 1 << " " << r << "\n";
    }
  }
}