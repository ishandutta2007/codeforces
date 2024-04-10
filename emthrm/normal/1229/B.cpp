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
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <unordered_map>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
long long g(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return __gcd(a, b);
}

long long x[100000], ans = 0;
vector<int> graph[100000];
void dfs(int par, int ver, map<long long, int> &mp) {
  map<long long, int> nx;
  for (auto &pr : mp) {
    long long gc = g(pr.first, x[ver]);
    (ans += gc % MOD * pr.second % MOD) %= MOD;
    nx[gc] += pr.second;
  }
  swap(mp, nx);
  ++mp[x[ver]];
  (ans += x[ver]) %= MOD;
  for (int e : graph[ver]) if (e != par) dfs(ver, e, mp);
  swap(mp, nx);
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  REP(i, n) cin >> x[i];
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  map<long long, int> mp;
  dfs(-1, 0, mp);
  cout << ans << '\n';
  return 0;
}