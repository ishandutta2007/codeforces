#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,tune=native")

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

constexpr char nl = '\n';
constexpr ll INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr ll MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

const int N = 2e5 + 1;
vector<int> adj[N];
vector<pair<int,int>> cents[N];
vector<int> values[N];
bool vis[N];
int sz[N];

int get_dists(int s, int u, int p, int d) {
  sz[u] = 0; // reset size
  cents[u].emplace_back(s, d);
  int res = 1;
  for(int v : adj[u]) {
    if(v == p || vis[v]) continue;
    res = max(res, 1 + get_dists(s, v, u, d + 1));
  }
  return res;
}

int dfs(int u, int p, vector<int>& seen) {
  seen.push_back(u);
  for(int v : adj[u]) {
    if(v == p || vis[v]) continue;
    sz[u] += dfs(v, u, seen);
  }
  return sz[u] += 1;
}

int centroid(int u) {
  vector<int> seen;
  int s = dfs(u, 0, seen);
  assert(s == size(seen));
  for(int v : seen) {
    if(2*sz[v] < s) continue;
    bool bad = false;
    for(int w : adj[v]) {
      if(vis[w]) continue;
      bad |= (sz[v] > sz[w] && 2*sz[w] > s);
    }
    if(bad) continue;
    int max_dist = get_dists(v, v, 0, 0);
    values[v].resize(max_dist);
    return v;
  }
  assert(false);
}

void decompose(int u) {
  int c = centroid(u);
  vis[c] = true;
  for(int v : adj[c]) {
    if(vis[v]) continue;
    decompose(v);
  }
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  int n;
  cin >> n;
  for(int i=1; i<n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  decompose(1);

  int k;
  cin >> k;
  queue<int> bfs;
  vector<int> dist(n+1, -1);
  for(int i=0; i<k; i++) {
    int s;
    cin >> s;
    bfs.push(s);
    dist[s] = 0;
  }
  while(!empty(bfs)) {
    int u = bfs.front();
    bfs.pop();
    for(int v : adj[u]) {
      if(dist[v] != -1) continue;
      dist[v] = dist[u] + 1;
      bfs.push(v);
    }
  }

  for(int i=1; i<=n; i++) {
    for(auto [c, d] : cents[i]) {
      if(d > dist[i] - 1) continue;
      int rem = dist[i] - 1 - d;
      rem = min(rem, (int)size(values[c]) - 1);
      values[c][rem] = max(values[c][rem], dist[i]);
    }
  }

  for(int i=1; i<=n; i++) {
    for(int j=(int)size(values[i])-2; j>=0; j--) {
      values[i][j] = max(values[i][j], values[i][j+1]);
    }
  }

  for(int i=1; i<=n; i++) {
    int ans = 0;
    for(auto [c, d] : cents[i]) {
      d = min(d, (int)size(values[c]) - 1);
      ans = max(ans, values[c][d]);
    }
    cout << ans << " ";
  }
  cout << nl;

  return 0;
}