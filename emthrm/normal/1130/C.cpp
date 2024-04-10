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
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, r1, c1, r2, c2; cin >> n >> r1 >> c1 >> r2 >> c2; --r1; --c1; --r2; --c2;
  vector<vector<char> > planet(n, vector<char>(n));
  vector<pair<int, int> > land, zero{{r1, c1}};
  REP(i, n) REP(j, n) {
    cin >> planet[i][j];
    if (planet[i][j] == '0') land.emplace_back(i, j);
  }
  vector<vector<long long> > dist(n, vector<long long>(n, LINF));
  dist[r1][c1] = 0;
  queue<pair<int, int> > que;
  que.emplace(r1, c1);
  while (!que.empty()) {
    auto a = que.front(); que.pop();
    REP(i, 4) {
      int y = a.first + dy[i], x = a.second + dx[i];
      if (0 <= y && y < n && 0 <= x && x < n && dist[y][x] == LINF && planet[y][x] == '0') {
        dist[y][x] = 0;
        zero.emplace_back(y, x);
        que.emplace(y, x);
      }
    }
  }
  for (auto e : zero) {
    for (auto ll : land) {
      int y = ll.first, x = ll.second;
      if (dist[y][x] == 0) continue;
      dist[y][x] = min(dist[y][x], (long long)abs(y-e.first)*abs(y-e.first)+abs(x-e.second)*abs(x-e.second));
    }
  }
  long long ans = dist[r2][c2];
  vector<vector<bool> > used(n, vector<bool>(n, false));
  used[r2][c2] = true;
  que.emplace(r2, c2);
  while (!que.empty()) {
    auto a = que.front(); que.pop();
    REP(i, 4) {
      int y = a.first + dy[i], x = a.second + dx[i];
      if (0 <= y && y < n && 0 <= x && x < n && !used[y][x] && planet[y][x] == '0') {
        used[y][x] = true;
        ans = min(ans, dist[y][x]);
        que.emplace(y, x);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}