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

  int h, w; cin >> h >> w;
  vector<vector<char> > pic(h, vector<char>(w));
  int cnt = 0;
  REP(i, h) REP(j, w) {
    cin >> pic[i][j];
    if (pic[i][j] == '*') ++cnt;
  }
  if (cnt >= h + w) {
    cout << "NO\n";
    return 0;
  }
  FOR(i, 1, h - 1) FOR(j, 1, w - 1) if (pic[i][j] == '*') {
    int tmp = 1;
    bool ok = true;
    REP(k, 4) {
      if (pic[i + dy[k]][j + dx[k]] == '.') {
        ok = false;
        break;
      }
    }
    if (!ok) continue;
    for (int k = i - 1; k >= 0; --k) {
      if (pic[k][j] == '.') break;
      else ++tmp;
    }
    FOR(k, i + 1, h) {
      if (pic[k][j] == '.') break;
      else ++tmp;
    }
    for (int k = j - 1; k >= 0; --k) {
      if (pic[i][k] == '.') break;
      else ++tmp;
    }
    FOR(k, j + 1, w) {
      if (pic[i][k] == '.') break;
      else ++tmp;
    }
    if (tmp == cnt) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}