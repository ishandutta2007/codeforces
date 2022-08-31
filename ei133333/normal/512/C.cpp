#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int mod = 1e9 + 7;
// const int mod = 998244353;
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
template< typename flow_t >
struct Dinic {
  const flow_t INF;
  struct edge {
    int to;
    flow_t cap;
    int rev;
    bool isrev;
  };
  vector< vector< edge > > graph;
  vector< int > min_cost, iter;
  Dinic(int V) : INF(numeric_limits< flow_t >::max()), graph(V) {}
  void add_edge(int from, int to, flow_t cap) {
    graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(), false});
    graph[to].emplace_back((edge) {from, 0, (int) graph[from].size() - 1, true});
  }
  bool bfs(int s, int t) {
    min_cost.assign(graph.size(), -1);
    queue< int > que;
    min_cost[s] = 0;
    que.push(s);
    while(!que.empty() && min_cost[t] == -1) {
      int p = que.front();
      que.pop();
      for(auto &e : graph[p]) {
        if(e.cap > 0 && min_cost[e.to] == -1) {
          min_cost[e.to] = min_cost[p] + 1;
          que.push(e.to);
        }
      }
    }
    return min_cost[t] != -1;
  }
  flow_t dfs(int idx, const int t, flow_t flow) {
    if(idx == t) return flow;
    for(int &i = iter[idx]; i < graph[idx].size(); i++) {
      edge &e = graph[idx][i];
      if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
        flow_t d = dfs(e.to, t, min(flow, e.cap));
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
    while(bfs(s, t)) {
      iter.assign(graph.size(), 0);
      flow_t f = 0;
      while((f = dfs(s, t, INF)) > 0) flow += f;
    }
    return flow;
  }
  void output() {
    for(int i = 0; i < graph.size(); i++) {
      for(auto &e : graph[i]) {
        if(e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
      }
    }
  }
};
vector< bool > prime_table(int n) {
  vector< bool > prime(n + 1, true);
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(int i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(int j = i + i; j <= n; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}
int main() {
  int N;
  cin >> N;
  vector< int > A(N);
  cin >> A;
  //      (4)
  // 
  // 2
  auto pd = prime_table(20000);
  Dinic< int > flow(N + 2);
  int S = N;
  int T = N + 1;
  for(int i = 0; i < N; i++) {
    if(A[i] & 1) {
      flow.add_edge(S, i, 2);
      for(int j = 0; j < N; j++) {
        if(pd[A[i] + A[j]]) {
          flow.add_edge(i, j, 1);
        }
      }
    } else {
      flow.add_edge(i, T, 2);
    }
  }
  if(flow.max_flow(S, T) != N) {
    cout << "Impossible\n";
    return 0;
  }
  vector< vector< int > > g(N);
  for(int i = 0; i < N; i++) {
    if(A[i] & 1) {
      for(auto &e : flow.graph[i]) {
        if(e.cap == 0) {
          if (0 <= i and i < N) {
            g[e.to].emplace_back(i);
            g[i].emplace_back(e.to);
          }
        }
      }
    }
  }

  vector< int > used(N);
  vector< vector< int > > ans;
  for(int i = 0; i < N; i++) {
    if(used[i]) continue;
    int cur = g[i][0], pre = i;
    vector< int > tap;
    while(cur != i) {
      used[cur] = true;
      tap.emplace_back(cur + 1);
      int nxt = g[cur][0] == pre ? g[cur][1] : g[cur][0];
      pre = cur;
      cur = nxt;
    }
    tap.emplace_back(i + 1);
    ans.emplace_back(tap);
  }
  cout << ans.size() << endl;
  for(auto& p : ans) {
    cout << p.size() << " " << p << endl;
  }
}