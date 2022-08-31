#include<bits/stdc++.h>

using namespace std;

struct StronglyConnectedComponents
{
  vector< vector< int > > gg, rg;
  vector< pair< int, int > > edges;
  vector< int > comp, order, used;

  StronglyConnectedComponents(size_t v) : gg(v), rg(v), comp(v, -1), used(v, 0) {}

  virtual void add_edge(int x, int y)
  {
    gg[x].push_back(y);
    rg[y].push_back(x);
    edges.emplace_back(x, y);
  }

  int operator[](int k)
  {
    return (comp[k]);
  }

  void dfs(int idx)
  {
    if(used[idx]) return;
    used[idx] = true;
    for(int to : gg[idx]) dfs(to);
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt)
  {
    if(comp[idx] != -1) return;
    comp[idx] = cnt;
    for(int to : rg[idx]) rdfs(to, cnt);
  }

  void build(vector< vector< int > > &t)
  {
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

struct TwoSatisfiability : StronglyConnectedComponents
{
  int sz;

  TwoSatisfiability(size_t v) : sz(v), StronglyConnectedComponents(v + v) {}

  void add_edge(int u, int v) // (u or v)
  {
    StronglyConnectedComponents::add_edge(rev(u), v);
    StronglyConnectedComponents::add_edge(rev(v), u);
  }

  void add_edge(int u)
  {
    TwoSatisfiability::add_edge(u, u);
  }

  inline int rev(int x)
  {
    if(x >= sz) return (x - sz);
    return (x + sz);
  }

  bool operator()(int v) // note
  {
    return ((*this)[v] > (*this)[rev(v)]);
  }

  bool solve()
  {
    vector< vector< int > > g;
    build(g);
    for(int i = 0; i < sz; i++) {
      if((*this)[i] == (*this)[rev(i)]) return (false);
    }
    return (true);
  }
};

void fail()
{
  puts("No");
  exit(0);
}

int main()
{
  int N, M;
  vector< int > s[100000];

  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    int L;
    cin >> L;
    s[i].resize(L);
    for(auto &p : s[i]) cin >> p, --p;
  }

  auto on = [&](int idx)
  {
    return (idx);
  };

  auto off = [&](int idx)
  {
    return (M + idx);
  };

  TwoSatisfiability sat(M);
  for(int i = 1; i < N; i++) {
    int lcp = 0;
    while(lcp < min(s[i - 1].size(), s[i].size()) && s[i - 1][lcp] == s[i][lcp]) ++lcp;
    if(lcp == s[i - 1].size()) {
      continue;
    } else if(lcp == s[i].size()) {
      fail();
    } else if(s[i - 1][lcp] < s[i][lcp]) {
      sat.add_edge(s[i - 1][lcp], sat.rev(s[i][lcp]));
    } else {
      sat.add_edge(s[i - 1][lcp]);
      sat.add_edge(sat.rev(s[i][lcp]));
    }
  }
  if(!sat.solve()) fail();
  vector< int > change;
  for(int i = 0; i < M; i++) {
    if(sat(i)) change.emplace_back(i);
  }
  puts("Yes");
  printf("%d\n", (int) change.size());
  for(auto &p : change) printf("%d ", p + 1);
  puts("");
}