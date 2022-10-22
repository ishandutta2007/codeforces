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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  string ideal = "";
  REP(i, k - 1) ideal += "()";
  REP(i, n / 2 - (k - 1)) ideal += '(';
  REP(i, n / 2 - (k - 1)) ideal += ')';
  vector<int> ls, rs;
  REP(i, n) {
    if (s[i] != ideal[i]) {
      FOR(j, i + 1, n) {
        if (s[j] == ideal[i]) {
          ls.emplace_back(i);
          rs.emplace_back(j);
          reverse(s.begin() + i, s.begin() + j + 1);
          break;
        }
      }
    }
  }
  // cout << s << '\n';
  int sz = ls.size();
  cout << sz << '\n';
  REP(i, sz) cout << ls[i] + 1 << ' ' << rs[i] + 1 << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}