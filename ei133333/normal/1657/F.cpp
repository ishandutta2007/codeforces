#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
//const int mod = 1e9 + 7;
const int mod = 998244353;

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
  for(T &in: v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

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
  for(auto &e: t) fill_v(e, v);
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

#line 2 "graph/others/two-satisfiability.hpp"

#line 2 "graph/connected-components/strongly-connected-components.hpp"

#line 2 "graph/graph-template.hpp"

/**
 * @brief Graph Template()
 */
template< typename T = int >
struct Edge {
  int from, to;
  T cost;
  int idx;

  Edge() = default;

  Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}

  operator int() const { return to; }
};

template< typename T = int >
struct Graph {
  vector< vector< Edge< T > > > g;
  int es;

  Graph() = default;

  explicit Graph(int n) : g(n), es(0) {}

  size_t size() const {
    return g.size();
  }

  void add_directed_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es++);
  }

  void add_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es);
    g[to].emplace_back(to, from, cost, es++);
  }

  void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
    for(int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      a += padding;
      b += padding;
      T c = T(1);
      if(weighted) cin >> c;
      if(directed) add_directed_edge(a, b, c);
      else add_edge(a, b, c);
    }
  }

  inline vector< Edge< T > > &operator[](const int &k) {
    return g[k];
  }

  inline const vector< Edge< T > > &operator[](const int &k) const {
    return g[k];
  }
};

template< typename T = int >
using Edges = vector< Edge< T > >;

#line 2 "math/two-sat.hpp"

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

using namespace std;

namespace TwoSatImpl {
  namespace internal {

    template< class E >
    struct csr {
      vector< int > start;
      vector< E > elist;

      csr(int n, const vector< pair< int, E>> &edges)
          : start(n + 1), elist(edges.size()) {
        for(auto e: edges) {
          start[e.first + 1]++;
        }
        for(int i = 1; i <= n; i++) {
          start[i] += start[i - 1];
        }
        auto counter = start;
        for(auto e: edges) {
          elist[counter[e.first]++] = e.second;
        }
      }
    };

    struct scc_graph {
    public:
      scc_graph(int n) : _n(n) {}

      int num_vertices() { return _n; }

      void add_edge(int from, int to) { edges.push_back({from, {to}}); }

      pair< int, vector< int>> scc_ids() {
        auto g = csr< edge >(_n, edges);
        int now_ord = 0, group_num = 0;
        vector< int > visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
          low[v] = ord[v] = now_ord++;
          visited.push_back(v);
          for(int i = g.start[v]; i < g.start[v + 1]; i++) {
            auto to = g.elist[i].to;
            if(ord[to] == -1) {
              self(self, to);
              low[v] = min(low[v], low[to]);
            } else {
              low[v] = min(low[v], ord[to]);
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
        for(auto &x: ids) {
          x = group_num - 1 - x;
        }
        return {group_num, ids};
      }

      vector< vector< int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        vector< int > counts(group_num);
        for(auto x: ids.second) counts[x]++;
        vector< vector< int>> groups(ids.first);
        for(int i = 0; i < group_num; i++) {
          groups[i].reserve(counts[i]);
        }
        for(int i = 0; i < _n; i++) {
          groups[ids.second[i]].push_back(i);
        }
        return groups;
      }

      void add_node_size(int m) { _n += m; }

      int size() { return _n; }

    private:
      int _n;
      struct edge {
        int to;
      };
      vector< pair< int, edge>> edges;
    };

  }  // namespace internal

  struct two_sat {
  public:
    two_sat() : _n(0), built(false), scc(0) {}

    two_sat(int n) : _n(n), built(false), scc(2 * n) {}

    int add_var() {
      scc.add_node_size(2);
      return _n++;
    }

    // (not i)  ~i 
    void add_clause(int i, int j) {
      i = max(2 * i, -1 - 2 * i);
      j = max(2 * j, -1 - 2 * j);
      assert(0 <= i && i < 2 * _n);
      assert(0 <= j && j < 2 * _n);
      scc.add_edge(i, j ^ 1);
      scc.add_edge(j, i ^ 1);
    }

    void if_then(int i, int j) { add_clause(~i, j); }

    void set_val(int i) { add_clause(i, i); }

    // (not i)  ~i 
    void at_most_one(const vector< int > &nodes) {
      if((int) nodes.size() <= 1) return;
      int cur = ~nodes[0];
      for(int i = 2; i < (int) nodes.size(); i++) {
        int nxt = add_var(), n_i = ~nodes[i];
        add_clause(cur, n_i);
        add_clause(cur, nxt);
        add_clause(n_i, nxt);
        cur = ~nxt;
      }
      add_clause(cur, ~nodes[1]);
    }

    bool satisfiable() {
      _answer.resize(_n);
      built = true;
      auto id = scc.scc_ids().second;
      for(int i = 0; i < _n; i++) {
        if(id[2 * i] == id[2 * i + 1]) {
          _answer.clear();
          return false;
        }
        _answer[i] = id[2 * i] < id[2 * i + 1];
      }
      return true;
    }

    vector< bool > answer() {
      if(!built) satisfiable();
      return _answer;
    }

  private:
    int _n;
    vector< bool > _answer;
    bool built;
    internal::scc_graph scc;
  };

}  // namespace TwoSatImpl

using TwoSatImpl::two_sat;

/**
 * @brief 2-SAT
 * @docs docs/math/two-sat.md
 */


int main() {
  int N, Q;
  cin >> N >> Q;
  Graph<> g(N);
  g.read(N - 1);
  vector< set< int > > ls(N), rs(N);
  vector< vector< int > > lv(Q), rv(Q);
  vector< string > Z(Q);
  for(int i = 0; i < Q; i++) {
    int u, v;
    cin >> u >> v >> Z[i];
    --u, --v;
    if(u == v) {
      lv[i].emplace_back(u);
    } else {
      ls[u].emplace(i);
      rs[v].emplace(i);
    }
  }
  MFP([&](auto dfs, int idx, int par) -> void {
    for(auto &to: g[idx]) {
      if(to == par) continue;
      dfs(to, idx);
      for(auto &p: ls[to]) {
        lv[p].emplace_back(to);
        if(rs[idx].count(p)) {
          lv[p].emplace_back(idx);
          rs[idx].erase(p);
        } else {
          ls[idx].emplace(p);
        }
      }
      ls[to].clear();
    }
    for(auto &to: g[idx]) {
      if(to == par) continue;
      for(auto &p: rs[to]) {
        rv[p].emplace_back(to);
        if(ls[idx].count(p)) {
          rv[p].emplace_back(idx);
          ls[idx].erase(p);
        } else {
          rs[idx].emplace(p);
        }
      }
      rs[to].clear();
    }
  })(0, -1);
  for(int i = 0; i < Q; i++) {
    reverse(begin(rv[i]), end(rv[i]));
    for(auto &p: rv[i]) lv[i].emplace_back(p);
    rv[i].clear();
    assert(lv[i].size() == Z[i].size());
  }
  vector< int > bit(N);
  for(int i = 0; i < Q; i++) {
    for(int j = 0; j < lv[i].size(); j++) {
      bit[lv[i][j]] |= 1 << (Z[i][j] - 'a');
    }
    reverse(begin(lv[i]), end(lv[i]));
    for(int j = 0; j < lv[i].size(); j++) {
      bit[lv[i][j]] |= 1 << (Z[i][j] - 'a');
    }
  }
  vector< int > in(N), out(N);
  auto rev = make_v< int >(N, 26);
  string ords;
  int ptr = 0;
  for(int i = 0; i < N; i++) {
    in[i] = ptr;
    for(int j = 0; j < 26; j++) {
      if((bit[i] >> j) & 1) {
        ords += (char)(j + 'a');
        rev[i][j] = ptr++;
      }
    }
    out[i] = ptr;
  }
  two_sat sat(ptr + Q);
  for(int i = 0; i < N; i++) {
    if(out[i] - in[i] > 1) {
      vector< int > vs(out[i] - in[i]);
      for(int j = in[i]; j < out[i]; j++) vs[j - in[i]] = j;
      sat.at_most_one(vs);
    }
  }
  for(int i = 0; i < Q; i++) {
    for(int j = 0; j < lv[i].size(); j++) {
      sat.add_clause(rev[lv[i][j]][Z[i][j] - 'a'], ~(i + ptr));
    }
    reverse(begin(lv[i]), end(lv[i]));
    for(int j = 0; j < lv[i].size(); j++) {
      sat.add_clause(rev[lv[i][j]][Z[i][j] - 'a'], i + ptr);
    }
  }
  auto ret = sat.answer();
  if(ret.empty()) {
    cout << "NO\n";
  } else {
    string ans;
    for(int i = 0; i < N; i++) {
      char c = 'a';
      for(int j = in[i]; j < out[i]; j++) {
        if(ret[j]) c = ords[j];
      }
      ans += c;
    }
    cout << "YES\n";
    cout << ans << "\n";
  }
}