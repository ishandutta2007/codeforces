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
vector<int> graph[100000];
int depth[100000] = {};

void dfs1(int par, int ver) {
  for (int e : graph[ver]) if (e != par) {
    dfs1(ver, e);
    depth[ver] = max(depth[ver], depth[e] + 1);
  }
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  FOR(i, 1, n) {
    int p; cin >> p; --p;
    graph[p].emplace_back(i);
  }
  dfs1(-1, 0);
  int x = 0;
  REP(i, n) {
    if (depth[i] % 2 == 0) x ^= a[i];
  }
  map<int, long long> blue, red;
  REP(i, n) ++(depth[i] % 2 == 0 ? blue : red)[a[i]];
  long long ans = 0;
  if (x == 0) {
    long long b = 0, r = 0;
    REP(i, n) ++(depth[i] % 2 == 0 ? b : r);
    ans += b * (b - 1) / 2;
    ans += r * (r - 1) / 2;
    for (pair<int, long long> pr : blue) {
      if (red.count(pr.first) == 1) ans += pr.second * red[pr.first];
    }
  } else {
    for (pair<int, long long> pr : blue) {
      if (red.count(x ^ pr.first) == 1) ans += pr.second * red[x ^ pr.first];
    }
  }
  cout << ans << '\n';
  return 0;
}