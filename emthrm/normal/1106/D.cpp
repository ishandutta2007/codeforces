#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
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
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  vector<vector<int> > edge(n+1);
  REP(i, m) {
    int u, v; cin >> u >> v;
    if (u == v) continue;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  vector<bool> used(n+1, false);
  priority_queue<int, vector<int>, greater<int> > que;
  que.push(1);
  while (!que.empty()) {
    int ver = que.top(); que.pop();
    if (used[ver]) continue;
    cout << ver;
    used[ver] = true;
    for (int e : edge[ver]) if (!used[e]) que.push(e);
    if (que.empty()) cout << '\n';
    else cout << ' ';
  }
  return 0;
}