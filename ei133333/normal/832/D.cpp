#include <bits/stdc++.h>

using namespace std;

struct CentroidPathDecomposition
{
  struct Centroid
  {
    int ParIndex, ParDepth, Deep;
    vector< int > node;

    inline int size()
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

  void BuildSubTreeSize()
  {
    stack< pair< int, int > > s;
    s.push({0, -1});
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
          if(p.second != to) s.push({to, p.first});
        }
      }
    }
  }

  void BuildPath()
  {
    stack< pair< int, int > > s;
    Centroids.push_back((Centroid) {-1, -1, 0});
    s.push({0, -1});
    TreeIndex[0] = 0;
    while(!s.empty()) {
      auto p = s.top();
      s.pop();
      TreeDepth[p.first] = Centroids[TreeIndex[p.first]].size();
      for(auto &to : graph[p.first]) {
        if(p.second != to) {
          if(to == NextPath[p.first]) { // Centroid-Path
            TreeIndex[to] = TreeIndex[p.first];
          } else {                  // Not Centroid-Path
            TreeIndex[to] = Centroids.size();
            Centroids.push_back((Centroid) {TreeIndex[p.first], TreeDepth[p.first], Centroids[TreeIndex[p.first]].Deep + 1});
          }
          s.push({to, p.first});
        }
      }
      Centroids[TreeIndex[p.first]].node.push_back(p.first);
    }
  }

  void AddEdge(int x, int y)
  {
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  void Build()
  {
    BuildSubTreeSize();
    BuildPath();
  }

  inline int size()
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

  CentroidPathDecomposition(int SZ)
  {
    graph.resize(SZ);
    SubTreeSize.assign(SZ, -1);
    NextPath.resize(SZ);
    TreeIndex.resize(SZ);
    TreeDepth.resize(SZ);
  }

  void addPath(int a, int b, int d);

  int queryPath(int a, int b);
};

struct SegmentTree
{
  vector< int > seg, add;
  int sz;

  SegmentTree(int n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz - 1, 0);
    add.assign(2 * sz - 1, 0);
  }

  int rmq(int a, int b, int k, int l, int r)
  {
    if(a >= r || b <= l) return (0);
    if(a <= l && r <= b) return (add[k] * (r - l) + seg[k]);
    return (rmq(a, b, 2 * k + 1, l, (l + r) >> 1) + rmq(a, b, 2 * k + 2, (l + r) >> 1, r) + (min(b, r) - max(a, l)) * add[k]);
  }

  int rmq(int a, int b)
  {
    return (rmq(a, b, 0, 0, sz));
  }

  void rangeadd(int a, int b, int x, int k, int l, int r)
  {
    if(a >= r || b <= l) return;
    if(a <= l && r <= b) {
      add[k] += x;
      return;
    }
    seg[k] += (min(b, r) - max(a, l)) * x;
    rangeadd(a, b, x, 2 * k + 1, l, (l + r) >> 1);
    rangeadd(a, b, x, 2 * k + 2, (l + r) >> 1, r);
  }

  void rangeadd(int a, int b, int x)
  {
    rangeadd(a, b, x, 0, 0, sz);
  }
};

vector< SegmentTree > segs;


void CentroidPathDecomposition::addPath(int a, int b, int d)
{
  int TreeIdxA, TreeDepthA, TreeIdxB, TreeDepthB;
  tie(TreeIdxA, TreeDepthA) = Information(a);
  tie(TreeIdxB, TreeDepthB) = Information(b);
  while(TreeIdxA != TreeIdxB) {
    if(Centroids[TreeIdxA].Deep > Centroids[TreeIdxB].Deep) {
      segs[TreeIdxA].rangeadd(0, TreeDepthA + 1, d);
      tie(TreeIdxA, TreeDepthA) = Centroids[TreeIdxA].Up();
    } else {
      segs[TreeIdxB].rangeadd(0, TreeDepthB + 1, d);
      tie(TreeIdxB, TreeDepthB) = Centroids[TreeIdxB].Up();
    }
  }
  if(TreeDepthA > TreeDepthB) swap(TreeDepthA, TreeDepthB);
  segs[TreeIdxA].rangeadd(TreeDepthA, TreeDepthB + 1, d);
}

int CentroidPathDecomposition::queryPath(int a, int b)
{
  int TreeIdxA, TreeDepthA, TreeIdxB, TreeDepthB;
  int ret = 0;
  tie(TreeIdxA, TreeDepthA) = Information(a);
  tie(TreeIdxB, TreeDepthB) = Information(b);
  while(TreeIdxA != TreeIdxB) {
    if(Centroids[TreeIdxA].Deep > Centroids[TreeIdxB].Deep) {
      ret += segs[TreeIdxA].rmq(0, TreeDepthA + 1);
      tie(TreeIdxA, TreeDepthA) = Centroids[TreeIdxA].Up();
    } else {
      ret += segs[TreeIdxB].rmq(0, TreeDepthB + 1);
      tie(TreeIdxB, TreeDepthB) = Centroids[TreeIdxB].Up();
    }
  }
  if(TreeDepthA > TreeDepthB) swap(TreeDepthA, TreeDepthB);
  ret += segs[TreeIdxA].rmq(TreeDepthA, TreeDepthB + 1);
  return (ret);
}

int main()
{
  int N, Q;

  scanf("%d %d", &N, &Q);
  CentroidPathDecomposition tree(N);
  for(int i = 1; i < N; i++) {
    int p;
    scanf("%d", &p);
    tree.AddEdge(--p, i);
  }
  tree.Build();
  for(int i = 0; i < tree.size(); i++) {
    segs.emplace_back(SegmentTree(tree[i].size()));
  }
  vector< int > s(3);
  for(int i = 0; i < Q; i++) {
    for(int j = 0; j < 3; j++) {
      scanf("%d", &s[j]);
      --s[j];
    }
    sort(begin(s), end(s));
    int ret = 0;
    do {
      tree.addPath(s[0], s[1], 1);
      ret = max(ret, tree.queryPath(s[2], s[1]));
      tree.addPath(s[0], s[1], -1);
    } while(next_permutation(begin(s), end(s)));
    printf("%d\n", ret);
  }
}