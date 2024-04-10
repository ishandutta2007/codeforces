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
  while (n--) {
    string s, t; cin >> s >> t;
    vector<char> schar, tchar; vector<int> snum, tnum;
    char now = s.front();
    int cnt = 1;
    for (char c : s) {
      if (c != now) {
        schar.emplace_back(now);
        snum.emplace_back(cnt);
        now = c;
        cnt = 1;
      } else {
        ++cnt;
      }
    }
    schar.emplace_back(now);
    snum.emplace_back(cnt);
    now = t.front();
    cnt = 1;
    for (char c : t) {
      if (c != now) {
        tchar.emplace_back(now);
        tnum.emplace_back(cnt);
        now = c;
        cnt = 1;
      } else {
        ++cnt;
      }
    }
    tchar.emplace_back(now);
    tnum.emplace_back(cnt);
    if ((int)schar.size() != (int)tchar.size()) {
      cout << "NO\n";
      continue;
    }
    int sz = schar.size();
    bool ok = true;
    REP(i, sz) {
      if (schar[i] != tchar[i]) {
        ok = false;
        break;
      }
      if (tnum[i] < snum[i]) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}