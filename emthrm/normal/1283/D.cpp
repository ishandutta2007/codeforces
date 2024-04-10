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
#include <iomanip>
#include <iostream>
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
  const int Y = 2000000000;
  int n, m; cin >> n >> m;
  vector<int> x(n + 1, -INF); FOR(i, 1, n + 1) cin >> x[i];
  sort(ALL(x));
  using P = pair<int, int>;
  priority_queue<P, vector<P>, greater<P> > que;
  set<int> used;
  FOR(i, 1, n + 1) used.emplace(x[i]);
  FOR(i, 1, n + 1) {
    if (used.count(x[i] + 1) == 0) que.emplace(1, i);
    if (used.count(x[i] - 1) == 0) que.emplace(1, -i);
  }
  long long ans = 0;
  vector<int> y(m);
  for (int i = 0; i < m;) {
    int dist, idx; tie(dist, idx) = que.top(); que.pop();
    if (idx < 0) {
      y[i] = x[-idx] - dist;
      if (used.count(y[i]) == 1) continue;
      used.emplace(y[i]);
      ans += dist;
      if (y[i] - 1 >= -Y && used.count(y[i] - 1) == 0) que.emplace(dist + 1, idx);
    } else {
      y[i] = x[idx] + dist;
      if (used.count(y[i]) == 1) continue;
      used.emplace(y[i]);
      ans += dist;
      if (y[i] + 1 <= Y && used.count(y[i] + 1) == 0) que.emplace(dist + 1, idx);
    }
    ++i;
  }
  cout << ans << '\n';
  REP(i, m) cout << y[i] << " \n"[i + 1 == m];
  return 0;
}