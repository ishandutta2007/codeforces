#include <bits/stdc++.h>

using namespace std;


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

  void BuildSubTreeSize()
  {
    stack< pair< int, int > > s;
    s.emplace(0, -1);
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

  void BuildPath()
  {
    stack< pair< int, int > > s;
    Centroids.emplace_back(-1, -1, 0);
    s.emplace(0, -1);
    TreeIndex[0] = 0;
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

  virtual void Build()
  {
    BuildSubTreeSize();
    BuildPath();
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

  inline virtual void query(int a, int b, const function< void(int, int, int) > &f)
  {
    int TreeIdxA, TreeDepthA, TreeIdxB, TreeDepthB;
    tie(TreeIdxA, TreeDepthA) = Information(a);
    tie(TreeIdxB, TreeDepthB) = Information(b);
    while(TreeIdxA != TreeIdxB) {
      if(Centroids[TreeIdxA].Deep > Centroids[TreeIdxB].Deep) {
        f(TreeIdxA, 0, TreeDepthA + 1);
        tie(TreeIdxA, TreeDepthA) = Centroids[TreeIdxA].Up();
      } else {
        f(TreeIdxB, 0, TreeDepthB + 1);
        tie(TreeIdxB, TreeDepthB) = Centroids[TreeIdxB].Up();
      }
    }
    if(TreeDepthA > TreeDepthB) swap(TreeDepthA, TreeDepthB);
    f(TreeIdxA, TreeDepthA, TreeDepthB + 1);
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

struct TreeArray : CentroidPathDecomposition
{
  TreeArray(int sz) : CentroidPathDecomposition(sz) {}

  vector< int > index;

  void Build()
  {
    CentroidPathDecomposition::Build();
    int ptr = 0;
    for(auto &centroid : Centroids) {
      index.emplace_back(ptr);
      ptr += centroid.size();
    }
  }

  inline int get(int a)
  {
    auto p = Information(a);
    return (index[p.first] + p.second);
  }

  inline void query(int a, int b, const function< void(int, int) > &f)
  {
    int TreeIdxA, TreeDepthA, TreeIdxB, TreeDepthB;
    tie(TreeIdxA, TreeDepthA) = Information(a);
    tie(TreeIdxB, TreeDepthB) = Information(b);
    while(TreeIdxA != TreeIdxB) {
      if(Centroids[TreeIdxA].Deep > Centroids[TreeIdxB].Deep) {
        f(index[TreeIdxA], index[TreeIdxA] + TreeDepthA + 1);
        tie(TreeIdxA, TreeDepthA) = Centroids[TreeIdxA].Up();
      } else {
        f(index[TreeIdxB], index[TreeIdxB] + TreeDepthB + 1);
        tie(TreeIdxB, TreeDepthB) = Centroids[TreeIdxB].Up();
      }
    }
    if(TreeDepthA > TreeDepthB) swap(TreeDepthA, TreeDepthB);
    f(index[TreeIdxA] + TreeDepthA + 1, index[TreeIdxA] + TreeDepthB + 1);
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

int main()
{
  int N, Q, A[100000], B[100000];
  scanf("%d", &N);
  TreeArray tree(N);
  for(int i = 1; i < N; i++) {
    scanf("%d %d", &A[i], &B[i]);
    --A[i], --B[i];
    tree.AddEdge(A[i], B[i]);
  }
  tree.Build();
  BinaryIndexedTree< int > bit(N);
  scanf("%d", &Q);
  while(Q--) {
    int X, Y;
    scanf("%d %d", &X, &Y);
    --X, --Y;
    tree.query(X, Y, [&](int a, int b)
    {
      bit.add(a, 1);
      bit.add(b, -1);
    });
  }
  for(int i = 1; i < N; i++) {
    if(i > 1) putchar(' ');
    printf("%d", bit.sum(max(tree.get(A[i]), tree.get(B[i]))));
  }
  puts("");

}