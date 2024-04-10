#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
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
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1},
//           dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
/*-------------------------------------------------*/
int main() {
  int n, a; cin >> n >> a;
  vector<vector<int> > mai(a);
  vector<int> mai_par(a, -1);
  FOR(i, 1, a) {
    int p; cin >> p; --p;
    mai[p].emplace_back(i);
    mai_par[i] = p;
  }
  vector<int> x(n);
  REP(i, n) {
    cin >> x[i]; --x[i];
  }
  vector<vector<int> > mai_wires(n, vector<int>(n, 0));
  REP(i, n) {
    int cnt = 0;
    vector<int> deg(a, 0);
    FOR(j, i, n) {
      int now = x[j];
      while (now != 0 && deg[now] == mai[now].size()) {
        ++cnt;
        now = mai_par[now];
        ++deg[now];
      }
      mai_wires[i][j] = cnt;
    }
  }
  int b; cin >> b;
  vector<vector<int> > res(b);
  vector<int> res_par(b, -1);
  FOR(i, 1, b) {
    int p; cin >> p; --p;
    res[p].emplace_back(i);
    res_par[i] = p;
  }
  vector<int> y(n);
  REP(i, n) {
    cin >> y[i]; --y[i];
  }
  vector<vector<int> > res_wires(n, vector<int>(n, 0));
  REP(i, n) {
    int cnt = 0;
    vector<int> deg(b, 0);
    FOR(j, i, n) {
      int now = y[j];
      while (now != 0 && deg[now] == res[now].size()) {
        ++cnt;
        now = res_par[now];
        ++deg[now];
      }
      res_wires[i][j] = cnt;
    }
  }
  vector<int> dp(n, 0);
  REP(i, n) REP(j, i + 1) dp[i] = max(dp[i], (j - 1 >= 0 ? dp[j - 1] : 0) + max(mai_wires[j][i], res_wires[j][i]));
  cout << dp[n - 1] << '\n';
  return 0;
}