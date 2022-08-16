#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
//const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;


struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) {
  if(b < 0)b *= -1;
  return a > b && (a = b, true);
}

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e : t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

/**
 * @brief Union-Find
 * @docs docs/union-find.md
 */
struct UnionFind {
  vector< int > data;

  UnionFind() = default;

  explicit UnionFind(size_t sz) : data(sz, -1) {}

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return data[k] = find(data[k]);
  }

  int size(int k) {
    return -data[find(k)];
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

namespace atcoder {
  namespace internal {

    template< class E >
    struct csr {
      std::vector< int > start;
      std::vector< E > elist;

      explicit csr(int n, const std::vector< std::pair< int, E>> &edges)
          : start(n + 1), elist(edges.size()) {
        for(auto e : edges) {
          start[e.first + 1]++;
        }
        for(int i = 1; i <= n; i++) {
          start[i] += start[i - 1];
        }
        auto counter = start;
        for(auto e : edges) {
          elist[counter[e.first]++] = e.second;
        }
      }
    };

  }  // namespace internal

}  // namespace atcoder



namespace atcoder {
  namespace internal {

    // Reference:
    // R. Tarjan,
    // Depth-First Search and Linear Graph Algorithms
    struct scc_graph {
    public:
      explicit scc_graph(int n) : _n(n) {}

      int num_vertices() { return _n; }

      void add_edge(int from, int to) { edges.push_back({from, {to}}); }

      // @return pair of (# of scc, scc id)
      std::pair< int, std::vector< int>> scc_ids() {
        auto g = csr< edge >(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector< int > visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
          low[v] = ord[v] = now_ord++;
          visited.push_back(v);
          for(int i = g.start[v]; i < g.start[v + 1]; i++) {
            auto to = g.elist[i].to;
            if(ord[to] == -1) {
              self(self, to);
              low[v] = std::min(low[v], low[to]);
            } else {
              low[v] = std::min(low[v], ord[to]);
            }
          }
          if(low[v] == ord[v]) {
            while(true) {
              int u = visited.back();
              visited.pop_back();
              ord[u] = _n;
              ids[u] = group_num;
              if(u == v) break;
            }
            group_num++;
          }
        };
        for(int i = 0; i < _n; i++) {
          if(ord[i] == -1) dfs(dfs, i);
        }
        for(auto &x : ids) {
          x = group_num - 1 - x;
        }
        return {group_num, ids};
      }

      std::vector< std::vector< int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector< int > counts(group_num);
        for(auto x : ids.second) counts[x]++;
        std::vector< std::vector< int>> groups(ids.first);
        for(int i = 0; i < group_num; i++) {
          groups[i].reserve(counts[i]);
        }
        for(int i = 0; i < _n; i++) {
          groups[ids.second[i]].push_back(i);
        }
        return groups;
      }

    private:
      int _n;
      struct edge {
        int to;
      };
      std::vector< std::pair< int, edge>> edges;
    };

  }  // namespace internal

}  // namespace atcoder

namespace atcoder {

  struct scc_graph {
  public:
    scc_graph() : internal(0) {}

    explicit scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
      int n = internal.num_vertices();
      assert(0 <= from && from < n);
      assert(0 <= to && to < n);
      internal.add_edge(from, to);
    }

    std::vector< std::vector< int>> scc() { return internal.scc(); }

  private:
    internal::scc_graph internal;
  };

}  // namespace atcoder



int main() {
  int H, W;
  cin >> H >> W;
  vector< string > S(H);
  cin >> S;
  vector< int > A(W);
  cin >> A;
  UnionFind uf(H * W);
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(S[i][j] == '#') {
        if(i and S[i - 1][j] == '#') {
          uf.unite(i * W + j, i * W + j - W);
        }
        if(j and S[i][j - 1] == '#') {
          uf.unite(i * W + j, i * W + j - 1);
        }
      }
    }
  }
  vector< int > id(H * W);
  int ptr = 0;
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(S[i][j] == '#') {
        if(uf.find(i * W + j) == i * W + j) {
          id[i * W + j] = ptr++;
        }
      }
    }
  }

  if(ptr == 0) {
    cout << 0 << "\n";
    return 0;
  }

  atcoder::internal::scc_graph g(ptr);

  struct V {
    int top1, top2;

    V() : top1(-1), top2(-1) {}

    V(int a, int b) : top1(a), top2(b) {}

    V operator+(int k) const {
      if(top1 == -1) {
        return {k, -1};
      }
      if(top1 == k) {
        return *this;
      }
      return {k, top1};
    }
  };

  auto add = [&](int x, int y) {
    if(x != y) {
      g.add_edge(x, y);
    }
  };

  for(int i = 0; i < W; i++) {
    V x, y, z;
    for(int j = H - 1; j >= 0; j--) {
      if(i > 0 and S[j][i - 1] == '#') {
        int look = id[uf.find(j * W + i - 1)];
        x = x + look;
      }
      if(i + 1 < W and S[j][i + 1] == '#') {
        int look = id[uf.find(j * W + i + 1)];
        y = y + look;
      }
      if(S[j][i] == '#') {
        int look = id[uf.find(j * W + i)];
        z = z + look;
        if(~z.top2) {
          add(z.top1, z.top2);
        }
        if(~x.top1) {
          add(z.top1, x.top1);
        }
        if(~x.top2) {
          add(z.top1, x.top2);
        }
        if(~y.top1) {
          add(z.top1, y.top1);
        }
        if(~y.top2) {
          add(z.top1, y.top2);
        }
      }
    }
  }
  auto p = g.scc();
  vector< int > rev(ptr);
  for(int i = 0; i < p.size(); i++) {
    for(auto &q : p[i]) rev[q] = i;
  }


  int N = (int) p.size();
  vector< int > deg(N);
  int ans = 0;

  auto check = [&](int x, int y) {
    if(x != y) {
      y=rev[y];
      x=rev[x];
      if(x!=y)++deg[y];
    }
  };



  for(int i = 0; i < W; i++) {
    V x, y, z;
    for(int j = H - 1; j >= 0; j--) {
      if(i > 0 and S[j][i - 1] == '#') {
        int look = id[uf.find(j * W + i - 1)];
        x = x + look;
      }
      if(i + 1 < W and S[j][i + 1] == '#') {
        int look = id[uf.find(j * W + i + 1)];
        y = y + look;
      }
      if(S[j][i] == '#') {
        int look = id[uf.find(j * W + i)];
        z = z + look;
        if(~z.top2) {
          check(z.top1, z.top2);
        }
        if(~x.top1) {
          check(z.top1, x.top1);
        }
        if(~x.top2) {
          check(z.top1, x.top2);
        }
        if(~y.top1) {
          check(z.top1, y.top1);
        }
        if(~y.top2) {
          check(z.top1, y.top2);
        }
      }
    }
  }

  for(int i = 0; i < N; i++) {
    if(deg[i] == 0) {
      ++ans;
    }
  }
  cout << ans << "\n";
}