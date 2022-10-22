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
  int n; cin >> n;
  vector<pair<long long, int> > ue, shita;
  FOR(i, 2, n) {
    cout << "2 1 2 " << i + 1 << endl;
    int sign; cin >> sign;
    cout << "1 1 2 " << i + 1 << endl;
    long long area; cin >> area;
    (sign == 1 ? ue : shita).emplace_back(area, i);
  }
  int u = -1;
  vector<int> ue1, ue2;
  if (!ue.empty()) {
    sort(ALL(ue));
    u = ue.back().second;
    REP(i, ue.size() - 1) {
      cout << "2 1 " << u + 1 << ' ' << ue[i].second + 1 << endl;
      int sign; cin >> sign;
      (sign == 1 ? ue2 : ue1).emplace_back(ue[i].second);
    }
  }
  reverse(ALL(ue2));
  int v = -1;
  vector<int> shita1, shita2;
  if (!shita.empty()) {
    sort(ALL(shita));
    v = shita.back().second;
    REP(i, shita.size() - 1) {
      cout << "2 1 " << v + 1 << ' ' << shita[i].second + 1 << endl;
      int sign; cin >> sign;
      (sign == 1 ? shita2 : shita1).emplace_back(shita[i].second);
    }
  }
  reverse(ALL(shita2));
  vector<int> ans{0};
  for (int e : shita1) ans.emplace_back(e);
  if (v != -1) ans.emplace_back(v);
  for (int e : shita2) ans.emplace_back(e);
  ans.emplace_back(1);
  for (int e : ue1) ans.emplace_back(e);
  if (u != -1) ans.emplace_back(u);
  for (int e : ue2) ans.emplace_back(e);
  cout << "0 ";
  REP(i, n) {
    cout << ans[i] + 1;
    if (i + 1 < n) cout << ' ';
  }
  cout << endl;
  return 0;
}