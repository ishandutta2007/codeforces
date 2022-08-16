#include <bits/stdc++.h>

using namespace std;

vector< vector< int > > graph;

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

  vector< int > SubTreeSize, NextPath;
  vector< int > TreeIndex, TreeDepth;
  vector< Centroid > Centroids;

  void BuildSubTreeSize()
  {
    stack< pair< int, int > > s;
    s.push({graph.size() - 1, -1});
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
    s.push({graph.size() - 1, -1});
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
};


typedef long long int64;

int64 N, X[100000], Y[100000], M, A[100000], B[100000];

int main()
{


  scanf("%lld", &N);
  for(int i = 0; i < N; i++) {
    scanf("%lld %lld", &X[i], &Y[i]);
  }
  scanf("%lld", &M);
  for(int i = 0; i < M; i++) {
    scanf("%lld %lld", &A[i], &B[i]);
    --A[i], --B[i];
  }

  vector< int > vs;
  vs.push_back(N - 1);
  CentroidPathDecomposition cpd(N);
  for(int i = N - 2; i >= 0; i--) {
    while(vs.size() >= 2) {
      int u = vs[vs.size() - 1], v = vs[vs.size() - 2];
      if((X[u] - X[i]) * (Y[v] - Y[i]) <= (X[v] - X[i]) * (Y[u] - Y[i])) break;
      vs.pop_back();
    }
    cpd.AddEdge(i, vs[vs.size() - 1]);
    vs.push_back(i);
  }
  cpd.Build();
  for(int i = 0; i < M; i++) {
    printf("%d ", cpd.LCA(A[i], B[i]) + 1);
  }
  puts("");
}