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
void solve(string &s, char c, char h) {
  vector<int> ans;
  REP(i, s.length() - 1) {
    if (s[i] == c) {
      ans.emplace_back(i);
      s[i] = h;
      s[i + 1] = (s[i + 1] == c ? h : c);
    }
  }
  cout << ans.size() << '\n';
  REP(i, ans.size()) cout << ans[i] + 1 << " \n"[i + 1 == ans.size()];
  exit(0);
}

int main() {
  int n; cin >> n;
  string s; cin >> s;
  if (count(ALL(s), 'W') % 2 == 0) solve(s, 'W', 'B');
  if (count(ALL(s), 'B') % 2 == 0) solve(s, 'B', 'W');
  cout << -1 << '\n';
  return 0;
}