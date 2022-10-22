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
  vector<vector<char> > board(n, vector<char>(n)); REP(i, n) REP(j, n) cin >> board[i][j];
  REP(i, n) REP(j, n) if (board[i][j] == '.') {
    bool cover = true;
    REP(k, 4) {
      int y = i + dy[k], x = j + dx[k];
      if (y < 0 || n <= y || x < 0 || n <= x || board[y][x] == '#') cover = false;
    }
    if (cover) {
      board[i][j] = '#';
      REP(k, 4) {
        int y = i + dy[k], x = j + dx[k];
        board[y][x] = '#';
      }
    }
  }
  bool ok = true;
  REP(i, n) REP(j, n) {
    if (board[i][j] == '.') ok = false;
  }
  cout << (ok ? "YeS\n" : "nO\n");
  return 0;
}