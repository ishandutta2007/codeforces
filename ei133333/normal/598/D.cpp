#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

const int vy[] = {1, 0, -1, 0};
const int vx[] = {0, 1, 0, -1};

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
  int N, M, Q;
  string S[1000];
  int d[1000][1000] = {{}};

  cin >> N >> M >> Q;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      for(int k = 0; k < 4; k++) {
        int ni = i + vy[k], nj = j + vx[k];
        if(ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
        d[i][j] += S[ni][nj] == '*';
      }
    }
  }
  UnionFind uf(N * M);
  vector< int > add(N * M);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(i && S[i - 1][j] == '.' && S[i][j] == '.') uf.unite(i * M + j, i * M + j - M);
      if(j && S[i][j - 1] == '.' && S[i][j] == '.') uf.unite(i * M + j, i * M + j - 1);
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      add[uf.find(i * M + j)] += d[i][j];
    }
  }
  while(Q--) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    cout << add[uf.find(x * M + y)] << endl;
  }
}