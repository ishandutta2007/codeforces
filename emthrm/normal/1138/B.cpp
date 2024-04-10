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

  int n; cin >> n;
  vector<char> c(n), a(n);
  REP(i, n) cin >> c[i];
  REP(i, n) cin >> a[i];
  vector<int> oo, io, oi, ii;
  int OO, IO, OI, II;
  OO = IO = OI = II = 0;
  REP(i, n) {
    if (c[i] == '0') {
      if (a[i] == '0') {
        ++OO;
        oo.emplace_back(i + 1);
      } else {
        ++OI;
        oi.emplace_back(i + 1);
      }
    } else if (a[i] == '0') {
      ++IO;
      io.emplace_back(i + 1);
    } else {
      ++II;
      ii.emplace_back(i + 1);
    }
  }
  REP(i, n / 2 + 1) {
    if (IO + II < i || OI + II < i || II > i * 2 || IO + OI + II < 2 * i) continue;
    vector<int> ans;
    int cnt = 0, IOIO = IO, OIOI = OI, IIII = II, OOOO = OO;
    vector<int> ioio = io, oioi = oi, iiii = ii, oooo = oo;
    while (OI + II > i && cnt < i && II > 0) {
      ans.emplace_back(ii.back());
      ii.pop_back();
      --II;
      ++cnt;
    }
    while (cnt < i && IO > 0) {
      ans.emplace_back(io.back());
      io.pop_back();
      --IO;
      ++cnt;
    }
    while (cnt < n / 2 && OI + II > i && OI > 0) {
      ans.emplace_back(oi.back());
      oi.pop_back();
      --OI;
      ++cnt;
    }
    while (cnt < n / 2 && OO > 0) {
      ans.emplace_back(oo.back());
      oo.pop_back();
      --OO;
      ++cnt;
    }
    if (cnt != n / 2 || OI + II != i) {
      IO = IOIO, OI = OIOI, II = IIII, OO = OOOO;
      io = ioio, oi = oioi, ii = iiii, oo = oooo;
      continue;
    }
    REP(i, n / 2) cout << ans[i] << (i == n / 2 - 1 ? '\n' : ' ');
    return 0;
  }
  cout << -1 << '\n';
  return 0;
}