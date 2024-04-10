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
int main() {
  const int N = 1000000;
  int d; cin >> d;
  vector<bool> office(N + 1, false), already(N + 1, false);
  vector<int> used;
  int cnt = 0;
  vector<int> ans{0};
  REP(i, d) {
    int c; cin >> c;
    if (c > 0) {
      if (already[c] || office[c]) {
        cout << -1 << '\n';
        return 0;
      }
      office[c] = true;
      ++cnt;
    } else if (c < 0) {
      c *= -1;
      if (!office[c]) {
        cout << -1 << '\n';
        return 0;
      }
      office[c] = false;
      already[c] = true;
      used.emplace_back(c);
      --cnt;
    }
    if (cnt == 0) {
      ans.emplace_back(i + 1);
      for (int e : used) already[e] = false;
      used.clear();
    }
  }
  if (cnt > 0) {
    cout << -1 << '\n';
    return 0;
  }
  int sz = ans.size();
  cout << sz - 1 << '\n';
  FOR(i, 1, sz) cout << ans[i] - ans[i - 1] << (i + 1 == sz ? '\n' : ' ');
  return 0;
}