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
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int x1, y1, x2, y2, n; cin >> x1 >> y1 >> x2 >> y2 >> n;
  string s; cin >> s;
  int y = 0, x = 0;
  for (char c : s) {
    if (c == 'U') --y;
    else if (c == 'D') ++y;
    else if (c == 'L') ++x;
    else --x;
  }
  long long lb = -1, ub = 1e18;
  while (ub - lb > 1) {
    long long mid = (lb + ub) / 2;
    long long turn = mid / n;
    long long yy = turn * y + y2, xx = turn * x + x2;
    long long nokori = mid - turn * n;
    REP(i, nokori) {
      if (s[i] == 'U') --yy;
      else if (s[i] == 'D') ++yy;
      else if (s[i] == 'L') ++xx;
      else --xx;
    }
    (abs(yy-y1)+abs(xx-x1)<=mid ? ub : lb) = mid;
  }
  if (ub == 1e18) {
    long long mid = 1e18;
    long long turn = mid / n;
    long long yy = turn * y + y2, xx = turn * x + x2;
    long long nokori = mid - turn * n;
    REP(i, nokori) {
      if (s[i] == 'U') --yy;
      else if (s[i] == 'D') ++yy;
      else if (s[i] == 'L') ++xx;
      else --xx;
    }
    cout << (abs(yy-y1)+abs(xx-x1)<=mid ? ub : -1) << '\n';
    return 0;
  }
  cout << ub << '\n';
  return 0;
}