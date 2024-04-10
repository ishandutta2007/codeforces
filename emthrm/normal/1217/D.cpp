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
vector<pair<int, int> > graph[5000];
bool visited[5000] = {}, calculated[5000] = {};
int ans[5000];

void dfs(int ver) {
  for (auto pr : graph[ver]) {
    if (visited[pr.first]) {
      ans[pr.second] = (calculated[pr.first] ? 1 : 2);
    } else {
      visited[pr.first] = true;
      ans[pr.second] = 1;
      dfs(pr.first);
    }
  }
  calculated[ver] = true;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  REP(i, m) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v, i);
  }
  REP(i, n) {
    if (!visited[i]) {
      visited[i] = true;
      dfs(i);
    }
  }
  cout << (count(ans, ans + m, 2) > 0 ? 2 : 1) << '\n';
  REP(i, m) cout << ans[i] << (i + 1 == m ? '\n' : ' ');
  return 0;
}