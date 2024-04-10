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
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};

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
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    // cout << s.length() << '\n';
    vector<bool> ok(26, false);
    for (int i = 0; i < s.length();) {
      if (i + 1 >= s.length()) {
        // cout << s[i] << '\n';
        ok[s[i] - 'a'] = true;
        break;
      } else if (s[i] == s[i + 1]) {
        i += 2;
      } else {
        ok[s[i] - 'a'] = true;
        ++i;
      }
      // cout << i << '\n';
    }
    REP(i, 26) {
      if (ok[i]) cout << char('a' + i);
    }
    cout << '\n';
  }
  return 0;
}