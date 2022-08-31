#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

inline int64 Mul(int64 a, int64 b)
{
  int64 v = a * b;
  if(v / a != b) return(1LL << 61);
  else return(v);
}

struct SegmentTree
{
  int n;
  vector< int64 > data;
  SegmentTree(int sz)
  {
    n = 1;
    while(n < sz) n <<= 1;
    data.assign(2 * n - 1, 1);
  }
  void Build(vector< int64 >& d)
  {
    for(int i = 0; i < d.size(); i++) {
      data[i + n - 1] = d[i];
    }
    for(int i = n - 2; i >= 0; i--) {
      data[i] = Mul(data[2 * i + 1], data[2 * i + 2]);
    }
  }
  inline int64 Query(int a, int b, int k, int l, int r)
  {
    if(a >= r || b <= l) return(1);
    if(a <= l && r <= b) return(data[k]);
    return(Mul(Query(a, b, 2 * k + 1, l, (l + r) >> 1), Query(a, b, 2 * k + 2, (l + r) >> 1, r)));
  }
  inline void Update(int k, int64 x)
  {
    k += n - 1;
    data[k] = x;
    while(k > 0) {
      k = (k - 1) >> 1;
      data[k] = Mul(data[2 * k + 1], data[2 * k + 2]);
    }
  }
  int64 Query(int a, int b)
  {
    if(a >= b) return(1);
    return(Query(a, b, 0, 0, n));
  }
};

struct CentroidPathDecomposition
{
  struct Centroid
  {
    int ParIndex, ParDepth, Deep;
    vector< int > node;
    inline int size()
    {
      return(node.size());
    }
    inline int &operator[](int k)
    {
      return(node[k]);
    }
    inline pair< int, int > Up()
    {
      return(make_pair(ParIndex, ParDepth));
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
      auto p = s.top(); s.pop();
      if(~SubTreeSize[p.first]) {
        NextPath[p.first] = 0;
        for(auto& to : graph[p.first]) {
          SubTreeSize[p.first] += SubTreeSize[to];
          if(SubTreeSize[NextPath[p.first]] < SubTreeSize[to]) {
            NextPath[p.first] = to;
          }
        }
      } else {
        s.push(p);
        SubTreeSize[p.first] = 1;
        for(auto& to : graph[p.first]) {
          if(p.second != to) s.push({to, p.first});
        }
      }
    }
  }
  void BuildPath()
  {
    stack< pair< int, int > > s;
    Centroids.push_back((Centroid){-1, -1, 0});
    s.push({0, -1});
    TreeIndex[0] = 0;
    while(!s.empty()) {
      auto p = s.top(); s.pop();
      TreeDepth[p.first] = Centroids[TreeIndex[p.first]].size();
      for(auto& to : graph[p.first]) {
        if(p.second != to) {
          if(to == NextPath[p.first]) { // Centroid-Path
            TreeIndex[to] = TreeIndex[p.first];
          } else {                  // Not Centroid-Path
            TreeIndex[to] = Centroids.size();
            Centroids.push_back((Centroid){TreeIndex[p.first], TreeDepth[p.first], Centroids[TreeIndex[p.first]].Deep + 1});
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
    return(Centroids.size());
  }
  inline pair< int, int > Information(int idx)
  {
    return(make_pair(TreeIndex[idx], TreeDepth[idx]));
  }
  inline Centroid &operator[](int k)
  {
    return(Centroids[k]);
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

signed main()
{
  int N, Q;
  map< pair< int, int >, int64 > cost;
  pair< int, int > edge[200000];

  scanf("%d %d", &N, &Q);

  CentroidPathDecomposition CPD(N);
  for(int i = 0; i < N - 1; i++) {
    int64 a, b, c;
    scanf("%I64d %I64d %I64d", &a, &b, &c);
    CPD.AddEdge(--a, --b);
    edge[i] = {a, b};
    cost[make_pair(a, b)] = c;
    cost[make_pair(b, a)] = c;
  }
  CPD.Build();

  vector< SegmentTree > segs;
  
  vector< int64 > data;
  for(int i = 0; i < CPD.size(); i++) {
    data.resize(CPD[i].size());
    segs.push_back(SegmentTree(CPD[i].size()));

    if(i == 0) {
      data[0] = 1;
    } else {
      auto d = CPD[i].Up();
      data[0] = cost[{CPD[d.first][d.second], CPD[i][0]}];
    }
    for(int j = 1; j < CPD[i].size(); j++) {
      data[j] = cost[{CPD[i][j - 1], CPD[i][j]}];
    }
    segs[i].Build(data);

  }
  int TreeIdxA, TreeDepthA, TreeIdxB, TreeDepthB;
  for(int i = 0; i < Q; i++) {
    int type;
    scanf("%d", &type);
    if(type == 1) {
      int64 a, b, y;
      scanf("%I64d %I64d %I64d", &a, &b, &y);
      --a, --b;
      int64 ret = 1;
      tie(TreeIdxA, TreeDepthA) = CPD.Information(a);
      tie(TreeIdxB, TreeDepthB) = CPD.Information(b);
      while(TreeIdxA != TreeIdxB) {
        if(CPD[TreeIdxA].Deep > CPD[TreeIdxB].Deep) {
          ret = Mul(ret, segs[TreeIdxA].Query(0, TreeDepthA + 1));
          tie(TreeIdxA, TreeDepthA) = CPD[TreeIdxA].Up();
        } else {
          ret = Mul(ret, segs[TreeIdxB].Query(0, TreeDepthB + 1));
          tie(TreeIdxB, TreeDepthB) = CPD[TreeIdxB].Up();
        }
      }
      if(TreeDepthA > TreeDepthB) swap(TreeDepthA, TreeDepthB);
      ret = Mul(ret, segs[TreeIdxA].Query(TreeDepthA + 1, TreeDepthB + 1));
      printf("%I64d\n", y / ret);
    } else {
      int64 a, b;
      scanf("%I64d %I64d", &a, &b);
      auto e = edge[--a];
      tie(TreeIdxA, TreeDepthA) = CPD.Information(e.first);
      tie(TreeIdxB, TreeDepthB) = CPD.Information(e.second);
      if(CPD.Centroids[TreeIdxA].Deep > CPD.Centroids[TreeIdxB].Deep) {
        swap(TreeIdxA, TreeIdxB);
        swap(TreeDepthA, TreeDepthB);
      } else if(TreeIdxA == TreeIdxB && TreeDepthA > TreeDepthB) {
        swap(TreeDepthA, TreeDepthB);
      }
      segs[TreeIdxB].Update(TreeDepthB, b);
    }
  }
}