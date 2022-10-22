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
  vector<vector<int> > a(n, vector<int>(m)); REP(i, n) REP(j, m) cin >> a[i][j];
  vector<int> yo(n), ta(m);
  vector<vector<int> > ko(n, vector<int>(m)), te(n, vector<int>(m));
  REP(i, n) {
    vector<int> tmp;
    REP(j, m) tmp.emplace_back(a[i][j]);
    sort(ALL(tmp));
    tmp.erase(unique(ALL(tmp)), tmp.end());
    yo[i] = tmp.size();
    REP(j, m) ko[i][j] = lower_bound(ALL(tmp), a[i][j]) - tmp.begin() + 1;
  }
  REP(j, m) {
    vector<int> tmp;
    REP(i, n) tmp.emplace_back(a[i][j]);
    sort(ALL(tmp));
    tmp.erase(unique(ALL(tmp)), tmp.end());
    ta[j] = tmp.size();
    REP(i, n) te[i][j] = lower_bound(ALL(tmp), a[i][j]) - tmp.begin() + 1;
  }
  vector<vector<int> > ans(n, vector<int>(m));
  REP(i, n) REP(j, m) {
    if (ko[i][j] > te[i][j]) ans[i][j] = max(yo[i], ta[j] + ko[i][j] - te[i][j]);
    else if (ko[i][j] < te[i][j]) ans[i][j] = max(yo[i] + te[i][j] - ko[i][j], ta[j]);
    else ans[i][j] = max(yo[i], ta[j]);
  }
  REP(i, n) {
    REP(j, m) cout << ans[i][j] << (j == m - 1 ? '\n' : ' ');
  }
  return 0;
}