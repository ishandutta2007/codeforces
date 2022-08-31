#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};

struct StronglyConnectedComponents {
  vector< vector< int > > gg, rg;
  vector< pair< int, int > > edges;
  vector< int > comp, order, used;

  StronglyConnectedComponents(size_t v) : gg(v), rg(v), comp(v, -1), used(v, 0) {}

  void add_edge(int x, int y) {
    gg[x].push_back(y);
    rg[y].push_back(x);
    edges.emplace_back(x, y);
  }

  int operator[](int k) {
    return (comp[k]);
  }

  void dfs(int idx) {
    if(used[idx]) return;
    used[idx] = true;
    for(int to : gg[idx]) dfs(to);
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt) {
    if(comp[idx] != -1) return;
    comp[idx] = cnt;
    for(int to : rg[idx]) rdfs(to, cnt);
  }

  void build(vector< vector< int > > &t) {
    for(int i = 0; i < gg.size(); i++) dfs(i);
    reverse(begin(order), end(order));
    int ptr = 0;
    for(int i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;

    t.resize(ptr);
    set< pair< int, int > > connect;
    for(auto &e : edges) {
      int x = comp[e.first], y = comp[e.second];
      if(x == y) continue;
      if(connect.count({x, y})) continue;
      t[x].push_back(y);
      connect.emplace(x, y);
    }
  }
};

int main() {
  int N, M;
  int T[1000][1000];

  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    string x;
    cin >> x;
    for(int j = 0; j < M; j++) {
      if(x[j] == '<') T[i][j] = 1;
      else if(x[j] == '=') T[i][j] = 0;
      else T[i][j] = -1;
    }
  }


  UnionFind uf(N + M);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(T[i][j] == 0) {
        uf.unite(i, N + j);
      }
    }
  }
  vector< int > belong[2000];


  for(int i = 0; i < N; i++) {
    belong[uf.find(i)].emplace_back(i);
  }
  int rot = 0;
  vector< int > rev;
  for(int i = 0; i < N + M; i++) {
    if(uf.find(i) == i) {
      rev.emplace_back(i);
    }
    bool same = true;
    for(int j = 1; j < belong[i].size(); j++) {
      for(int k = 0; k < M; k++) {
        same &= T[belong[i][j - 1]][k] == T[belong[i][j]][k];
      }
    }
    if(!same) {
      cout << "No" << endl;
      return 0;
    }
  }
  vector< int > dict(N + M);
  for(int i = 0; i < rev.size(); i++) dict[rev[i]] = i;

  StronglyConnectedComponents scc(rev.size());
  for(int i = 0; i < N + M; i++) {
    if(uf.find(i) == i && belong[i].size()) {
      int p = belong[i][0];
      for(int j = 0; j < M; j++) {
        if(T[p][j] == 0) continue;
        if(T[p][j] == 1) scc.add_edge(dict[uf.find(p)], dict[uf.find(j + N)]);
        else scc.add_edge(dict[uf.find(j + N)], dict[uf.find(p)]);
      }
    }
  }
  vector< vector< int > > t;
  scc.build(t);

  if(t.size() == rev.size()) {
    cout << "Yes" << endl;
    vector< int > ans(N + M);
    for(int i = 0; i < N; i++) ans[i] = scc[dict[uf.find(i)]];
    for(int i = 0; i < M; i++) ans[i + N] = scc[dict[uf.find(i + N)]];
    // 
    int tap[2000] = {};
    for(int i = 0; i < N; i++) {
      tap[ans[i]] |= 1;
    }
    for(int i = 0; i < M; i++) {
      tap[ans[i + N]] |= 2;
    }
    vector< int > used{0};
    for(int i = 1; i < N + M; i++) {
      if(tap[i - 1] == tap[i] && (tap[i] == 1 || tap[i] == 2)) {
        continue;
      }
      used.emplace_back(i);
    }
    sort(begin(used), end(used));
    for(int i = 0; i < N; i++) cout << upper_bound(begin(used), end(used), ans[i]) - begin(used) << " ";
    cout << endl;
    for(int i = 0; i < M; i++) cout << upper_bound(begin(used), end(used), ans[i + N]) - begin(used) << " ";
    cout << endl;
  } else {
    cout << "No" << endl;
  }
}