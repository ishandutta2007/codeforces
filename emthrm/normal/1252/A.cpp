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
    vector<pair<string, int> > OO, OI, IO, II;
    REP(i, n) {
      string s; cin >> s;
      if (s.front() == '0') {
        (s.back() == '0' ? OO : OI).emplace_back(s, i);
      } else {
        (s.back() == '0' ? IO : II).emplace_back(s, i);
      }
    }
    if (!OO.empty() && OI.empty() && IO.empty() && !II.empty()) {
      cout << -1 << '\n';
      continue;
    }
    bool odd = (OI.size() + IO.size()) & 1;
    if (OI.size() < IO.size()) swap(OI, IO);
    set<string> st;
    for (auto &pr : IO) st.emplace(pr.first);
    vector<int> ans;
    // cout << OI.size() << ' ' << IO.size() << '\n';
    int tmp = 0;
    while (!OI.empty() && OI.size() + tmp > st.size() + odd) {
      string rev = OI.back().first;
      reverse(ALL(rev));
      if (st.count(rev) == 0) {
        st.emplace(rev);
        ans.emplace_back(OI.back().second);
      } else {
        ++tmp;
      }
      OI.pop_back();
    }
    if (OI.size() + tmp > st.size() + odd) {
      cout << -1 << '\n';
      continue;
    }
    sort(ALL(ans));
    cout << ans.size() << '\n';
    REP(i, ans.size()) cout << ans[i] + 1 << " \n"[i + 1 == ans.size()];
  }
  return 0;
}