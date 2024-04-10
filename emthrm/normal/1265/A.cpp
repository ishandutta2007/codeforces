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
void solve() {
  string s; cin >> s;
  FOR(i, 1, s.length()) {
    if (s[i] == '?') continue;
    if (s[i] == s[i - 1]) {
      cout << -1 << '\n';
      return;
    }
  }
  REP(i, s.length()) {
    if (s[i] == '?') {
      vector<bool> ok(3, true);
      if (i - 1 >= 0) ok[s[i - 1] - 'a'] = false;
      if (i + 1 < s.length() && s[i + 1] != '?') ok[s[i + 1] - 'a'] = false;
      REP(j, 3) {
        if (ok[j]) {
          s[i] = 'a' + j;
          break;
        }
      }
    }
  }
  cout << s << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}