#include <bits/stdc++.h>

using namespace std;

using int64 = long long;


struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};


template< typename T, typename F >
T boruvka(int N, F f) {
  vector< int > rev(N), belong(N);
  UnionFind uf(N);
  T ret = T();
  while(uf.size(0) != N) {
    int ptr = 0;
    for(int i = 0; i < N; i++) {
      if(uf.find(i) == i) {
        belong[i] = ptr++;
        rev[belong[i]] = i;
      }
    }
    for(int i = 0; i < N; i++) {
      belong[i] = belong[uf.find(i)];
    }
    auto v = f(ptr, belong);
    bool update = false;
    for(int i = 0; i < ptr; i++) {
      if(~v[i].second && uf.unite(rev[i], rev[v[i].second])) {
        ret += v[i].first;
        update = true;
      }
    }
    if(!update) return -1; // notice!!
  }
  return ret;
}

const int64 INF = 1LL << 60;

int main() {
  int N, M;
  int64 A[200000];
  int64 X[400000], Y[400000], Z[400000];

  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for(int i = 0; i < M; i++) {
    cin >> X[i] >> Y[i] >> Z[i];
    --X[i], --Y[i];
    X[M + i] = Y[i];
    Y[M + i] = X[i];
    Z[M + i] = Z[i];
  }

  using pii = pair< pair< int64, int >, pair< int64, int > >;
  auto f2 = [](pii a, pair< int64, int > p) {
    if(a.first.second == p.second) {
      a.first.first = min(a.first.first, p.first);
    } else if(a.second.second == p.second) {
      a.second.first = min(a.second.first, p.first);
      if(a.first > a.second) swap(a.first, a.second);
    } else {
      if(p < a.first) {
        a.second = a.first;
        a.first = p;
      } else if(p < a.second) {
        a.second = p;
      }
    }
    return a;
  };


  auto f = [&](int, vector< int > &belong) {
    vector< pair< int64, int > > ans(N, make_pair(INF, -1));
    for(int i = 0; i < 2 * M; i++) {
      if(belong[X[i]] == belong[Y[i]]) continue;
      ans[belong[X[i]]] = min(ans[belong[X[i]]], make_pair(Z[i], belong[Y[i]]));
    }
    pii top(make_pair(INF, -1), make_pair(INF, -1));
    for(int i = 0; i < N; i++) {
      top = f2(top, make_pair(A[i], belong[i]));
    }
    for(int i = 0; i < N; i++) {
      auto o = top.first;
      if(o.second == belong[i]) o = top.second;
      ans[belong[i]] = min(ans[belong[i]], make_pair(o.first + A[i], o.second));
    }
    return ans;
  };
  cout << boruvka< int64, decltype(f) >(N, f) << endl;
}