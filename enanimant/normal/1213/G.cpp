// August 30, 2019
// https://codeforces.com/contest/1213/problem/G

/*

*/


#include <bits/stdc++.h>

using namespace std;


class UnionFind {
public:
  int n;
  vector<int> p;
  vector<int> sz;

  UnionFind(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    sz.resize(n, 1);
  }

  int find(int x) {
    if (x != p[x]) {
      p[x] = find(p[x]);
    }
    return p[x];
  }

  int size(int x) {
    x = find(x);
    return sz[x];
  }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) {
      return false;
    }
    p[u] = v;
    sz[v] += sz[u];
    return true;
  }
};


const int N = 200000;


struct Edge {
  int from;
  int to;
  int cost;
};


int n, m;
vector<int> g[N];
vector<Edge> edges;

long long n_choose_2(int n) {
  return 1LL * n * (n - 1) / 2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> n >> m;
  vector<int> weights;
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    int id = (int) edges.size();
    g[u].push_back(id);
    g[v].push_back(id);
    edges.push_back({u, v, w});
    weights.push_back(w);
  }
  sort(weights.begin(), weights.end());
  weights.resize(unique(weights.begin(), weights.end()) - weights.begin());
  vector<int> perm(n - 1);
  iota(perm.begin(), perm.end(), 0);
  sort(perm.begin(), perm.end(), [&](int a, int b) {
    return edges[a].cost < edges[b].cost;
  });
  vector<long long> ans(1, 0);
  int last = 0;
  UnionFind uf(n);
  for (int i = 1; i <= n - 1; i++) {
    if (i == n - 1 || edges[perm[i]].cost != edges[perm[i - 1]].cost) {
      long long last_ans = ans.back();
      for (int j = last; j < i; j++) {
        const auto &e = edges[perm[j]];
        int u = e.from, v = e.to;
        int s1 = uf.size(u);
        int s2 = uf.size(v);
        uf.unite(u, v);
        last_ans -= n_choose_2(s1);
        last_ans -= n_choose_2(s2);
        last_ans += n_choose_2(s1 + s2);
      }
      ans.push_back(last_ans);
      last = i;
    }
  }
  assert(ans.size() == weights.size() + 1);
  for (int i = 0; i < m; i++) {
    int q;
    cin >> q;
    int ind = upper_bound(weights.begin(), weights.end(), q) - weights.begin() - 1;
    if (i > 0) {
      cout << ' ';
    }
    cout << ans[ind + 1];
  }
  cout << '\n';


  return 0;
}