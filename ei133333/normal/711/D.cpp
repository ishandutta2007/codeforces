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


const int MOD = 1000000007;

typedef long long int64;

int64 pow_mod(int64 x, int64 n, int64 mod)
{
  int64 ret = 1LL;
  while(n > 0) {
    if(n & 1) (ret *= x) %= mod;
    (x *= x) %= mod;
    n >>= 1;
  }
  return ret;
}

int N;
vector< pair< int, int > > g[200000];
int v[200000];

int roop(int idx, int rev)
{
  for(int i = 0; i < g[idx].size(); i++) {
    if(g[idx][i].second == rev) {
      continue;
    } else if(v[g[idx][i].first] == -1) {
      v[g[idx][i].first] = v[idx] + 1;
      int val = roop(g[idx][i].first, g[idx][i].second);
      if(val >= 0) return (val);
    } else {
      return (v[idx] - v[g[idx][i].first] + 1);
    }
  }
  return (-1);
}

int main()
{
  memset(v, -1, sizeof(v));

  cin >> N;

  UnionFind uf(N);

  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    --a;
    g[a].emplace_back(i, i);
    g[i].emplace_back(a, i);

    uf.unite(a, i);
  }


  int64 ret = 1;

  for(int i = 0; i < N; i++) {
    if(uf.find(i) == i) {
      v[i] = 0;
      int Size = roop(i, -1);
      int64 get1 = pow_mod(2, uf.size(i) - Size, MOD);
      int64 get2 = (pow_mod(2, Size, MOD) - 2 + MOD) % MOD;
      int64 get3 = (get1 * get2) % MOD;
      (ret *= get3) %= MOD;
    }
  }
  cout << ret << endl;
}