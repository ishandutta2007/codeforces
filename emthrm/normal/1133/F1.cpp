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
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  vector<int> jisu(n + 1, 0);
  vector<vector<int> > edge(n + 1);
  while (m--) {
    int v, u; cin >> v >> u;
    ++jisu[v];
    ++jisu[u];
    edge[v].emplace_back(u);
    edge[u].emplace_back(v);
  }
  int mx = 0, vertex;
  FOR(i, 1, n + 1) {
    if (jisu[i] > mx) {
      vertex = i;
      mx = jisu[i];
    }
  }
  vector<bool> used(n + 1, false);
  queue<int> que;
  que.push(vertex);
  used[vertex] = true;
  while (!que.empty()) {
    int ver = que.front(); que.pop();
    for (int e : edge[ver]) if (!used[e]) {
      cout << ver << ' ' << e << '\n';
      que.push(e);
      used[e] = true;
    }
  }
  return 0;
}