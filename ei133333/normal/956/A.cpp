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
  int N, M;
  string S[50];

  cin >> N >> M;
  UnionFind uf(N + M);
  int sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(S[i][j] == '#') {
        uf.unite(i, j + N);
      }
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(uf.find(i) == uf.find(j + N)) {
        if(S[i][j] == '.') {
          puts("No");
          return(0);
        }
      }
    }
  }
  cout << "Yes" << endl;
}