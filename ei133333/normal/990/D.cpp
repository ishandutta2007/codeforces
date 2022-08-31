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

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  bool g[1000][1000] = {{}};
  if(A == 1 && B == 1) {
    for(int i = 1; i < N; i++) {
      g[i - 1][i] = true;
      g[i][i - 1] = true;
    }
    UnionFind uf(N);
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        if(!g[i][j]) uf.unite(i, j);
      }
    }
    if(uf.size(0) == N) {
      cout << "YES" << endl;
      for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
          cout << g[i][j];
        }
        cout << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  } else if(A == 1) {

    for(int i = 1; i < N; i++) {
      g[0][i] = true;
      g[i][0] = true;
    }

    for(int i = 1; i < N; i++) {
      if(B > 1) {
        g[0][i] = false;
        g[i][0] = false;
        --B;
      }
    }


    cout << "YES" << endl;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        if(i == j) cout << 0;
        else cout << 1 - g[i][j];
      }
      cout << endl;
    }

  } else if(B == 1) {

    for(int i = 1; i < N; i++) {
      g[0][i] = true;
      g[i][0] = true;
    }
    for(int i = 1; i < N; i++) {
      if(A > 1) {
        g[0][i] = false;
        g[i][0] = false;
        --A;
      }
    }


    cout << "YES" << endl;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        cout << g[i][j];
      }
      cout << endl;
    }


  } else {
    cout << "NO" << endl;
  }
}