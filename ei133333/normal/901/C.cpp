#include <bits/stdc++.h>

using namespace std;


using int64 = long long;

struct SegNode
{
  int v, p;

  SegNode(int v, int s) : v(v), p(s) {}

  SegNode operator*(const SegNode &r) const
  {
    int x = min(v, r.v);
    int y = max(p, r.p);
    return (SegNode(x, y));
  }
} e(1 << 30, -(1 << 30));

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

  void set(int k, const SegNode &x)
  {
    seg[k + sz - 1] = x;
  }

  void build()
  {
    for(int k = sz - 2; k >= 0; k--) {
      seg[k] = seg[2 * k + 1] * seg[2 * k + 2];
    }
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

  SegNode query(int a, int b)
  {
    return (query(a, b, 0, 0, sz));
  }
};


vector< SegmentTree > segs;

struct CentroidPathDecomposition
{
  struct Centroid
  {
    int ParIndex, ParDepth, Deep;
    vector< int > node;

    Centroid(int idx, int dep, int deep) : ParIndex(idx), ParDepth(dep), Deep(deep) {}

    inline size_t size()
    {
      return (node.size());
    }

    inline int &operator[](int k)
    {
      return (node[k]);
    }

    inline pair< int, int > Up()
    {
      return (make_pair(ParIndex, ParDepth));
    }
  };

  vector< vector< int > > graph;
  vector< int > SubTreeSize, NextPath;
  vector< int > TreeIndex, TreeDepth;
  vector< Centroid > Centroids;

  void BuildSubTreeSize(int x)
  {
    stack< pair< int, int > > s;
    s.emplace(x, -1);
    while(!s.empty()) {
      auto p = s.top();
      s.pop();
      if(~SubTreeSize[p.first]) {
        NextPath[p.first] = -1;
        for(auto &to : graph[p.first]) {
          if(p.second == to) continue;
          SubTreeSize[p.first] += SubTreeSize[to];
          if(NextPath[p.first] == -1 || SubTreeSize[NextPath[p.first]] < SubTreeSize[to]) {
            NextPath[p.first] = to;
          }
        }
      } else {
        s.push(p);
        SubTreeSize[p.first] = 1;
        for(auto &to : graph[p.first]) {
          if(p.second != to) s.emplace(to, p.first);
        }
      }
    }
  }

  void BuildPath(int x)
  {
    stack< pair< int, int > > s;
    Centroids.emplace_back(-1, -1, 0);
    s.emplace(x, -1);
    TreeIndex[x] = 0;
    while(!s.empty()) {
      auto p = s.top();
      s.pop();
      TreeDepth[p.first] = (int) Centroids[TreeIndex[p.first]].size();
      for(auto &to : graph[p.first]) {
        if(p.second == to) continue;
        if(to == NextPath[p.first]) { // Centroid-Path
          TreeIndex[to] = TreeIndex[p.first];
        } else {                  // Not Centroid-Path
          TreeIndex[to] = (int) Centroids.size();
          Centroids.emplace_back(TreeIndex[p.first], TreeDepth[p.first], Centroids[TreeIndex[p.first]].Deep + 1);
        }
        s.emplace(to, p.first);
      }
      Centroids[TreeIndex[p.first]].node.emplace_back(p.first);
    }
  }

  void AddEdge(int x, int y)
  {
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  virtual void Build(int x)
  {
    BuildSubTreeSize(x);
    BuildPath(x);
  }

  inline size_t size()
  {
    return (Centroids.size());
  }

  inline pair< int, int > Information(int idx)
  {
    return (make_pair(TreeIndex[idx], TreeDepth[idx]));
  }

  inline Centroid &operator[](int k)
  {
    return (Centroids[k]);
  }

  inline int LCA(int a, int b)
  {
    int TreeIdxA, TreeDepthA, TreeIdxB, TreeDepthB;
    tie(TreeIdxA, TreeDepthA) = Information(a);
    tie(TreeIdxB, TreeDepthB) = Information(b);
    while(TreeIdxA != TreeIdxB) {
      if(Centroids[TreeIdxA].Deep > Centroids[TreeIdxB].Deep) {
        tie(TreeIdxA, TreeDepthA) = Centroids[TreeIdxA].Up();
      } else {
        tie(TreeIdxB, TreeDepthB) = Centroids[TreeIdxB].Up();
      }
    }
    if(TreeDepthA > TreeDepthB) swap(TreeDepthA, TreeDepthB);
    return (Centroids[TreeIdxA][TreeDepthA]);
  }

  inline pair< int, int > query(int a, int b)
  {
    int TreeIdxA, TreeDepthA, TreeIdxB, TreeDepthB;
    tie(TreeIdxA, TreeDepthA) = Information(a);
    tie(TreeIdxB, TreeDepthB) = Information(b);
    SegNode x = e;

    while(TreeIdxA != TreeIdxB) {
      if(Centroids[TreeIdxA].Deep > Centroids[TreeIdxB].Deep) {
        x = x * segs[TreeIdxA].query(0, TreeDepthA + 1);
        tie(TreeIdxA, TreeDepthA) = Centroids[TreeIdxA].Up();
      } else {
        x = x * segs[TreeIdxB].query(0, TreeDepthB + 1);
        tie(TreeIdxB, TreeDepthB) = Centroids[TreeIdxB].Up();
      }
    }
    if(TreeDepthA > TreeDepthB) swap(TreeDepthA, TreeDepthB);
    x = x * segs[TreeIdxA].query(TreeDepthA, TreeDepthB + 1);
    return {x.v, x.p};
  }

  CentroidPathDecomposition(int SZ)
  {
    graph.resize(SZ);
    SubTreeSize.assign(SZ, -1);
    NextPath.resize(SZ);
    TreeIndex.resize(SZ);
    TreeDepth.resize(SZ);
  }

};

struct UnionFind
{
  vector< int > data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k)
  {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k)
  {
    return (-data[find(k)]);
  }
};

template< class T >
struct BinaryIndexedTree
{
  vector< T > data;

  BinaryIndexedTree(int sz)
  {
    data.assign(++sz, 0);
  }

  T sum(int k)
  {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x)
  {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};


int N, M, Q;
vector< int > g[300000];
int reach[300000];
int L[300000], R[300000];
int64 ret[300000];
vector< int > add[300001], del[300001];

int main()
{
  scanf("%d %d", &N, &M);
  fill_n(reach, N, N);
  UnionFind uf(N);
  CentroidPathDecomposition cpd(N + 1);

  for(int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    if(a > b) swap(a, b);
    if(!uf.unite(a, b)) {
      g[a].emplace_back(b);
    } else {
      cpd.AddEdge(a, b);
    }
  }
  for(int i = 0; i < N; i++) {
    if(uf.find(i) == i) {
      cpd.AddEdge(i, N);
    }
  }
  cpd.Build(N);
  for(int i = 0; i < cpd.size(); i++) {
    SegmentTree seg2(cpd[i].size());
    for(int j = 0; j < cpd[i].size(); j++) {
      seg2.set(j, SegNode(cpd[i][j], cpd[i][j]));
    }
    seg2.build();
    segs.emplace_back(seg2);
  }

  for(int i = 0; i < N; i++) {
    for(auto &p : g[i]) {
      auto get = cpd.query(i, p);
      reach[get.first] = min(reach[get.first], get.second);
    }
  }

  multiset< int > st;
  for(int i = 0; i < N; i++) {
    st.emplace(reach[i]);
  }
  for(int i = 0; i < N; i++) {
    int most = *st.begin();
    st.erase(st.find(reach[i]));
    reach[i] = most - 1;
  }

  scanf("%d", &Q);
  for(int i = 0; i < Q; i++) {
    scanf("%d %d", &L[i], &R[i]);
    --L[i], --R[i];
    add[L[i]].emplace_back(i);
    del[R[i]].emplace_back(i);
  }


  BinaryIndexedTree< int64 > bit1(N + 1), bit2(N + 1);
  for(int i = 0; i < N; i++) {
    for(auto &p : add[i]) {
      ret[p] -= 1LL * (R[p] + 1) * (bit1.sum(N) - bit1.sum(R[p] - 1));
      ret[p] -= bit2.sum(R[p] - 1);
    }
    bit1.add(reach[i], 1);
    bit2.add(reach[i], reach[i] + 1);
    for(auto &p : del[i]) {
      ret[p] += 1LL * (R[p] + 1) * (bit1.sum(N) - bit1.sum(R[p] - 1));
      ret[p] += bit2.sum(R[p] - 1);
    }
  }

  for(int i = 0; i < Q; i++) {
    ret[i] += 1LL * (L[i] - R[i] - 1) * (L[i] + R[i]) / 2;
    printf("%lld\n", ret[i]);
  }
}