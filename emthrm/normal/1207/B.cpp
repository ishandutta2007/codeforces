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
/*-------------------------------------------------*/
const int dy[] = {1,1,0,0,-1,-1,-1,-1,0,0,1,1};
const int dx[] = {0,-1,-1,-1,-1,0,0,1,1,1,1,0};

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  vector<vector<int> > a(n, vector<int>(m)), b(n, vector<int>(m, 0));
  REP(i, n) REP(j, m) cin >> a[i][j];
  vector<int> ans_y, ans_x;
  REP(i, n) REP(j, m) if (a[i][j] == 1) {
    int idx = -1;
    for (int k = 0; k < 12; k += 3) {
      bool ok = true;
      FOR(l, k, k + 3) {
        int y = i + dy[l], x = j + dx[l];
        if (y < 0 || n <= y || x < 0 || m <= x || a[y][x] == 0) ok = false;
      }
      if (ok) {
        idx = k;
        break;
      }
    }
    if (idx == -1) {
      cout << -1 << '\n';
      return 0;
    }
    if (idx == 0) {
      ans_y.emplace_back(i);
      ans_x.emplace_back(j - 1);
    } else if (idx == 3) {
      ans_y.emplace_back(i - 1);
      ans_x.emplace_back(j - 1);
    } else if (idx == 6) {
      ans_y.emplace_back(i - 1);
      ans_x.emplace_back(j);
    } else {
      ans_y.emplace_back(i);
      ans_x.emplace_back(j);
    }
  }
  int sz = ans_y.size();
  cout << sz << '\n';
  REP(i, sz) cout << ans_y[i] + 1 << ' ' << ans_x[i] + 1 << '\n';
  return 0;
}