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

  string a, b; cin >> a >> b;
  int flag = 0;
  for (char c : b) {
    if (c == '1') ++flag;
  }
  REP(i, (int)b.length() - 1) {
    if (a[i] == '1') ++flag;
  }
  int ans = 0;
  FOR(i, (int)b.length() - 1, a.length()) {
    if (a[i] == '1') ++flag;
    if (flag % 2 == 0) ++ans;
    // cout << flag << '\n';
    if (a[i + 1 - (int)b.length()] == '1') --flag;
  }
  cout << ans << '\n';
  return 0;
}