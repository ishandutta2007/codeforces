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

  int n, m; cin >> n >> m;
  vector<vector<int> > a(n, vector<int>(m)), b(n, vector<int>(m));
  REP(i, n) REP(j, m) cin >> a[i][j];
  REP(i, n) REP(j, m) cin >> b[i][j];
  bool ok = true;
  REP(matrix, n + m - 1) {
    vector<int> aa, bb;
    int i = max(matrix - m + 1, 0), j = (matrix < m - 1 ? matrix : m - 1);
    while (i < n && j >= 0) {
      aa.emplace_back(a[i][j]);
      bb.emplace_back(b[i][j]);
      ++i;
      --j;
    }
    sort(ALL(aa));
    sort(ALL(bb));
    int sz = aa.size();
    REP(i, sz) {
      if (aa[i] != bb[i]) {
        ok = false;
        break;
      }
    }
    if (!ok) break;
  }
  cout << (ok ? "YES\n" : "NO\n");
  return 0;
}