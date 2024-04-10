#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 50'000;
const int M = 1'000'000;
const int Q = 5'000;

const int B = 224;
const int L = 20;

struct Node {
  void clear() {
    min = INT_MAX;
    child[0] = child[1] = -1;
  }

  int min, child[2];
};

template <size_t N> struct Trie {
  void clear() {
    size = 0;
    trie[size++].clear();
  }

  void add(int x, int a) {
    int p = 0;
    trie[p].min = std::min(trie[p].min, a);
    for (int i = L; i--;) {
      int c = x >> i & 1;
      if (!~trie[p].child[c]) {
        trie[trie[p].child[c] = size++].clear();
      }
      p = trie[p].child[c];
      trie[p].min = std::min(trie[p].min, a);
    }
  }

  int ask(int x, int a) const {
    if (trie[0].min > a) {
      return 0;
    }
    int result = 0;
    for (int i = L, p = 0; i--;) {
      int c = (x >> i & 1) ^ 1;
      if (~trie[p].child[c] && trie[trie[p].child[c]].min <= a) {
        result ^= 1 << i;
        p = trie[p].child[c];
      } else {
        p = trie[p].child[c ^ 1];
      }
    }
    return result;
  }

  int size;
  Node trie[1 + N * L];
};

int prefix_sum[M + 1];

template <size_t N> struct DualTrie {
  void clear() {
    lt.clear();
    gt.clear();
  }

  void add(int a) {
    lt.add(prefix_sum[a - 1], a);
    gt.add(prefix_sum[a], -a);
  }

  int ask(int a) const {
    return std::max(lt.ask(prefix_sum[a], a), gt.ask(prefix_sum[a - 1], -a));
  }

  Trie<N> lt, gt;
};

int n, q, a[N], block_size, result[Q];
std::vector<std::tuple<int, int, int>> queries[B];

DualTrie<B> small;
DualTrie<N> large;

int main() {
  for (int i = 1; i <= M; ++i) {
    prefix_sum[i] = prefix_sum[i - 1] ^ i;
  }
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  block_size = std::sqrt(n) + 1;
  for (int i = 0, l, r; i < q; ++i) {
    scanf("%d%d", &l, &r);
    l--;
    r--;
    if (r - l + 1 <= block_size) {
      small.clear();
      result[i] = 0;
      for (int j = l; j <= r; ++j) {
        small.add(a[j]);
        result[i] = std::max(result[i], small.ask(a[j]));
      }
    } else {
      queries[l / block_size].emplace_back(r, l, i);
    }
  }
  for (int block_id = 0, block_start = 0; block_start < n;
       ++block_id, block_start += block_size) {
    auto &qs = queries[block_id];
    std::sort(qs.begin(), qs.end());
    int large_r = block_start + block_size - 1;
    int large_result = 0;
    large.clear();
    for (auto [r, l, i] : qs) {
      assert(large_r <= r);
      while (large_r < r) {
        large.add(a[++large_r]);
        // std::cerr << "add " << a[large_r] << " to large" << std::endl;
        large_result = std::max(large_result, large.ask(a[large_r]));
      }
      small.clear();
      result[i] = large_result;
      for (int j = block_start + block_size - 1; j >= l; --j) {
        small.add(a[j]);
        // std::cerr << "add " << a[j] << " to small" << std::endl;
        result[i] = std::max(result[i], small.ask(a[j]));
        result[i] = std::max(result[i], large.ask(a[j]));
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    printf("%d\n", result[i]);
  }
}