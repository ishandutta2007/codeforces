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

  int n, m; cin >> n >> m;
  vector<vector<int> > a(n, vector<int>(m)); REP(i, n) REP(j, m) cin >> a[i][j];
  int row = -1;
  vector<vector<int> > cop(a);
  REP(i, n) {
    cop[i].erase(unique(ALL(cop[i])), cop[i].end());
    if (cop[i].size() >= 2) row = i;
  }
  if (row != -1) {
    REP(j, m) {
      int how = 0;
      REP(i, n) {
        if (i == row) how ^= a[i][j];
        else how ^= a[i].front();
      }
      if (how > 0) {
        cout << "TAK\n";
        REP(i, n) {
          if (i == row) cout << j + 1;
          else cout << 1;
          cout << (i == m - 1 ? '\n' : ' ');
        }
        break;
      }
    }
  } else {
    int how = 0;
    REP(i, n) how ^= a[i].front();
    if (how == 0) {
      cout << "NIE\n";
    } else {
      cout << "TAK\n";
      REP(i, n) cout << 1 << (i == m - 1 ? '\n' : ' ');
    }
  }
  return 0;
}