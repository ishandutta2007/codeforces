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
  int q; cin >> q;
  while (q--) {
    string s; cin >> s;
    int L = count(ALL(s), 'L');
    int R = count(ALL(s), 'R');
    int U = count(ALL(s), 'U');
    int D = count(ALL(s), 'D');
    int lr = min(L, R), ud = min(U, D);
    string ans = "";
    if (lr == 0 || ud == 0) {
      if (lr > 0) ans = "LR";
      if (ud > 0) ans = "UD";
    } else {
      REP(_, lr) ans += 'R';
      REP(_, ud) ans += 'U';
      REP(_, lr) ans += 'L';
      REP(_, ud) ans += 'D';
    }
    cout << ans.size() << '\n' << ans << '\n';
  }
  return 0;
}