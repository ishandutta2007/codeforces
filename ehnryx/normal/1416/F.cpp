//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

namespace Flow {
  const int N = 1e5 + 7;
  struct Edge { int v, r; int f, c; };
  vector<Edge> adj[N]; int sz[N];
  void init(int n=N) {
    fill(sz,sz+n,0); fill(adj,adj+n,vector<Edge>()); }
  void add_edge(int a, int b, int c=1) {
    adj[a].push_back({b,sz[b]++,0,c});
    adj[b].push_back({a,sz[a]++,0,0}); }

  int L[N], cur[N], Q[N];
  bool bfs(int s, int t) {
    memset(L, INF, sizeof L); memset(cur, 0, sizeof cur);
    int f,b; Q[f=b=0] = s; L[s] = 0;
    while(f<=b && L[t]==INF) { int u = Q[f++];
      for(const Edge& e:adj[u]) if(L[e.v] == INF && e.c > e.f) {
        Q[++b] = e.v; L[e.v] = L[u]+1; } } return L[t] < INF; }
  int dfs(int u, int t, int f) { if (u == t || !f) return f;
    for (int i = cur[u]; i < sz[u]; cur[u] = ++i) { Edge& e = adj[u][i];
      if(e.f<e.c && L[e.v]==L[u]+1) {
        if(int cf = dfs(e.v, t, min(e.c-e.f, f))) {
          e.f += cf; adj[e.v][e.r].f -= cf; return cf; } } } return 0; }
  int flow(int s, int t) {int inf=numeric_limits<int>::max();
    int res = 0;
    while(bfs(s,t))while(int cf=dfs(s,t,inf))res += cf;
    return res;}
}

const vector<int> di = { 0, 0, 1, -1 };
const vector<int> dj = { 1, -1, 0, 0 };

void solve_case() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n+2, vector<int>(m+2, INF));
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      cin >> g[i][j];
    }
  }

  function<int(int,int)> get = [=](int i, int j) {
    return (i-1)*m + (j-1);
  };

  function<pair<int,int>(int)> unget = [=](int v) {
    return make_pair(v/m + 1, v%m + 1);
  };

  Flow::init(n*m + 4);
  const int S = n*m;
  const int T = n*m + 1;
  const int SS = n*m + 2;
  const int TT = n*m + 3;

  int need = 0;
  vector<vector<pair<int,int>>> dir(n+1, vector<pair<int,int>>(m+1));
  vector<vector<int>> ans(n+1, vector<int>(m+1));

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      bool small = false;
      for(int d=0; d<4; d++) {
        int ni = i + di[d];
        int nj = j + dj[d];
        if(g[i][j] > g[ni][nj]) {
          small = true;
          dir[i][j] = make_pair(ni-i, nj-j);
          ans[i][j] = g[i][j] - g[ni][nj];
        }
        if(g[i][j] == g[ni][nj] && (i+j) % 2) {
          Flow::add_edge(get(i,j), get(ni,nj));
        }
      }

      if(small) {
        if((i+j) % 2) {
          Flow::add_edge(S, get(i,j));
        } else {
          Flow::add_edge(get(i,j), T);
        }
      } else {
        need++;
        if((i+j) % 2) {
          Flow::add_edge(S, TT);
          Flow::add_edge(SS, get(i,j));
        } else {
          Flow::add_edge(SS, T);
          Flow::add_edge(get(i,j), TT);
        }
      }
    }
  }

  Flow::add_edge(T, S, INF);
  int maxflow = Flow::flow(SS, TT);
  if(maxflow < need) {
    cout << "NO" << nl;
    return;
  }

  cout << "YES" << nl;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      if((i+j) % 2 == 0) continue;
      int u = get(i,j), v = -1;
      for(const auto& e : Flow::adj[u]) {
        if(e.v < n*m && e.f > 0) {
          v = e.v;
          break;
        }
      }

      if(v != -1) {
        auto [ni, nj] = unget(v);
        dir[i][j] = make_pair(ni-i, nj-j);
        dir[ni][nj] = make_pair(i-ni, j-nj);
        ans[i][j] = g[i][j] - 1;
        ans[ni][nj] = 1;
      }
    }
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      assert(ans[i][j]);
      cout << ans[i][j] << " ";
    }
    cout << nl;
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      if(dir[i][j] == make_pair(0, 1)) cout << 'R';
      else if(dir[i][j] == make_pair(0, -1)) cout << 'L';
      else if(dir[i][j] == make_pair(1, 0)) cout << 'D';
      else if(dir[i][j] == make_pair(-1, 0)) cout << 'U';
      else assert(false);
      cout << ' ';
    }
    cout << nl;
  }
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  int T;
  cin >> T;
  while(T--) {
    solve_case();
  }

  return 0;
}