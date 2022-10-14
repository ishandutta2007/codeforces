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
#line 1 "/home/ftiasch/Documents/shoka/free_queue.h"
#include <cstdint>
#include <cstdlib>
#include <numeric>
#line 5 "/home/ftiasch/Documents/shoka/free_queue.h"

struct FreeQueue {
  explicit FreeQueue(int size_) : size(size_), head(0), rear(0), queue(size) {
    std::iota(queue.begin(), queue.end(), 0);
  }

  int allocate() {
    int index = queue[head++];
    if (head == size) {
      head = 0;
    }
    return index;
  }

  void free(int index) {
    queue[rear++] = index;
    if (rear == size) {
      rear = 0;
    }
  }

private:
  int size, head, rear;
  std::vector<int> queue;
};
#line 3 "sol.cpp"
#include <bits/stdc++.h>

const int N = 300'050;
const int C = 26;

int q, op[N];
std::string s[N];
char buffer[N];

FreeQueue pool(N);
int trie[N][C], fail[N], go[N][C], weight[N];

std::vector<int> queue;

struct Aho {
  Aho(std::vector<int> &&indices_) : indices{std::move(indices_)} {
    root = allocate();
    for (int i : indices) {
      length += s[i].size();
      int p = root;
      for (int j = 0; j < s[i].size(); ++j) {
        int c = s[i][j] - 'a';
        if (!~trie[p][c]) {
          trie[p][c] = allocate();
        }
        p = trie[p][c];
      }
      weight[p] += op[i] == 1 ? 1 : -1;
    }
    queue.clear();
    for (int c = 0; c < C; ++c) {
      int v = trie[root][c];
      if (~v) {
        go[root][c] = v;
        fail[v] = root;
        queue.push_back(v);
      } else {
        go[root][c] = root;
      }
    }
    for (int head = 0; head < queue.size(); ++head) {
      int u = queue[head];
      weight[u] += weight[fail[u]];
      for (int c = 0; c < C; ++c) {
        int v = trie[u][c];
        if (~v) {
          go[u][c] = v;
          fail[v] = go[fail[u]][c];
          queue.push_back(v);
        } else {
          go[u][c] = go[fail[u]][c];
        }
      }
    }
  }

  int allocate() {
    int u = pool.allocate();
    weight[u] = 0;
    memset(trie[u], -1, sizeof(trie[u]));
    allocated.push_back(u);
    return u;
  }

  long long count(const std::string &s) const {
    long long result = 0;
    for (int i = 0, p = root; i < s.size(); ++i) {
      p = go[p][s[i] - 'a'];
      result += weight[p];
    }
    return result;
  }

  void free() {
    for (int a : allocated) {
      pool.free(a);
    }
  }

  int root, length = 0;
  std::vector<int> allocated, indices;
};

std::ostream &operator<<(std::ostream &out, const Aho &aho) {
  return out << KV(aho.length) << KV(aho.indices);
}

int main() {
  scanf("%d", &q);
  std::vector<Aho> ahos;
  for (int i = 0; i < q; ++i) {
    scanf("%d%s", op + i, buffer);
    s[i] = buffer;
    if (op[i] == 3) {
      long long result = 0;
      for (const auto &aho : ahos) {
        result += aho.count(s[i]);
      }
      printf("%lld\n", result);
      fflush(stdout);
    } else {
      int length = s[i].length();
      std::vector<int> indices{i};
      while (!ahos.empty() && ahos.back().length < 2 * length) {
        Aho &aho = ahos.back();
        length += aho.length;
        for (int i : aho.indices) {
          indices.push_back(i);
        }
        aho.free();
        ahos.pop_back();
      }
      ahos.push_back(Aho{std::move(indices)});
    }
  }
}