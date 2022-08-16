#include<bits/stdc++.h>

using namespace std;

#define int long long

#define rep(i, n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector< int > vint;
typedef pair< int, int > pint;
typedef vector< pint > vpint;

template< typename A, typename B >
inline void chmin(A &a, B b) { if(a > b)a = b; }

template< typename A, typename B >
inline void chmax(A &a, B b) { if(a < b)a = b; }

template< class A, class B >
ostream &operator<<(ostream &ost, const pair< A, B > &p) {
  ost << "{" << p.first << "," << p.second << "}";
  return ost;
}

template< class T >
ostream &operator<<(ostream &ost, const vector< T > &v) {
  ost << "{";
  for(int i = 0; i < v.size(); i++) {
    if(i)ost << ",";
    ost << v[i];
  }
  ost << "}";
  return ost;
}

struct PrimalDual {
  using F=long long;
  const F INF = 1ll << 60;

  struct Edge {
    int to;
    F cap, cost;
    int rev;

    Edge(int to, F cap, F cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}
  };

  int n;
  vector< vector< Edge>> G;
  vector< F > h;
  vector< int > prevv, preve;
  vector< F > dist;

  PrimalDual(int n) : n(n), G(n), h(n), dist(n), prevv(n, -1), preve(n, -1) {}

  void addEdge(int from, int to, F cap, F cost) {
    G[from].push_back(Edge(to, cap, cost, G[to].size()));
    G[to].push_back(Edge(from, 0, -cost, G[from].size() - 1));
  }

  vector< pair< F, F > > solve(int s, int t) {
    F cur = 0;
    priority_queue< pair< F, int >, vector< pair< F, int>>, greater< pair< F, int>> > que;
    vector< pair< F, F > > ret;
    for(int z = 1;; z++) {
      fill(dist.begin(), dist.end(), INF);
      dist[s] = 0;
      que.emplace(0, s);
      while(que.size()) {
        F d;
        int v;
        tie(d, v) = que.top();
        que.pop();
        if(dist[v] < d)continue;
        for(int i = 0; i < G[v].size(); i++) {
          Edge &e = G[v][i];
          F nd = dist[v] + e.cost + h[v] - h[e.to];
          if(e.cap > 0 && dist[e.to] > nd) {
            dist[e.to] = nd;
            prevv[e.to] = v;
            preve[e.to] = i;
            que.emplace(nd, e.to);
          }
        }
      }
      if(dist[t] == INF) break;
      for(int v = 0; v < n; v++) h[v] += dist[v];
      cur += h[t];
      for(int v = t; v != s; v = prevv[v]) {
        Edge &e = G[prevv[v]][preve[v]];
        e.cap -= 1;
        G[v][e.rev].cap += 1;
      }
      // cur+P/z
      ret.emplace_back(cur, z);
    }
    return ret;
  }
};


template< typename T, bool isMin >
struct ConvexHullTrickAddMonotone {
#define F first
#define S second
  using P = pair< T, T >;
  deque< P > H;

  ConvexHullTrickAddMonotone() = default;

  bool empty() const { return H.empty(); }

  void clear() { H.clear(); }

  inline int sgn(T x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }

  using D = long double;

  inline bool check(const P &a, const P &b, const P &c) {
    if(b.S == a.S || c.S == b.S)
      return sgn(b.F - a.F) * sgn(c.S - b.S) >= sgn(c.F - b.F) * sgn(b.S - a.S);

    //return (b.F-a.F)*(c.S-b.S) >= (b.S-a.S)*(c.F-b.F);
    return
        D(b.F - a.F) * sgn(c.S - b.S) / D(abs(b.S - a.S)) >=
        D(c.F - b.F) * sgn(b.S - a.S) / D(abs(c.S - b.S));
  }

  void add(T a, T b) {
    if(!isMin) a *= -1, b *= -1;
    P line(a, b);
    if(empty()) {
      H.emplace_front(line);
      return;
    }
    if(H.front().F <= a) {
      if(H.front().F == a) {
        if(H.front().S <= b) return;
        H.pop_front();
      }
      while(H.size() >= 2 && check(line, H.front(), H[1])) H.pop_front();
      H.emplace_front(line);
    } else {
      assert(a <= H.back().F);
      if(H.back().F == a) {
        if(H.back().S <= b) return;
        H.pop_back();
      }
      while(H.size() >= 2 && check(H[H.size() - 2], H.back(), line)) H.pop_back();
      H.emplace_back(line);
    }
  }

  inline T get_y(const P &a, const T &x) {
    return a.F * x + a.S;
  }

  T query(T x) {
    assert(!empty());
    int l = -1, r = H.size() - 1;
    while(l + 1 < r) {
      int m = (l + r) >> 1;
      if(get_y(H[m], x) >= get_y(H[m + 1], x)) l = m;
      else r = m;
    }
    if(isMin) return get_y(H[r], x);
    return -get_y(H[r], x);
  }

  T query_monotone_inc(T x) {
    assert(!empty());
    while(H.size() >= 2 && get_y(H.front(), x) >= get_y(H[1], x)) H.pop_front();
    if(isMin) return get_y(H.front(), x);
    return -get_y(H.front(), x);
  }

  T query_monotone_dec(T x) {
    assert(!empty());
    while(H.size() >= 2 && get_y(H.back(), x) >= get_y(H[H.size() - 2], x)) H.pop_back();
    if(isMin) return get_y(H.back(), x);
    return -get_y(H.back(), x);
  }

#undef F
#undef S
};

signed main() {
  int N, M;
  cin >> N >> M;
  PrimalDual pd(N);
  rep(i, M) {
    int u, v, d;
    cin >> u >> v >> d;
    u--;
    v--;
    pd.addEdge(u, v, 1, d);
  }
  auto tap = pd.solve(0, N - 1);

  // (tap[i].first+x)/tap[i].second
  // tap[i].first/tap[i].second + x * (1 / tap[i].second)
  // CHT

  ConvexHullTrickAddMonotone< long double, true > cht;
  vector< pair< long double, long double > > lines;
  for(auto &p : tap) {
    lines.emplace_back((long double) 1.0 / p.second, (long double) p.first / p.second);
  }
  sort(begin(lines), end(lines));
  for(auto &p : lines) cht.add(p.first, p.second);
  int Q;
  cin >> Q;
  vector< pair< int, int > > val;
  for(int i = 0; i < Q; i++) {
    int x;
    cin >> x;
    val.emplace_back(x, i);
  }
  sort(begin(val), end(val));
  vector< double > ans(Q);
  for(int i = 0; i < Q; i++) {
    ans[val[i].second] = cht.query_monotone_inc(val[i].first);
  }
  cout << fixed << setprecision(10);
  for(int i = 0; i < Q; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}