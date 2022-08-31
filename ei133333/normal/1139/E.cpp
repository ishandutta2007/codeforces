#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const int64 infll = (1LL << 61) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;

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

template< typename flow_t >
struct FordFulkerson {
  struct edge {
    int to;
    flow_t cap;
    int rev;
    bool isrev;
  };

  vector< vector< edge > > graph;
  vector< int > used;
  const flow_t INF;
  int timestamp;

  FordFulkerson(int n) : INF(numeric_limits< flow_t >::max()), timestamp(0) {
    graph.resize(n);
    used.assign(n, -1);
  }

  void add_edge(int from, int to, flow_t cap) {
    graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(), false});
    graph[to].emplace_back((edge) {from, 0, (int) graph[from].size() - 1, true});
  }

  flow_t dfs(int idx, const int t, flow_t flow) {
    if(idx == t) return flow;
    used[idx] = timestamp;
    for(auto &e : graph[idx]) {
      if(e.cap > 0 && used[e.to] != timestamp) {
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
    ++timestamp;
    for(flow_t f; (f = dfs(s, t, INF)) > 0; timestamp++) {
      flow += f;
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


bool ex[5000][5000];

int main() {
  int N, M, D;
  cin >> N >> M;
  vector< int > P(N), C(N);
  cin >> P >> C;
  for(auto &p : C) --p;
  cin >> D;
  vector< int > K(D);
  cin >> K;
  for(auto &p : K) --p;

  vector< int > used(N);
  for(auto &p : K) used[p] = true;


  FordFulkerson< int > flow(M + 5003 + 2);
  int S = M + 5003, T = M + 5004;
  for(int i = 0; i < M; i++) {
    flow.add_edge(S, i, 1);
  }
  for(int i = 0; i < N; i++) {
    if(used[i]) continue;
    if(!exchange(ex[C[i]][P[i]], true)) {
      flow.add_edge(C[i], M + P[i], 1);
    }
  }
  flow.add_edge(M, T, 1);

  int mex = 0;
  auto arg = [&]() {
    while(flow.max_flow(S, T) == 1) {
      ++mex;
      flow.add_edge(M + mex, T, 1);
    }
  };

  vector< int > ans(D);
  for(int i = D - 1; i >= 0; i--) {
    arg();
    ans[i] = mex;
    if(!exchange(ex[C[K[i]]][P[K[i]]], true)) {
      flow.add_edge(C[K[i]], M + P[K[i]], 1);
    }
  }

  for(auto &p : ans) cout << p << endl;
}