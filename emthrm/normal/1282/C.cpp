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

#define int long long
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
signed main() {
  int t; cin >> t;
  while (t--) {
    vector<int> tm;
    int n, T, a, b; cin >> n >> T >> a >> b;
    tm.emplace_back(0);
    tm.emplace_back(T);
    vector<int> type(n), t(n);
    int easy = 0, hard = 0;
    REP(i, n) {
      cin >> type[i];
      ++(type[i] == 0 ? easy : hard);
    }
    REP(i, n) {
      cin >> t[i];
      tm.emplace_back(max(t[i] - 1, 0LL));
    }
    sort(ALL(tm));
    tm.erase(unique(ALL(tm)), tm.end());
    vector<vector<int> > det(tm.size());
    REP(i, n) det[lower_bound(ALL(tm), t[i]) - tm.begin()].emplace_back(i);
    long long mandatory = 0;
    int ans = 0, required = 0;
    REP(i, tm.size()) {
      for (int e : det[i]) {
        if (type[e] == 0) {
          --easy;
          mandatory += a;
        } else {
          --hard;
          mandatory += b;
        }
        ++required;
      }
      if (mandatory > tm[i]) continue;
      int solved = required, rem = tm[i] - mandatory;
      solved += min(easy, rem / a);
      rem -= min(easy, rem / a) * a;
      solved += min(hard, rem / b);
      ans = max(ans, solved);
    }
    cout << ans << '\n';
  }
  return 0;
}