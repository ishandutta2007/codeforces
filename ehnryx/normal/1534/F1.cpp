#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

// START #include "../../../lca/graph/strongly_connected.h"

template <bool build_dag, typename = void>
struct scc_dag_base {
  scc_dag_base(int) {}
};

template <bool build_dag>
struct scc_dag_base<build_dag, enable_if_t<build_dag>> {
  vector<int> remap;
  vector<vector<int>> group;
  vector<int> indegree;
  vector<vector<int>> dag;
  scc_dag_base(size_t n): remap(n) { group.reserve(n); }
};

template <bool build_dag = false, bool remove_dups = true>
struct strongly_connected : scc_dag_base<build_dag> {
  using base = scc_dag_base<build_dag>;
  int components;
  vector<int> idx, low, scc;
  int operator [] (int i) const { return scc[i]; }
  int size() const { return components; }

  strongly_connected(const vector<vector<int>>& graph):
    base(graph.size()), components(0),
    idx(graph.size(), -1), low(graph.size(), -1), scc(graph.size(), -1) {
    for (int i = 0, j = 0; i < (int)graph.size(); i++) {
      if (low[i] == -1) {
        dfs(graph, i, j);
      }
    }
    if constexpr (build_dag) {
      base::dag.resize(size());
      base::indegree.resize(size());
      for (int i = 0; i < size(); i++) {
        for (int u : base::group[i]) {
          for (int v : graph[u]) {
            if (scc[v] == i) continue;
            base::dag[i].push_back(scc[v]);
          }
        }
        if constexpr (remove_dups) {
          sort(begin(base::dag[i]), end(base::dag[i]));
          base::dag[i].resize(
              unique(begin(base::dag[i]), end(base::dag[i])) - begin(base::dag[i]));
        }
        for (int j : base::dag[i]) {
          base::indegree[j] += 1;
        }
      }
    }
  }

  void dfs(const vector<vector<int>>& graph, int u, int& i) {
    static stack<int> stk;
    stk.push(u);
    idx[u] = low[u] = i++;
    for (int v : graph[u]) {
      if (low[v] == -1) dfs(graph, v, i);
      if (scc[v] == -1) low[u] = min(low[u], low[v]);
    }
    if (idx[u] == low[u]) {
      if constexpr (build_dag) base::group.emplace_back();
      for (int v = -1; v != u; ) {
        v = stk.top();
        stk.pop();
        scc[v] = components;
        if constexpr (build_dag) {
          base::remap[v] = (int)base::group.back().size();
          base::group.back().push_back(v);
        }
      }
      components++;
    }
  }
};

// END #include "../../../lca/graph/strongly_connected.h"

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

  int n, m;
  cin >> n >> m;
  vector remap(n, vector<int>(m));
  vector g(n, vector<char>(m));
  int rid = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> g[i][j];
      if(g[i][j] == '#') {
        remap[i][j] = rid++;
      } else {
        g[i][j] = 0;
      }
    }
  }
  vector<int> want(m);
  for(int i=0; i<m; i++) {
    cin >> want[i];
  }

  vector<vector<int>> adj(rid);
  vector<int> last(m, -1);
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(!g[i][j]) continue;
      if(i>0 && g[i-1][j]) {
        adj[remap[i-1][j]].push_back(remap[i][j]);
        adj[remap[i][j]].push_back(remap[i-1][j]);
      }
      if(j>0 && g[i][j-1]) {
        adj[remap[i][j-1]].push_back(remap[i][j]);
        adj[remap[i][j]].push_back(remap[i][j-1]);
      }
      if(last[j] != -1) {
        adj[last[j]].push_back(remap[i][j]);
      }
      if(j>0 && last[j-1] != -1) {
        adj[last[j-1]].push_back(remap[i][j]);
      }
      if(j+1<m && last[j+1] != -1) {
        adj[last[j+1]].push_back(remap[i][j]);
      }
      last[j] = remap[i][j];
    }
  }

  strongly_connected<true, false> scc(adj);
  int ans = 0;
  for(int in : scc.indegree) {
    ans += (in == 0);
  }
  cout << ans << nl;

  return 0;
}