#include <bits/stdc++.h>
using namespace std;

//%:include "utility/fast_input.h"
//%:include "utility/output.h"

// START %:include "tree/rooted_tree.h"

#include <vector>

struct rooted_tree {
  std::vector<std::vector<int>> adj;
  std::vector<int> parent, depth, subtree, start, preorder, in, out;
  int root;

  rooted_tree(const std::vector<std::vector<int>>& adj_list, int r): adj(adj_list),
    parent(size(), -1), depth(size()), subtree(size()), start(size()),
    in(size()), out(size()), root(r) {
    preorder.reserve(size());
    build(root, -1, 0);
  }
  rooted_tree(std::vector<std::vector<int>>&& adj_list, int r): adj(move(adj_list)),
    parent(size(), -1), depth(size()), subtree(size()), start(size()),
    in(size()), out(size()), root(r) {
    preorder.reserve(size());
    build(root, -1, 0);
  }

  const std::vector<int>& operator [] (int i) const { return adj[i]; }
  size_t size() const { return adj.size(); }

  bool is_ancestor_of(int anc, int v, bool strict = true) const {
    if (strict) return in[anc] < in[v] && out[anc] > out[v];
    else return in[anc] <= in[v] && out[anc] >= out[v];
  }

private:
  int build(int u, int par, int idx) {
    in[u] = idx++;
    start[u] = (int)preorder.size();
    preorder.push_back(u);
    parent[u] = par;
    subtree[u] = 1;
    if (par != -1) {
      depth[u] = depth[par] + 1;
      std::vector<int>::iterator it = find(adj[u].begin(), adj[u].end(), par);
      if (it != adj[u].end()) {
        adj[u].erase(it);
      }
    }
    for (int v : adj[u]) {
      idx = build(v, u, idx);
      subtree[u] += subtree[v];
    }
    out[u] = idx++;
    return idx;
  }
};

// END %:include "tree/rooted_tree.h"
// START %:include "graph/two_sat.h"

// START #include "strongly_connected.h"

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

// END #include "strongly_connected.h"

struct two_sat {
  int n;
  vector<bool> truth;
  vector<vector<int>> adj;
  two_sat(int _n): n(_n), truth(n), adj(2*n) {}
  void add_edge(int a, int b) { adj[a].push_back(b); }
  bool operator [] (int i) const { return truth[i]; }
  bool solve() {
    strongly_connected scc(adj);
    for (int i = 0; i < n; i++) {
      if (scc[2*i] == scc[2*i + 1]) return false;
      truth[i] = (scc[2*i] < scc[2*i + 1]);
    }
    return true;
  }

  void or_clause(int a, int b) {
    add_edge(a^1, b);
    add_edge(b^1, a);
  }
  void implies(int a, int b) {
    add_edge(a, b);
    add_edge(b^1, a^1);
  }
  void iff(int a, int b) {
    implies(a, b);
    implies(b, a);
  }
  void or_clause(int a, bool a_truth, int b, bool b_truth) {
    or_clause(2*a + !a_truth, 2*b + !b_truth);
  }
  void implies(int a, bool a_truth, int b, bool b_truth) {
    implies(2*a + !a_truth, 2*b + !b_truth);
  }
  void iff(int a, bool a_truth, int b, bool b_truth) {
    iff(2*a + !a_truth, 2*b + !b_truth);
  }
};

// END %:include "graph/two_sat.h"

using ll = long long;
using ld = long double;

constexpr char nl = '\n';
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());


//#define MULTI_TEST
void solve_main([[maybe_unused]] int testnum, [[maybe_unused]] auto& cin) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n+1);
  for(int i=1; i<n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  rooted_tree g(move(adj), 1);

  vector<pair<char, char>> options(g.size());
  two_sat sat(g.size() + m);
  auto word = [n=g.size()](int i) -> int {
    return n + i;
  };

  for(int i=0; i<m; i++) {
    int a, b; string s;
    cin >> a >> b >> s;

    vector<int> path(size(s));
    int front = 0;
    int back = size(s);
    if(g.depth[a] < g.depth[b]) swap(a, b);
    while(g.depth[a] > g.depth[b]) {
      path[front++] = a;
      a = g.parent[a];
    }
    while(a != b) {
      path[front++] = a;
      path[--back] = b;
      a = g.parent[a];
      b = g.parent[b];
    }
    path[front++] = a;
    assert(front == back);

    for(int j=0; j<size(s); j++) {
      if(!options[path[j]].first) {
        options[path[j]] = pair(s[j], s[size(s)-1 - j]);
      }
      auto [x, y] = options[path[j]];
      if(s[j] != x) {
        sat.implies(path[j], true, word(i), false);
      }
      if(s[j] != y) {
        sat.implies(path[j], false, word(i), false);
      }
      if(s[size(s)-1 - j] != x) {
        sat.implies(path[j], true, word(i), true);
      }
      if(s[size(s)-1 - j] != y) {
        sat.implies(path[j], false, word(i), true);
      }
    }
  }

  if (!sat.solve()) {
    cout << "NO" << nl;
  } else {
    cout << "YES" << nl;
    for(int i=1; i<=n; i++) {
      char ans = (sat[i] ? options[i].first : options[i].second);
      cout << (ans ? ans : 'a');
    }
    cout << nl;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#ifdef USING_FAST_INPUT
  fast_input cin;
#endif

  int T = 1;
#ifdef MULTI_TEST
  cin >> T;
#endif
  for(int testnum=1; testnum<=T; testnum++) {
    solve_main(testnum, cin);
  }

  return 0;
}