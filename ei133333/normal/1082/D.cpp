#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;

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

pair< int, int > dfs(const UnWeightedGraph &g, int idx, int par) {
  pair< int, int > ret(0, idx);
  for(auto &e : g[idx]) {
    if(e == par) continue;
    auto cost = dfs(g, e, idx);
    cost.first += 1;
    ret = max(ret, cost);
  }
  return ret;
}

int tree_diameter(const UnWeightedGraph &g) {
  auto p = dfs(g, 0, -1);
  auto q = dfs(g, p.second, -1);
  return (q.first);
}


int main() {
  int N;
  cin >> N;
  vector< pair< int, int > > beet;
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    beet.emplace_back(x, i);
  }
  sort(beet.rbegin(), beet.rend());
  int ret = -1;
  for(int i = (int) beet.size(); i >= 0; i--) {
    UnWeightedGraph g(N);
    vector< pair< int, int > > lis;
    for(int j = 0; j < i; j++) {
      lis.push_back(beet[j]);
    }
    for(int j = 0; j + 1 < lis.size(); j++) {
      lis[j].first--;
      g[lis[j].second].push_back(lis[j + 1].second);
      g[lis[j + 1].second].push_back(lis[j].second);
    }
    for(int j = 1; j < lis.size(); j++) {
      lis[j].first--;
    }
    bool fail = false;
    for(int j = 0; j < lis.size(); j++) {
      fail |= lis[j].first < 0;
    }
    for(int j = i; j < beet.size(); j++) {
      bool ex = false;
      for(int k = 0; k < j; k++) {
        if(lis[k].first > 0) {
          lis.push_back(beet[j]);
          lis[k].first--;
          lis.back().first--;
          g[lis[j].second].push_back(lis[k].second);
          g[lis[k].second].push_back(lis[j].second);
          ex = true;
          break;
        }
      }
      if(!ex) {
        fail = true;
        break;
      }
    }
    if(!fail) {
      ret = max(ret, tree_diameter(g));
    }
  }

  if(~ret) {
    cout << "YES " << ret << endl;

    for(int i = (int) beet.size(); i >= 0; i--) {
      UnWeightedGraph g(N);
      vector< pair< int, int > > lis;
      vector< pair< int, int > > edges;
      for(int j = 0; j < i; j++) {
        lis.push_back(beet[j]);
      }
      for(int j = 0; j + 1 < lis.size(); j++) {
        lis[j].first--;
        g[lis[j].second].push_back(lis[j + 1].second);
        g[lis[j + 1].second].push_back(lis[j].second);
        edges.emplace_back(lis[j].second, lis[j + 1].second);
      }
      for(int j = 1; j < lis.size(); j++) {
        lis[j].first--;
      }
      bool fail = false;
      for(int j = 0; j < lis.size(); j++) {
        fail |= lis[j].first < 0;
      }
      for(int j = i; j < beet.size(); j++) {
        bool ex = false;
        for(int k = 0; k < j; k++) {
          if(lis[k].first > 0) {
            lis.push_back(beet[j]);
            lis[k].first--;
            lis.back().first--;
            g[lis[j].second].push_back(lis[k].second);
            g[lis[k].second].push_back(lis[j].second);
            edges.emplace_back(lis[j].second, lis[k].second);
            ex = true;
            break;
          }
        }
        if(!ex) {
          fail = true;
          break;
        }
      }
      if(!fail) {
        if(ret == tree_diameter(g)) {
          cout << edges.size() << endl;
          for(auto& p : edges) {
            cout << p.first + 1 << " " << p.second + 1 << endl;
          }
          return 0;
        }
      }
    }
  }


  cout << "NO" << endl;
}