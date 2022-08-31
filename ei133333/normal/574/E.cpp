#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int N;
vector< int > g[100000];
map< int, bool > dp[100000];

bool check_one(int idx, int par) {
  if(dp[idx].count(par)) return dp[idx][par];
  if(g[idx].size() >= 3) return false;
  int child = 0;
  for(auto &to : g[idx]) {
    if(to == par) continue;
    auto ret = check_one(to, idx);
    if(!ret) {
      child += 1333;
      break;
    }
    ++child;
  }
  return dp[idx][par] = (child <= 1);
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
  cin >> N;

  using pi = pair< int, bool >;
  auto f1 = [](pi a, pi b) {
    return pi(a.first + b.first, (a.first + b.first >= 2) | a.second | b.second);
  };
  auto f2 = [&](pi a, int src, int to, int d) {
    if(g[to].size() > 3) {
      a.first = 1;
      return a;
    }
    bool ok = true;
    for(auto &to2 : g[to]) {
      if(to2 == src) continue;
      ok &= check_one(to2, to);
    }
    if(!ok) {
      a.first = 1;
    } else {
      a.first = 0;
      a.second = false;
    }
    return a;
  };


  ReRooting< int, pi > dd(N, f1, f2, pi(0, false));
  for(int i = 1; i < N; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    dd.add_edge(x, y, 0);
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  for(auto &p : dd.solve()) {
    if(p.first <= 2 && !p.second) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
}