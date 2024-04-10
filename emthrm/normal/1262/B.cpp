
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
  vector<int> q(n); REP(i, n) cin >> q[i];
  set<int> st;
  FOR(i, 1, n + 1) st.emplace(i);
  vector<int> p(n, -1);
  p[0] = q[0];
  st.erase(q[0]);
  FOR(i, 1, n) {
    if (q[i - 1] < q[i]) {
      p[i] = q[i];
      st.erase(q[i]);
    }
  }
  REP(i, n) {
    if (p[i] == -1) {
      p[i] = *st.begin();
      if (p[i] > q[i]) {
        cout << -1 << '\n';
        return;
      }
      st.erase(p[i]);
    }
  }
  REP(i, n) cout << p[i] << (i + 1 == n ? '\n' : ' ');
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}