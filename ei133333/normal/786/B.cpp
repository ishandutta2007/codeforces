#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
const int64 INF = 1LL << 58;
typedef pair< int64, int > Pi;

struct edge
{
  int to, cost;
};

struct SegmentTreeGraph
{
  vector< vector< edge > > g;
  int n, sz;

  SegmentTreeGraph(int n) : n(n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    g.resize((2 * sz - 1) * 2);
    for(int k = 0; k < n; k++) {
      g[(k + sz - 1) * 2].push_back((edge) {(k + sz - 1) * 2 + 1, 0});
      g[(k + sz - 1) * 2 + 1].push_back((edge) {(k + sz - 1) * 2, 0});
    }
    for(int k = sz - 2; k >= 0; k--) {
      g[k * 2].push_back((edge) {(2 * k + 1) * 2, 0});
      g[k * 2].push_back((edge) {(2 * k + 2) * 2, 0});
      g[(2 * k + 1) * 2 + 1].push_back((edge) {k * 2 + 1, 0});
      g[(2 * k + 2) * 2 + 1].push_back((edge) {k * 2 + 1, 0});
    }
  }

  void add(int a, int b, int x, int t, int w, int k, int l, int r)
  {
    if(a >= r || b <= l) return;
    if(a <= l && r <= b) {
      if(t == 2) g[(x + sz - 1) * 2].push_back((edge) {k * 2, w});
      else g[k * 2 + 1].push_back((edge) {(x + sz - 1) * 2 + 1, w});
      return;
    }
    add(a, b, x, t, w, 2 * k + 1, l, (l + r) >> 1);
    add(a, b, x, t, w, 2 * k + 2, (l + r) >> 1, r);
  }

  void add(int a, int b, int x, int t, int w)
  {
    add(a, b, x, t, w, 0, 0, sz);
  }

  void dijkstra(int k)
  {
    k += sz - 1;
    k *= 2;
    priority_queue< Pi, vector< Pi >, greater< Pi > > que;
    vector< int64 > v(g.size(), INF);
    v[k] = 0;
    que.emplace(0, k);
    while(!que.empty()) {
      auto p = que.top();
      que.pop();
      if(p.first > v[p.second]) continue;
      for(auto &e : g[p.second]) {
        if(p.first + e.cost >= v[e.to]) continue;
        v[e.to] = p.first + e.cost;
        que.emplace(v[e.to], e.to);
      }
    }

    for(int i = 0; i < n; i++) {
      if(v[(i + sz - 1) * 2] >= INF) printf("-1 ");
      else printf("%lld ", v[(i + sz - 1) * 2]);
    }
    puts("");
  }
};

int main()
{
  int N, Q, S;

  scanf("%d %d %d", &N, &Q, &S);
  SegmentTreeGraph tree(N);
  while(Q--) {
    int t, v, l, r, w;
    scanf("%d", &t);
    if(t == 1) {
      scanf("%d %d %d", &v, &l, &w);
      --v;
      --l;
      r = l + 1;
      t = 2;
    } else {
      scanf("%d %d %d %d", &v, &l, &r, &w);
      --v;
      --l;
    }
    tree.add(l, r, v, t, w);
  }
  tree.dijkstra(--S);
}