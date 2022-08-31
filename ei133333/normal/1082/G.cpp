#include<bits/stdc++.h>

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

#line 2 "graph/flow/burn-bury.hpp"

#line 2 "structure/union-find/union-find.hpp"

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

  vector< vector< int > > groups() {
    int n = (int) data.size();
    vector< vector< int > > ret(n);
    for(int i = 0; i < n; i++) {
      ret[find(i)].emplace_back(i);
    }
    ret.erase(remove_if(begin(ret), end(ret), [&](const vector< int > &v) {
      return v.empty();
    }), end(ret));
    return ret;
  }
};

#line 1 "graph/flow/dinic.hpp"

/**
 * @brief Dinic()
 * @docs docs/dinic.md
 */
template< typename flow_t >
struct Dinic {
  const flow_t INF;

  struct edge {
    int to;
    flow_t cap;
    int rev;
    bool isrev;
    int idx;
  };

  vector< vector< edge > > graph;
  vector< int > min_cost, iter;

  explicit Dinic(int V) : INF(numeric_limits< flow_t >::max()), graph(V) {}

  void add_edge(int from, int to, flow_t cap, int idx = -1) {
    graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(), false, idx});
    graph[to].emplace_back((edge) {from, 0, (int) graph[from].size() - 1, true, idx});
  }

  bool build_augment_path(int s, int t) {
    min_cost.assign(graph.size(), -1);
    queue< int > que;
    min_cost[s] = 0;
    que.push(s);
    while(!que.empty() && min_cost[t] == -1) {
      int p = que.front();
      que.pop();
      for(auto &e: graph[p]) {
        if(e.cap > 0 && min_cost[e.to] == -1) {
          min_cost[e.to] = min_cost[p] + 1;
          que.push(e.to);
        }
      }
    }
    return min_cost[t] != -1;
  }

  flow_t find_min_dist_augment_path(int idx, const int t, flow_t flow) {
    if(idx == t) return flow;
    for(int &i = iter[idx]; i < (int) graph[idx].size(); i++) {
      edge &e = graph[idx][i];
      if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
        flow_t d = find_min_dist_augment_path(e.to, t, min(flow, e.cap));
        if(d > 0) {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  flow_t max_flow(int s, int t) {
    flow_t flow = 0;
    while(build_augment_path(s, t)) {
      iter.assign(graph.size(), 0);
      flow_t f;
      while((f = find_min_dist_augment_path(s, t, INF)) > 0) flow += f;
    }
    return flow;
  }

  void output() {
    for(int i = 0; i < graph.size(); i++) {
      for(auto &e: graph[i]) {
        if(e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
      }
    }
  }

  vector< bool > min_cut(int s) {
    vector< bool > used(graph.size());
    queue< int > que;
    que.emplace(s);
    used[s] = true;
    while(not que.empty()) {
      int p = que.front();
      que.pop();
      for(auto &e: graph[p]) {
        if(e.cap > 0 and not used[e.to]) {
          used[e.to] = true;
          que.emplace(e.to);
        }
      }
    }
    return used;
  }
};

#line 5 "graph/flow/burn-bury.hpp"

/**
 * @brief Burn Bury()
 */
template< typename T, bool minimize = true >
struct BurnBury {
private:
  using MaxFlow = Dinic< T >;
  using UF = UnionFind;
  using arr2 = array< T, 2 >;
  using arr4 = array< T, 4 >;

  int n;
  T alpha;
  vector< arr2 > theta;
  vector< map< int, arr4 > > phi;
  map< vector< int >, T > zeta;

public:
  explicit BurnBury(int n) : n{n}, alpha{}, theta(n), phi(n) {}

  void add_cost(T cost) {
    if(not minimize) cost *= -1;
    alpha += cost;
  }

  void add_cost(int x, T cost) {
    if(not minimize) cost *= -1;
    int a = max(~x, x);
    theta[a][x >= 0] += cost;
  }

  void add_cost(int x, int y, T cost) {
    assert(x != y);
    if(not minimize) cost *= -1;
    int a = max(~x, x), b = max(~y, y);
    if(a < b) phi[a][b][((x >= 0) << 1) | (y >= 0)] += cost;
    else phi[b][a][((y >= 0) << 1) | (x >= 0)] += cost;
  }

  void add_cost(vector< int > xs, T cost) {
    assert(not xs.empty());
    sort(xs.begin(), xs.end());
    if(not minimize) cost *= -1;
    zeta[xs] += cost;
  }

  optional< pair< T, vector< bool > > > solve() {
    vector< int > flip(2 * n, -1);
    {
      UF uf(n + n);
      for(int i = 0; i < n; i++) {
        for(auto&[j, cs]: phi[i]) {
          T c = -cs[0] + cs[1] + cs[2] - cs[3];
          if(c < 0) {
            uf.unite(i, j + n);
            uf.unite(i + n, j);
          }
          if(c > 0) {
            uf.unite(i, j);
            uf.unite(i + n, j + n);
          }
        }
      }
      for(auto&[vs, c]: zeta) {
        if(c > 0) return nullopt;
        if(c < 0) {
          for(int i = 1; i < (int) vs.size(); i++) {
            int x = vs[i - 1], y = vs[i];
            int a = max(x, ~x), b = max(y, ~y);
            if((x >= 0) ^ (y >= 0)) {
              uf.unite(a, b + n);
              uf.unite(a + n, b);
            } else {
              uf.unite(a, b);
              uf.unite(a + n, b + n);
            }
          }
        }
      }
      for(int i = 0; i < n; i++) {
        int x = uf.find(i);
        int y = uf.find(i + n);
        if(x == y) return nullopt;
        if(flip[x] < 0) {
          flip[x] = 0;
          flip[y] = 1;
        }
      }
      for(int i = 0; i < n; i++) {
        if(flip[i] < 0) {
          flip[i] = flip[uf.find(i)];
        }
      }
      flip.resize(n);
    }
    {
      for(int i = 0; i < n; i++) {
        for(auto&[j, cs]: phi[i]) {
          if(flip[i]) {
            swap(cs[0], cs[2]);
            swap(cs[1], cs[3]);
          }
          if(flip[j]) {
            swap(cs[0], cs[1]);
            swap(cs[2], cs[3]);
          }
          T c = -cs[0] + cs[1] + cs[2] - cs[3];
          alpha += cs[0];
          theta[i][not flip[i]] += cs[2] - cs[0];
          theta[j][not flip[j]] += cs[3] - cs[2];
          cs[1] = c;
          cs[0] = cs[2] = cs[3] = 0;
        }
      }
    }
    {
      for(int i = 0; i < n; i++) {
        auto &cs = theta[i];
        if(flip[i]) {
          swap(cs[0], cs[1]);
        }
        if(cs[0] <= cs[1]) {
          alpha += cs[0];
          cs[1] -= cs[0];
          cs[0] = 0;
        } else {
          alpha += cs[1];
          cs[0] -= cs[1];
          cs[1] = 0;
        }
      }
    }

    MaxFlow flow(n + 2 + zeta.size());
    int s = n, t = n + 1;
    {
      for(int i = 0; i < n; i++) {
        auto &cs = theta[i];
        if(cs[1] > 0) {
          flow.add_edge(i, t, cs[1]);
        }
        if(cs[0] > 0) {
          flow.add_edge(s, i, cs[0]);
        }
      }
      for(int i = 0; i < n; i++) {
        for(auto&[j, cs]: phi[i]) {
          if(cs[2] > 0) {
            flow.add_edge(i, j, cs[2]);
          }
          if(cs[1] > 0) {
            flow.add_edge(j, i, cs[1]);
          }
        }
      }
      int u = t + 1;
      for(auto&[vs, c]: zeta) {
        if(c < 0) {
          if((vs[0] >= 0) ^ flip[vs[0]]) {
            flow.add_edge(s, u, -c);
            for(auto &p: vs) flow.add_edge(u, max(p, ~p), -c);
          } else {
            for(auto &p: vs) flow.add_edge(max(p, ~p), u, -c);
            flow.add_edge(u, t, -c);
          }
          alpha += c;
          u++;
        }
      }
    }
    T ans = flow.max_flow(s, t) + alpha;
    vector< bool > cut = flow.min_cut(s);
    for(int i = 0; i < n; i++) {
      if(flip[i]) cut[i] = 1 - cut[i];
    }
    cut.resize(n);
    return make_pair(minimize ? ans : -ans, cut);
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  BurnBury< int64, false > flow(N);
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    flow.add_cost(i, -a);
  }
  for(int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    flow.add_cost({a, b}, c);
  }
  cout << flow.solve().value().first << "\n";
}