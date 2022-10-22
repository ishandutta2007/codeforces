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
    int n; cin >> n;
    map<int, int> mp;
    REP(_, n) {
      int p; cin >> p;
      ++mp[-p];
    }
    vector<int> par;
    for (auto it = mp.begin(); it != mp.end(); ++it) par.emplace_back((*it).second);
    int ans_g = 0, ans_s = 0, ans_b = 0;
    int g = par[0], s = 0, b = 0, g_r = 1, s_r, b_r;
    for (s_r = g_r; s_r < par.size();) {
      s += par[s_r++];
      if (g < s) break;
    }
    for (b_r = s_r; b_r < par.size();) {
      b += par[b_r++];
      if (g < b) break;
    }
    if (g >= s || g >= b || g + s + b > n / 2) {
      cout << ans_g << ' ' << ans_s << ' ' << ans_b << '\n';
      continue;
    }
    for (; b_r < par.size();) {
      if (g + s + b + par[b_r] <= n / 2) {
        b += par[b_r++];
      } else {
        break;
      }
    }
    cout << g << ' ' << s << ' ' << b << '\n';
  }
  return 0;
}