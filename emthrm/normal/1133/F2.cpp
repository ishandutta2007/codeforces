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

  int n, m, d; cin >> n >> m >> d;
  int jisu = 0;
  vector<vector<int> > edge(n + 1);
  while (m--) {
    int v, u; cin >> v >> u;
    if (v == 1 || u == 1) ++jisu;
    edge[v].emplace_back(u);
    edge[u].emplace_back(v);
  }
  if (jisu < d) {
    cout << "NO\n";
    return 0;
  }
  vector<bool> used(n + 1, false);
  used[1] = true;
  vector<int> memo;
  for (int e : edge[1]) if (!used[e]) {
    queue<pair<int, int> > que;
    used[e] = true;
    que.emplace(1, e);
    while (!que.empty()) {
      auto au = que.front(); que.pop();
      for (int ee : edge[au.second]) if (ee != au.first) {
        if (used[ee]) {
          if (ee == 1) memo.emplace_back(au.second);
        } else {
          used[ee] = true;
          que.emplace(au.second, ee);
        }
      }
    }
  }
  if (jisu - memo.size() > d) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  vector<bool> can_cat(n + 1, false);
  REP(i, jisu - d) can_cat[memo[i]] = true;
  used.assign(n + 1, false);
  used[1] = true;
  queue<int> que;
  vector<int> ans1, ans2;
  for (int e : edge[1]) if (!can_cat[e]) {
    que.push(e);
    used[e] = true;
    ans1.emplace_back(1);
    ans2.emplace_back(e);
  }
  while (!que.empty()) {
    int ver = que.front(); que.pop();
    for (int e : edge[ver]) if (!used[e]) {
      ans1.emplace_back(ver);
      ans2.emplace_back(e);
      used[e] = true;
      que.push(e);
    }
  }
  int sz = ans1.size();
  REP(i, sz) cout << ans1[i] << ' ' << ans2[i] << '\n';
  return 0;
}