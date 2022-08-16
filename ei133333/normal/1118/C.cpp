#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 mod = 1e9 + 7;

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
  cin >> N;

  UnionFind uf(N * N);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      uf.unite(i * N + j, i * N + N - j - 1);
      uf.unite(i * N + j, (N - i - 1) * N + j);
    }
  }
  vector< pair< int, int > > need;
  vector< int > belong[20 * 20];
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      belong[uf.find(i * N + j)].emplace_back(i * N + j);
      if(uf.find(i * N + j) == i * N + j) {
        need.emplace_back(uf.size(i * N + j), i * N + j);
      }
    }
  }

  int sz[1000] = {};
  for(int i = 0; i < N*N; i++) {
    int x;
    cin >> x;
    --x;
    sz[x]++;
  }
  using pi = pair< int, int >;
  priority_queue< pi > que;
  for(int i = 0; i < 1000; i++) {
    que.emplace(sz[i], i);
  }
  sort(need.rbegin(), need.rend());
  int mat[20][20];
  for(auto &p : need) {
    auto q = que.top();
    que.pop();
    sz[q.second] -= p.first;
    if(sz[q.second] < 0) {
      cout << "NO" << endl;
      return 0;
    }
    for(auto t : belong[p.second]) {
      mat[t / N][t % N] = q.second;
    }
    que.emplace(sz[q.second], q.second);
  }
  cout << "YES" << endl;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cout << mat[i][j]+1 << " ";
    }
    cout << endl;
  }


}