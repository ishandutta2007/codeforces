#include <algorithm>
#include <bitset>
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
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
vector<int> edge[200000];

long long fact[200001];
void init() {
  fact[0] = fact[1] = 1;
  FOR(i, 2, 200001) fact[i] = (fact[i - 1] * i) % MOD;
}

long long ans = 1;
void dfs(int par, int ver) {
  (ans *= fact[edge[ver].size()]) %= MOD;
  for (int e : edge[ver]) if (e != par) {
    dfs(ver, e);
  }
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  init();
  int n; cin >> n;
  REP(i, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
  }
  dfs(-1, 0);
  (ans *= n) %= MOD;
  cout << ans << '\n';
  return 0;
}