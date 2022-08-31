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
  int H, W, K;
  string S[53];
  cin >> H >> W >> K;

  S[0] = S[H + 1] = string(W + 2, '.');
  for(int i = 1; i <= H; i++) {
    cin >> S[i];
    S[i] = "." + S[i] + ".";
  }

  H += 2;
  W += 2;

  UnionFind tree(H * W);
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(j > 0 && S[i][j - 1] == '.' && S[i][j] == '.') tree.unite(i * W + j, i * W + j - 1);
      if(i > 0 && S[i - 1][j] == '.' && S[i][j] == '.') tree.unite(i * W + j, i * W + j - W);
    }
  }

  map< int, int > curr;
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(S[i][j] == '.' && tree.find(i * W + j) != tree.find(0)) {
        curr[tree.find(i * W + j)]++;
      }
    }
  }
  vector< pair< int, int > > rev;
  for(auto& k : curr) rev.emplace_back(k.second, k.first);
  sort(begin(rev), end(rev));

  int ike = rev.size();
  int now = 0;
  int sz = 0;
  while(ike > K) {
    --ike;
    auto obj = rev[now++];
    for(int i = 0; i < H; i++) {
      for(int j = 0; j < W; j++) {
        if(tree.find(i * W + j) == obj.second) {
          S[i][j] = '*';
          ++sz;
        }
      }
    }
  }
  cout << sz << endl;
  for(int i = 1; i < H - 1; i++) {
    cout << S[i].substr(1, W - 2) << endl;
  }
}