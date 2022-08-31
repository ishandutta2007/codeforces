#include<bits/stdc++.h>

using namespace std;

struct Namori
{
  vector< vector< int > > g;
  vector< int > in;

  Namori(int n) : g(n), in(n, 0) {}

  void add_edge(int x, int y)
  {
    g[x].push_back(y);
    g[y].push_back(x);
    ++in[x];
    ++in[y];
  }

  void decomposition(vector< int > &loop, vector< vector< int > > &forest)
  {
    int N = (int) in.size();
    forest.resize(N);
    queue< int > que;
    vector< bool > v(N, 0);
    for(int i = 0; i < N; i++) {
      if(in[i] == 1) {
        que.emplace(i);
        v[i] = true;
      }
    }
    while(!que.empty()) {
      int idx = que.front();
      que.pop();
      for(auto &to : g[idx]) {
        if(v[to]) continue;
        --in[to];
        forest[to].push_back(idx);
        forest[idx].push_back(to);
        if(in[to] > 1) continue;
        que.emplace(to);
        v[to] = true;
      }
    }

    function< void(int) > dfs = [&](int idx)
    {
      loop.push_back(idx);
      for(auto &to : g[idx]) {
        if(v[to]) continue;
        v[to] = true;
        dfs(to);
      }
    };
    for(int i = 0; i < N; i++) {
      if(v[i]) continue;
      v[i] = true;
      dfs(i);
      break;
    }
  }
};

typedef long long int64;
const int64 INF = 1LL << 58;

struct SegNode
{
  int64 ans, leftans, rightans;
  int64 rowsum;

  SegNode() {}

  SegNode(int64 a, int64 b, int64 c, int64 d) : ans(a), leftans(b), rightans(c), rowsum(d) {}

} e(-INF, -INF, -INF, 0);

SegNode operator*(const SegNode &a, const SegNode &b)
{
  SegNode c;
  c.ans = max({a.ans, b.ans, a.leftans + b.rightans});
  c.leftans = max(a.leftans + b.rowsum, b.leftans);
  c.rightans = max(a.rightans, b.rightans + a.rowsum);
  c.rowsum = a.rowsum + b.rowsum;
  return (c);
}


struct SegmentTree
{
  int sz;
  vector< SegNode > seg;

  SegmentTree(int n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz - 1, e);
  }

  void update(int k, const SegNode &x)
  {
    k += sz - 1;
    seg[k] = x;
    while(k > 0) {
      k = (k - 1) >> 1;
      seg[k] = seg[2 * k + 1] * seg[2 * k + 2];
    }
  }

  SegNode query(int a, int b, int k, int l, int r)
  {
    if(a >= r || b <= l) return (e);
    if(a <= l && r <= b) return (seg[k]);
    return (query(a, b, 2 * k + 1, l, (l + r) >> 1) * query(a, b, 2 * k + 2, (l + r) >> 1, r));
  }

  int64 query(int a, int b)
  {
    return (query(a, b, 0, 0, sz).ans);
  }
};


int main()
{
  int N;
  cin >> N;
  Namori namori(N);
  map< pair< int, int >, int > cost;
  for(int i = 0; i < N; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    namori.add_edge(a, b);
    cost[{a, b}] = c;
    cost[{b, a}] = c;
  }

  vector< int > loop;
  vector< vector< int > > tree;
  namori.decomposition(loop, tree);
  vector< int64 > dp(N, 0);
  int64 ret1 = 0, ret2 = INF;

  function< void(int, int) > rec = [&](int idx, int par)
  {
    for(auto &to : tree[idx]) {
      if(to == par) continue;
      rec(to, idx);
      dp[idx] = max(dp[idx], dp[to] + cost[{idx, to}]);
    }
  };
  function< void(int, int64, int) > rec2 = [&](int idx, int64 pardep, int par)
  {
    vector< pair< int64, int > > dist;
    dist.emplace_back(pardep, par);
    for(auto &to : tree[idx]) {
      if(to == par) continue;
      dist.emplace_back(dp[to] + cost[{idx, to}], to);
    }
    sort(dist.rbegin(), dist.rend());
    ret1 = max(ret1, dist[0].first);
    for(auto &to : tree[idx]) {
      if(to == par) continue;
      rec2(to, dist[to == dist[0].second].first + cost[{idx, to}], idx);
    }
  };

  for(int i : loop) rec(i, -1);
  for(int i : loop) rec2(i, 0, -1);
  SegmentTree seg(loop.size() * 2);
  for(int i = 0; i < loop.size() * 2; i++) {
    int64 latte = dp[loop[i % loop.size()]];
    int64 malta = cost[{loop[(i - 1 + loop.size()) % loop.size()], loop[i % loop.size()]}];
    seg.update(i, SegNode(latte, latte, latte + malta, malta));
  }
  for(int i = 0; i < loop.size(); i++) {
    ret2 = min(ret2, seg.query(i, i + loop.size()));
  }
  cout << max(ret2, ret1) << endl;
}