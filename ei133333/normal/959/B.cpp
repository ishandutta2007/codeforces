#include <bits/stdc++.h>

using namespace std;

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

using int64 = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int N, K, M;
  cin >> N >> K >> M;
  vector< string > words(N);
  map< string, int > mp;
  for(int i = 0; i < N; i++) {
    cin >> words[i];
    mp[words[i]] = i;
  }
  vector< int > S(N);
  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }
  UnionFind uf(N);
  for(int i = 0; i < K; i++) {
    int p;
    cin >> p;
    vector< int > sz(p);
    for(int j = 0; j < p; j++) {
      cin >> sz[j];
      --sz[j];
    }
    for(int j = 1; j < p; j++) {
      uf.unite(sz[j - 1], sz[j]);
    }
    for(int j = 0; j < p; j++) {
      S[uf.find(sz[j])] = min(S[uf.find(sz[j])], S[sz[j]]);
    }
  }
  int64 ret = 0;
  for(int i = 0; i < M; i++) {
    string x;
    cin >> x;
    ret += S[uf.find(mp[x])];
  }
  cout << ret << endl;
}