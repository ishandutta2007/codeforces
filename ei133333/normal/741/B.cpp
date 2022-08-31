#include <bits/stdc++.h>

using namespace std;

struct UnionFind
{
  vector< int > data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  void unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x != y) {
      if(data[x] > data[y]) swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }
  }

  int find(int k)
  {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k)
  {
    return (-data[find(k)]);
  }
};

int main()
{
  int N, M, W, w[1000], b[1000];

  cin >> N >> M >> W;
  for(int i = 0; i < N; i++) {
    cin >> w[i];
  }
  for(int i = 0; i < N; i++) {
    cin >> b[i];
  }

  UnionFind tree(N);
  while(M--) {
    int A, B;
    cin >> A >> B;
    tree.unite(--A, --B);
  }

  int dp[1000][1001] = {{}};
  vector< vector< pair< int, int > > > kk(N);
  vector< int > roots;
  for(int i = 0; i < N; i++) {
    kk[tree.find(i)].emplace_back(w[i], b[i]);
    if(i == tree.find(i)) roots.push_back(i);
  }

  for(int i = 0; i < roots.size(); i++) {
    int x = 0, y = 0;
    for(auto &a : kk[roots[i]]) {
      x += a.first;
      y += a.second;
    }
    kk[roots[i]].emplace_back(x, y);
    kk[roots[i]].emplace_back(0, 0);
    for(auto &a : kk[roots[i]]) {
      if(a.first > W) continue;
      dp[i][a.first] = max(dp[i][a.first], a.second);
      if(i > 0) {
        for(int j = W - a.first; j >= 0; j--) {
          dp[i][j + a.first] = max(dp[i][j + a.first], dp[i - 1][j] + a.second);
        }
      }
    }
  }

  int ret = 0;
  for(int i = 0; i <= W; i++) ret = max(ret, dp[roots.size() - 1][i]);
  cout << ret << endl;
}