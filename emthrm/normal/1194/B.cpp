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
    int r, c; cin >> r >> c;
    vector<vector<char> > pic(r, vector<char>(c)); REP(i, r) REP(j, c) cin >> pic[i][j];
    vector<int> yoko(r, 0), tate(c, 0);
    REP(i, r) REP(j, c) if (pic[i][j] == '*') {
      ++yoko[i];
      ++tate[j];
    }
    int ans = INF;
    REP(i, r) {
      int nokori = c - yoko[i];
      REP(j, c) {
        if (pic[i][j] == '.') ans = min(ans, nokori + r - tate[j] - 1);
        else ans = min(ans, nokori + r - tate[j]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}