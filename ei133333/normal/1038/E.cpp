#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
using vi = vector< int64 >;

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
  int N;
  vector< int > G[4][4];
  int add[4] = {};

  cin >> N;
  for(int i = 0; i < N; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    --x, --z;
    if(x > z) swap(x, z);
    G[x][z].push_back(y);
    add[x]++;
    add[z]++;
  }
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      sort(begin(G[i][j]), end(G[i][j]));
      reverse(begin(G[i][j]), end(G[i][j]));
    }
  }

  int ans = 0;
  for(int x = 0; x < 4; x++) {
    for(int y = 0; y < 4; y++) {

      int deleted = 0;
      if(G[x][y].size()) {
        deleted = G[x][y].back();
        --add[x];
        --add[y];
        G[x][y].pop_back();
      }

      UnionFind uf(4);
      for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
          if(G[i][j].size()) uf.unite(i, j);
        }
      }

      for(int i = 0; i < 4; i++) {
        if(uf.find(i) == i) {
          vector< int > beet;
          for(int j = 0; j < 4; j++) {
            if(uf.find(j) == i) beet.push_back(j);
          }

          int sum = 0, sub = 0;
          for(auto &p : beet) if(add[p] & 1) ++sub;
          for(auto &p : beet) {
            for(auto &q : beet) sum += accumulate(begin(G[p][q]), end(G[p][q]), 0);
          }
          if(sub <= 2) ans = max(ans, sum);

        }
      }

      if(deleted > 0) {
        ++add[x];
        ++add[y];
        G[x][y].emplace_back(deleted);
      }
    }
  }
  cout << ans << endl;
}