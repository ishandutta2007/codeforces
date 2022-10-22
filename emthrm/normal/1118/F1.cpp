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
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
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
int a[300000];
vector<vector<int> > edge(300000);
bool r[300000], b[300000];
pair<bool, bool> dfs2(int par, int ver) {
  r[ver] = b[ver] = false;
  for (int v : edge[ver]) if (v != par) {
    auto dou = dfs2(ver, v);
    r[ver] |= dou.first;
    b[ver] |= dou.second;
  }
  if (a[ver] == 1) r[ver] = true;
  if (a[ver] == 2) b[ver] = true;
  return {r[ver], b[ver]};
}

int ans = 0;
void dfs(int par, int ver, bool red, bool blue) {
  // cout << par << ' ' << ver << ' ' << (red?1:0) << ' ' << (blue?1:0) << " | " << ans << '\n';
  int rr = 0, bb = 0, rb = 0, no = 0;
  for (int v : edge[ver]) if (v != par) {
    if (r[v]) {
      if (b[v]) ++rb;
      else ++rr;
    } else if (b[v]) ++bb;
    else ++no;
  }
  if (rb == 0 && !(red && blue) && ((rr == 0 && !red && a[ver] != 1) || (bb == 0 && !blue && a[ver] != 2))) {
    ans += no;
  }
  // cout << ver << ' ' << ans << '\n';
  if (rb == 0 && !(red && blue)) {
    if (bb == 0 && !blue && a[ver] != 2) ans += rr;
    else if (rr == 1) {
      if (a[ver] != 1 && !red) ans += rr;
      else if (bb == 0 && !blue && a[ver] != 2) ans += rr;
    }
    if (rr == 0 && !red && a[ver] != 1) ans += bb;
    else if (bb == 1) {
      if (a[ver] != 2 && !blue) ans += bb;
      else if (rr == 0 && !red && a[ver] != 1) ans += bb;
    }
  }
  // cout << ver << ' ' << ans << '\n';
  bool aka = (a[ver] == 1 ? true : false), ao = (a[ver] == 2 ? true : false);
  for (int v : edge[ver]) if (v != par) {
    if (r[v]) {
      if (b[v]) {
        dfs(ver, v, rr+rb-1||aka||red, bb+rb-1||ao||blue);
      } else {
        dfs(ver, v, rr-1+rb||aka||red, bb+rb||ao||blue);
      }
    } else if (b[v]) {
      dfs(ver, v, rr+rb||aka||red, bb+rb-1||ao||blue);
    } else {
      dfs(ver, v, rr+rb||aka||red, bb+rb||ao||blue);
    }
  }
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  REP(i, n) cin >> a[i];
  REP(i, n-1) {
    int v, u; cin >> v >> u; --v; --u;
    edge[v].emplace_back(u);
    edge[u].emplace_back(v);
  }
  dfs2(-1, 0);
  dfs(-1, 0, false, false);
  cout << ans << '\n';
  return 0;
}