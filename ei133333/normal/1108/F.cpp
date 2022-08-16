#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

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
  cin >> N >> M;
  map< int, vector< pair< int, int > > > mp;
  for(int i = 0; i < M; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    --x, --y;
    mp[z].emplace_back(x, y);
  }
  UnionFind uf(N);
  int ret = 0;
  for(auto &vs : mp) {
    vector< int > contain;
    int add = 0;
    for(auto &p : vs.second) {
      p.first = uf.find(p.first);
      p.second = uf.find(p.second);
      if(p.first == p.second) continue;
      contain.emplace_back(p.first);
      contain.emplace_back(p.second);
    }
    for(int i = 0; i < contain.size(); i += 2) {
      ret += 1 - uf.unite(contain[i], contain[i + 1]);
    }
  }
  cout << ret << endl;
}