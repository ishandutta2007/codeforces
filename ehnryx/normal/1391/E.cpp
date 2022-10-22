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

const int N = 5e5 + 1;
int depth[N], layer[N], par[N];
vector<int> adj[N];
bool vis[N];

void dfs(int u, int p) {
  depth[u] = depth[p] + 1;
  par[u] = p;
  vis[u] = true;
  for(int v : adj[u]) {
    if(v == p || vis[v]) continue;
    dfs(v, u);
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
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
      adj[i].clear();
      layer[i] = 0;
      vis[i] = false;
    }
    for(int i=0; i<m; i++) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    dfs(1, 0);

    vector<pair<int,int>> pairs;
    for(int i=1; i<=n; i++) {
      if(depth[i] >= (n+1)/2) {
        cout << "PATH" << nl;
        cout << depth[i] << nl;
        while(i) {
          cout << i << " ";
          i = par[i];
        }
        cout << nl;
        pairs.clear();
        break;
      }
      if(layer[depth[i]]) {
        pairs.emplace_back(i, layer[depth[i]]);
        layer[depth[i]] = 0;
      } else {
        layer[depth[i]] = i;
      }
    }

    if(!pairs.empty()) {
      cout << "PAIRING" << nl;
      cout << pairs.size() << nl;
      for(auto [a, b] : pairs) {
        cout << a << " " << b << nl;
      }
    }
  }

  return 0;
}