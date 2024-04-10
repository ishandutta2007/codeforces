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
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    if (s.length() <= 2) {
      cout << 0 << '\n';
      continue;
    }
    vector<int> ans;
    for (int i = 0; i < s.length() - 2;) {
      if (s.substr(i, 3) == "one") {
        ans.emplace_back(i + 1);
        i += 3;
      } else if (s.substr(i, 3) == "two") {
        if (i + 4 < s.length() && s.substr(i + 2, 3) == "one") {
          ans.emplace_back(i + 2);
          i += 5;
        } else {
          ans.emplace_back(i + 1);
          i += 3;
        }
      } else {
        ++i;
      }
    }
    // string result = s;
    // for (int i = int(ans.size()) - 1; i >= 0; --i) {
    //   result.erase(result.begin() + ans[i]);
    // }
    // cout << result << '\n';
    cout << ans.size() << '\n';
    REP(i, ans.size()) cout << ans[i] + 1 << " \n"[i + 1 == ans.size()];
  }
  return 0;
}