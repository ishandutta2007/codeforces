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
  int q; cin >> q;
  while (q--) {
    int n; long long k; cin >> n >> k;
    string s; cin >> s;
    int one = 0;
    string ans = "";
    REP(i, n) {
      if (s[i] == '0') {
        if (k >= one) {
          k -= one;
          ans += '0';
        } else {
          REP(_, one - k) ans += '1';
          ans += '0';
          REP(_, k) ans += '1';
          one = 0;
          k = 0;
        }
      } else {
        ++one;
      }
    }
    while (one--) ans += '1';
    cout << ans << '\n';
  }
  return 0;
}