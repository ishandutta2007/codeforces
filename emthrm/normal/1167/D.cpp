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

  int n; cin >> n;
  string s; cin >> s;
  int lb = 0, ub = n / 2;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    int r = 0, b = 0, mx = 0;
    for (char c : s) {
      if (c == '(') {
        if (r < mid) ++r;
        else ++b;
      } else {
        if (r > 0) --r;
        else --b;
      }
      mx = max({mx, r, b});
    }
    (mx <= mid ? ub : lb) = mid;
  }
  string ans = "";
  int r = 0;
  for (char c : s) {
    if (c == '(') {
      if (r < ub) {
        ans += '0';
        ++r;
      } else {
        ans += '1';
      }
    } else {
      if (r > 0) {
        ans += '0';
        --r;
      } else {
        ans += '1';
      }
    }
  }
  cout << ans << '\n';
  return 0;
}