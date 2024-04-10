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
void solve() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  vector<int> diff(n);
  REP(i, n) {
    diff[i] = b[i] - a[i];
    if (diff[i] < 0) {
      cout << "NO\n";
      return;
    }
  }
  if (count(ALL(diff), 0) == n) {
    cout << "YES\n";
    return;
  }
  int l, r;
  for (l = 0; l < n; ++l) {
    if (diff[l] > 0) break;
  }
  for (r = n - 1; r >= 0; --r) {
    if (diff[r] > 0) break;
  }
  FOR(i, l + 1, r + 1) {
    if (diff[i] != diff[l]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}