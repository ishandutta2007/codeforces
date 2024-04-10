#include <bits/stdc++.h>
using namespace std;

#define int long long

using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int mod = 1e9+7;
const int ms = 1e6+5;
const int inf = 1e9;

template <class T = int>
class MCMF {
public:
  struct Edge {
    Edge(int a, T b, T c, int d) : to(a), cap(b), cost(c), idx(d) {}
    int to;
    T cap, cost;
    int idx;
  };
  MCMF(int size) {
    n = size;
    edges.resize(n);
    pot.assign(n, 0);
    dist.resize(n);
    visit.assign(n, false);
  }
  pair<T, T> mcmf(int src, int sink) {
    pair<T, T> ans(0, 0);
    if(!SPFA(src, sink)) return ans;
    fixPot();
    // can use dijkstra to speed up depending on the graph
    while(SPFA(src, sink)) {
      auto flow = augment(src, sink);
      ans.first += flow.first;
      ans.second += flow.first * flow.second;
      fixPot();
    }
    return ans;
  }
  void addEdge(int from, int to, T cap, T cost, int idx = 0) {
    edges[from].push_back(list.size());
    list.push_back(Edge(to, cap, cost, idx));
    edges[to].push_back(list.size());
    list.push_back(Edge(from, 0, -cost, 0));
  }
  int n;
  vector<vector<int>> edges;
  vector<Edge> list;
  vector<int> from;
  vector<T> dist, pot;
  vector<bool> visit;

  /*bool dij(int src, int sink) {
    T INF = std::numeric_limits<T>::max();
    dist.assign(n, INF);
    from.assign(n, -1);
    visit.assign(n, false);
    dist[src] = 0;
    for(int i = 0; i < n; i++) {
      int best = -1;
      for(int j = 0; j < n; j++) {
        if(visit[j]) continue;
        if(best == -1 || dist[best] > dist[j]) best = j;
      }
      if(dist[best] >= INF) break;
      visit[best] = true;
      for(auto e : edges[best]) {
        auto ed = list[e];
        if(ed.cap == 0) continue;
        T toDist = dist[best] + ed.cost + pot[best] - pot[ed.to];
        assert(toDist >= dist[best]);
        if(toDist < dist[ed.to]) {
          dist[ed.to] = toDist;
          from[ed.to] = e;
        }
      }
    }
    return dist[sink] < INF;
  }*/

  pair<T, T> augment(int src, int sink) {
    pair<T, T> flow = {list[from[sink]].cap, 0};
    for(int v = sink; v != src; v = list[from[v]^1].to) {
      flow.first = min(flow.first, list[from[v]].cap);
      flow.second += list[from[v]].cost;
    }
    for(int v = sink; v != src; v = list[from[v]^1].to) {
      list[from[v]].cap -= flow.first;
      list[from[v]^1].cap += flow.first;
    }
    return flow;
  }
  queue<int> q;
  bool SPFA(int src, int sink) {
    T INF = numeric_limits<T>::max();
    dist.assign(n, INF);
    from.assign(n, -1);
    q.push(src);
    dist[src] = 0;
    while(!q.empty()) {
      int on = q.front();
      q.pop();
      visit[on] = false;
      for(auto e : edges[on]) {
        auto ed = list[e];
        if(ed.cap == 0) continue;
        T toDist = dist[on] + ed.cost + pot[on] - pot[ed.to];
        if(toDist < dist[ed.to]) {
          dist[ed.to] = toDist;
          from[ed.to] = e;
          if(!visit[ed.to]) {
            visit[ed.to] = true;
            q.push(ed.to);
          }
        }
      }
    }
    return dist[sink] + pot[sink] < 0;
  }
  void fixPot() {
    T INF = numeric_limits<T>::max();
    for(int i = 0; i < n; i++) {
      if(dist[i] < INF) pot[i] += dist[i];
    }
  }
};


void solve() {
  int n1, n2, m, r, b;
  cin >> n1 >> n2 >> m >> r >> b;
  int src = n1+n2+1, snk = n1+n2+2;

  MCMF mcmf(n1+n2+5);  
  string s1, s2;
  cin >> s1 >> s2;
  int tmp = 0;
  for(int i = 0; i < n1; i++) {
    if(s1[i] == 'U') {
      mcmf.addEdge(src, i, inf, 0);
      mcmf.addEdge(i, snk, inf, 0);
    } else if(s1[i] == 'R') {
      mcmf.addEdge(src, i, 1, -inf);
      mcmf.addEdge(src, i, inf, 0);
      tmp += inf;
    } else {
      mcmf.addEdge(i, snk, 1, -inf);
      mcmf.addEdge(i, snk, inf, 0);
      tmp += inf;
    }
  }
  for(int i = 0; i < n2; i++) {
    if(s2[i] == 'U') {
      mcmf.addEdge(src, i+n1, inf, 0);
      mcmf.addEdge(i+n1, snk, inf, 0);
    } else if(s2[i] == 'B') {
      mcmf.addEdge(src, i+n1, 1, -inf);
      mcmf.addEdge(src, i+n1, inf, 0);
      tmp += inf;
    } else {
      mcmf.addEdge(i+n1, snk, 1, -inf);
      mcmf.addEdge(i+n1, snk, inf, 0);
      tmp += inf;
    }
  }
  for(int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    mcmf.addEdge(u, v+n1, 1, r, i);
    mcmf.addEdge(v+n1, u, 1, b, -i);
  }
  // cout << tmp << endl;
  int ans = mcmf.mcmf(src, snk).second;
  if(tmp+ans >= inf/2 ) {
    cout << -1 << '\n';
    return;
  }
  string st;
  for(int i = 1; i<= m; i++) {
    st.push_back('U');
  }
  for(auto ed : mcmf.list) {
    if(ed.cap == 0 && ed.idx) {
      if(ed.idx > 0) st[ed.idx-1] = 'R';
      else st[-ed.idx-1] = 'B';
    }
  }
  cout << ans + tmp << '\n';
  cout << st << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(3);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  // cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}