#include <algorithm>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f, MOD = 1000000007;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*-----------------------------------------*/
struct UnionFind {
  UnionFind(int sz) : data(sz, -1) {}

  int root(int ver) { return data[ver] < 0 ? ver : data[ver] = root(data[ver]); }

  void unite(int ver1, int ver2) {
    ver1 = root(ver1);
    ver2 = root(ver2);
    if (ver1 != ver2) {
      if (data[ver1] > data[ver2]) swap(ver1, ver2);
      data[ver1] += data[ver2];
      data[ver2] = ver1;
    }
  }

  bool same(int ver1, int ver2) { return root(ver1) == root(ver2); }

  int size(int ver) { return -data[root(ver)]; }

private:
  vector<int> data;
};

long long mod_pow(long long base, long long exponent, long long mod = MOD) {
  base %= mod;
  long long res = 1;
  while (exponent > 0) {
    if (exponent & 1) (res *= base) %= mod;
    (base *= base) %= mod;
    exponent >>= 1;
  }
  return res;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, k; cin >> n >> k;
  UnionFind uf(n);
  REP(i, n - 1) {
    int u, v, x; cin >> u >> v >> x; --u; --v;
    if (x == 0) uf.unite(u, v);
  }
  long long dame = 0;
  vector<int> cnt(n, 0);
  REP(i, n) ++cnt[uf.root(i)];
  REP(i, n) if (cnt[i] > 0) {
    (dame += mod_pow(cnt[i], k)) %= MOD;
  }
  long long ans = mod_pow(n, k);
  (ans -= dame) %= MOD;
  if (ans < 0) ans += MOD;
  cout << ans << '\n';
  return 0;
}