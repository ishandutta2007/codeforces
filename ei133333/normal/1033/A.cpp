#include<bits/stdc++.h>

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
  int N, AX, AY, BX, BY, CX, CY;
  cin >> N;
  cin >> AX >> AY;
  cin >> BX >> BY;
  cin >> CX >> CY;
  --AX, --AY, --BX, --BY, --CX, --CY;
  bool v[1000][1000] = {{}};
  for(int i = 0; i < N; i++) v[AY][i] = true;
  for(int i = 0; i < N; i++) v[i][AX] = true;
  for(int i = -1; i <= 1; i++) {
    for(int j = -1; j <= 1; j++) {
      int ny = AY + i, nx = AX + j;
      if(0 <= ny && ny < N && 0 <= nx && nx < N) v[ny][nx] = true;
    }
  }
  for(int i = -2 * N; i <= 2 * N; i++) {
    int ny = AY + i, nx = AX + i;
    if(0 <= ny && ny < N && 0 <= nx && nx < N) v[ny][nx] = true;
    ny = AY - i, nx = AX + i;
    if(0 <= ny && ny < N && 0 <= nx && nx < N) v[ny][nx] = true;
  }
  UnionFind uf(N * N);
  for(int k = 0; k < N; k++) {
    for(int l = 0; l < N; l++) {
      for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
          int ny = k + i, nx = l + j;
          if(0 <= ny && ny < N && 0 <= nx && nx < N) {
            if(!v[k][l] && !v[ny][nx]) {
              uf.unite(k * N + l, ny * N + nx);
            }
          }
        }
      }
    }
  }
  if(uf.find(BY * N + BX) == uf.find(CY * N + CX))cout << "YES\n";
  else cout << "NO\n";
}