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
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    int mn_x = -1e5, mx_x= 1e5, mn_y = -1e5, mx_y = 1e5;
    while (n--) {
      int x, y; cin >> x >> y;
      vector<int> f(4); REP(i, 4) cin >> f[i];
      if (f[0] == 0) mn_x = max(mn_x, x);
      if (f[3] == 0) mn_y = max(mn_y, y);
      if (f[2] == 0) mx_x = min(mx_x, x);
      if (f[1] == 0) mx_y = min(mx_y, y);
    }
    if (mn_x <= mx_x && mn_y <= mx_y) {
      cout << "1 " << mn_x << ' ' << mn_y << '\n';
    } else {
      cout << 0 << '\n';
    }
  }
  return 0;
}