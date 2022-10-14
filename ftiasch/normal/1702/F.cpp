#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
  }

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

  template <typename T> std::ostream &operator<<(const T &o) {
    return std::cout << o;
  }
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-8821617r0zDk1160PN.cpp"

#line 4 "/tmp/tmp-8821617r0zDk1160PN.cpp"

struct TrieNode {
  TrieNode() : count{0, 0}, child{-1, -1} {}

  std::array<int, 2> count, child;
};

struct Trie : std::vector<TrieNode> {
  Trie() : std::vector<TrieNode>(1) {}

  // result, a, b
  std::tuple<int, int, int> solve(int u) {
    int result = 0;
    std::array<int, 2> count = (*this)[u].count;
    for (int c = 0; c < 2; ++c) {
      int v = (*this)[u].child[c];
      if (~v) {
        auto [rr, aa, bb] = solve(v);
        if (!~rr || (bb && c == 1)) {
          return {-1, 0, 0};
        }
        count[0] += aa;
        count[1] += bb;
        result += rr + aa + bb;
      }
    }
    int c = std::min(count[0], count[1]);
    return {result, count[0] - c, count[1] - c};
  }
};

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    Trie trie;
    trie.reserve(60 * n);
    for (int t = 2; t--;) {
      for (int i = 0; i < n; ++i) {
        int a = io.read();
        int u = 0;
        for (int k = 30; k--;) {
          int c = a >> k & 1;
          if (!u && !c) {
            continue;
          }
          if (!~trie[u].child[c]) {
            trie[u].child[c] = trie.size();
            trie.emplace_back();
          }
          u = trie[u].child[c];
        }
        trie[u].count[t]++;
      }
    }
    std::cout << (std::get<0>(trie.solve(0)) == -1 ? "NO" : "YES") << "\n";
  }
}