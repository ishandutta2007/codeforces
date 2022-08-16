#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

template< typename G >
struct CentroidPathDecomposition {
  struct Centroid {
    int ParIndex, ParDepth, Deep;
    vector< int > node;

    Centroid(int idx, int dep, int deep) : ParIndex(idx), ParDepth(dep), Deep(deep) {}

    inline size_t size() {
      return (node.size());
    }

    inline int &operator[](int k) {
      return (node[k]);
    }

    inline pair< int, int > Up() {
      return (make_pair(ParIndex, ParDepth));
    }
  };

  const G &graph;
  vector< int > SubTreeSize, NextPath;
  vector< int > TreeIndex, TreeDepth;
  vector< Centroid > Centroids;

  void BuildSubTreeSize() {
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

  void BuildPath() {
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


  virtual void Build() {
    BuildSubTreeSize();
    BuildPath();
  }

  inline size_t size() {
    return (Centroids.size());
  }

  inline pair< int, int > Information(int idx) {
    return (make_pair(TreeIndex[idx], TreeDepth[idx]));
  }

  inline Centroid &operator[](int k) {
    return (Centroids[k]);
  }

  inline int LCA(int a, int b) {
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

  inline virtual void query(int a, int b, const function< void(int, int, int) > &f) {
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

  CentroidPathDecomposition(const G &g) : graph(g) {
    int SZ = g.size();
    SubTreeSize.assign(SZ, -1);
    NextPath.resize(SZ);
    TreeIndex.resize(SZ);
    TreeDepth.resize(SZ);
  }
};

struct SegmentTree {
  vector< int > data;
  int sz;

  SegmentTree(int n) {
    sz = 1;
    while(sz < n) sz <<= 1;
    data.assign(2 * sz - 1, 0);

    for(int i = 0; i < n; i++) {
      data[i + sz - 1] = 1;
    }
    for(int i = sz - 2; i >= 0; i--) {
      data[i] = data[2 * i + 1] + data[2 * i + 2];
    }
  }

  inline void Fill(int a, int b, int k, int l, int r) {
    if(a >= r || b <= l) return;
    if(a <= l && r <= b) {
      data[k] = 0;
    } else {
      if(data[k] == 0) return;
      Fill(a, b, 2 * k + 1, l, (l + r) >> 1);
      Fill(a, b, 2 * k + 2, (l + r) >> 1, r);
      data[k] = data[2 * k + 1] + data[2 * k + 2];
    }
  }

  inline int Query(int a, int b, int k, int l, int r) {
    if(a >= r || b <= l) return (0);
    if(a <= l && r <= b) return (data[k]);
    if(data[k] == 0) return (0);
    return (Query(a, b, 2 * k + 1, l, (l + r) >> 1) + Query(a, b, 2 * k + 2, (l + r) >> 1, r));
  }

  void Fill(int a, int b) {
    Fill(a, b, 0, 0, sz);
  }

  int Query(int a, int b) {
    return (Query(a, b, 0, 0, sz));
  }
};

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};


template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  UnWeightedGraph g(N);
  for(int i = 1; i < N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x, --y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  CentroidPathDecomposition< UnWeightedGraph > beet(g);
  beet.Build();
  vector< SegmentTree > segs;
  for(int i = 0; i < beet.size(); i++) segs.emplace_back(beet[i].size());

  int rest = N - K, last = -1;


  if(rest > 0) {
    for(int i = N - 1; i >= 0; i--) {
      if(last == -1) {
        auto p = beet.Information(i);
        segs[p.first].Fill(p.second, p.second + 1);
        rest--;
        last = i;
        continue;
      }
      int sum = 0;
      beet.query(last, i, [&](int x, int y, int z) { sum += segs[x].Query(y, z); });

      if(sum <= rest) {
        rest -= sum;
        beet.query(last, i, [&](int x, int y, int z) { segs[x].Fill(y, z); });
        last = i;
      }
    }
  }

  for(int i = 0; i < N; i++) {
    auto p = beet.Information(i);
    if(segs[p.first].Query(p.second, p.second + 1) == 1) {
      printf("%d ", i + 1);
    }
  }
  puts("");
}