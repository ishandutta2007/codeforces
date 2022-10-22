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
  const int X = 200000;
  int n, k; cin >> n >> k;
  vector<vector<pair<int, int> > > in(X);
  vector<vector<int> > out(X);
  REP(i, n) {
    int l, r; cin >> l >> r; --l; --r;
    in[l].emplace_back(r, i);
    out[r].emplace_back(i);
  }
  vector<int> ans;
  set<pair<int, int> > st;
  REP(x, X) {
    for (auto e : in[x]) st.emplace(e);
    while (st.size() > k) {
      auto it = prev(st.end());
      ans.emplace_back((*it).second);
      st.erase(it);
    }
    for (int e : out[x]) {
      if (st.count(make_pair(x, e)) == 1) st.erase(make_pair(x, e));
    }
  }
  sort(ALL(ans));
  int sz = ans.size();
  cout << sz << '\n';
  REP(i, sz) cout << ans[i] + 1 << (i + 1 == sz ? '\n' : ' ');
  return 0;
}