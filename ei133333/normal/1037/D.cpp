#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

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
  int N, S[200000];
  scanf("%d", &N);
  UnWeightedGraph g(N);
  for(int i = 1; i < N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 0; i < N; i++) {
    scanf("%d", &S[i]);
    --S[i];
  }
  for(int i = 0; i < N; i++) {
    sort(begin(g[i]), end(g[i]));
  }


  if(S[0] != 0) {
    cout << "No" << endl;
    return 0;
  }

  int marked = 1;
  queue< int > que;
  que.emplace(0);
  vector< int > visited(N);
  visited[0] = true;

  while(que.size()) {
    int idx = que.front();
    que.pop();
    while(marked < N && binary_search(begin(g[idx]), end(g[idx]), S[marked])) {
      visited[S[marked]] = true;
      que.emplace(S[marked++]);
    }
    for(auto &to : g[idx]) {
      if(!visited[to]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  for(int i = 0; i < N; i++) {
    if(!visited[i]) {
      cout << "No" << endl;
      return 0;
    }
  }


  cout << "Yes" << endl;
}