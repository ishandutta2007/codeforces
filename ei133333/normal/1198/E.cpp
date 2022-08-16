#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

const int64 infll = (1LL << 62) - 1;
const int64 infll2 = infll / 10;
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


int main() {
  int H, N;
  cin >> H >> N;
  vector< int > x1(N), y1(N), x2(N), y2(N);
  vector< int > xs, ys;
  for(int i = 0; i < N; i++) {
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    --x1[i];
    --y1[i];
    xs.emplace_back(x1[i]);
    xs.emplace_back(x2[i]);
    ys.emplace_back(y1[i]);
    ys.emplace_back(y2[i]);
  }
  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  sort(begin(ys), end(ys));
  ys.erase(unique(begin(ys), end(ys)), end(ys));

  auto sum = make_v< int >(xs.size(), ys.size());
  for(int i = 0; i < N; i++) {
    x1[i] = lower_bound(begin(xs), end(xs), x1[i]) - begin(xs);
    x2[i] = lower_bound(begin(xs), end(xs), x2[i]) - begin(xs);
    y1[i] = lower_bound(begin(ys), end(ys), y1[i]) - begin(ys);
    y2[i] = lower_bound(begin(ys), end(ys), y2[i]) - begin(ys);
    sum[x1[i]][y1[i]]++;
    sum[x2[i]][y2[i]]++;
    sum[x1[i]][y2[i]]--;
    sum[x2[i]][y1[i]]--;
  }


  for(int i = 0; i < xs.size(); i++) {
    for(int j = 1; j < ys.size(); j++) {
      sum[i][j] += sum[i][j - 1];
    }
  }
  for(int i = 0; i < ys.size(); i++) {
    for(int j = 1; j < xs.size(); j++) {
      sum[j][i] += sum[j - 1][i];
    }
  }
  Dinic< int64 > flow(xs.size() + ys.size() + 2);
  int S = xs.size() + ys.size();
  int T = S + 1;
  for(int i = 0; i + 1 < xs.size(); i++) {
    flow.add_edge(S, i, xs[i + 1] - xs[i]);
  }
  for(int i = 0; i + 1 < ys.size(); i++) {
    flow.add_edge(i + xs.size(), T, ys[i + 1] - ys[i]);
  }
  for(int i = 0; i < xs.size(); i++) {
    for(int j = 0; j < ys.size(); j++) {
      if(sum[i][j] > 0) {
        flow.add_edge(i, j + xs.size(), flow.INF);
      }
    }
  }
  cout << flow.max_flow(S, T) << endl;
}