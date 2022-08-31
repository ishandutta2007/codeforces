#include <bits/stdc++.h>

using namespace std;


int N, M;
bool S[123456];
vector< int > g[123456];
int deg[123456];
bool need[123456];

bool dfs1(int idx, int par) {
  bool f = S[idx];
  for(auto &to : g[idx]) {
    if(to == par) continue;
    f |= dfs1(to, idx);
  }
  need[idx] = f;
  return f;
}

template< typename Data, typename T >
struct ReRooting {

  struct Node {
    int to, rev;
    Data data;
  };

  using F1 = function< T(T, T) >;
  using F2 = function< T(T, int, int, Data) >; // ret, src, to, data

  vector< vector< Node > > g;
  vector< vector< T > > ldp, rdp;
  vector< int > lptr, rptr;
  const F1 f1;
  const F2 f2;
  const T ident;

  ReRooting(int n, const F1 &f1, const F2 &f2, const T &ident) :
      g(n), ldp(n), rdp(n), lptr(n), rptr(n), f1(f1), f2(f2), ident(ident) {}

  void add_edge(int u, int v, const Data &d) {
    g[u].emplace_back((Node) {v, (int) g[v].size(), d});
    g[v].emplace_back((Node) {u, (int) g[u].size() - 1, d});
  }

  T dfs(int idx, int par) {

    while(lptr[idx] != par && lptr[idx] < g[idx].size()) {
      auto &e = g[idx][lptr[idx]];
      ldp[idx][lptr[idx] + 1] = f1(ldp[idx][lptr[idx]], f2(dfs(e.to, e.rev), idx, e.to, e.data));
      ++lptr[idx];
    }
    while(rptr[idx] != par && rptr[idx] >= 0) {
      auto &e = g[idx][rptr[idx]];
      rdp[idx][rptr[idx]] = f1(rdp[idx][rptr[idx] + 1], f2(dfs(e.to, e.rev), idx, e.to, e.data));
      --rptr[idx];
    }
    if(par < 0) return rdp[idx][0];
    return f1(ldp[idx][par], rdp[idx][par + 1]);
  }

  vector< T > solve() {
    for(int i = 0; i < g.size(); i++) {
      ldp[i].assign(g[i].size() + 1, ident);
      rdp[i].assign(g[i].size() + 1, ident);
      lptr[i] = 0;
      rptr[i] = (int) g[i].size() - 1;
    }
    vector< T > ret;
    for(int i = 0; i < g.size(); i++) {
      ret.push_back(dfs(i, -1));
    }
    return ret;
  }
};

int main() {
  cin >> N >> M;
  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
    deg[a]++;
    deg[b]++;
  }
  int root = -1;
  for(int i = 0; i < M; i++) {
    int x;
    cin >> x;
    --x;
    S[x] = true;
    root = x;
  }
  dfs1(root, -1);
  auto f1 = [](int a, int b) {
    return max(a, b);
  };
  auto f2 = [](int a, int src, int to, int cost) {
    return a + cost;
  };
  ReRooting< int, int > uku(N, f1, f2, 0);
  int ret = 0;
  for(int i = 0; i < N; i++) {
    if(need[i]) {
      ret++;
      for(auto to : g[i]) {
        if(need[to]) {
          if(i < to) uku.add_edge(i, to, 1);
        }
      }
    }
  }

  ret = (ret - 1) * 2;
  if(ret == 0) {
    for(int i = 0; i < N; i++) {
      if(S[i]) {
        cout << i + 1 << endl;
        cout << 0 << endl;
        return 0;
      }
    }
    return 0;
  }

  auto latte = uku.solve();
  int q = 0, idx = 0;
  for(int i = 0; i < N; i++) {
    if(need[i]) {
      if(q < latte[i]) {
        q = latte[i];
        idx = i + 1;
      }
    }
  }

  cout << idx << endl;
  cout << ret - q << endl;
}