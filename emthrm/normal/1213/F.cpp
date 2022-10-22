#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
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
/*-------------------------------------------------*/
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, k; cin >> n >> k; --k;
  vector<int> p(n), q(n);
  map<int, int> mp;
  REP(i, n) {
    cin >> p[i]; --p[i];
    mp[p[i]] = i;
  }
  vector<int> idx(n);
  iota(ALL(idx), 0);
  REP(i, n) {
    cin >> q[i]; --q[i];
  }
  REP(i, n - 1) {
    int u = mp[q[i]], v = mp[q[i + 1]];
    idx[v] = max(idx[v], u);
  }
  vector<char> ans(n);
  char now = 'a';
  int mx = 0;
  REP(i, n) {
    ans[p[i]] = now;
    mx = max(mx, idx[i]);
    if (mx == i && now + 1 <= 'a' + k) ++now;
  }
  char mxmx = 'a';
  REP(i, n) mxmx = max(mxmx, ans[i]);
  if (mxmx != 'a' + k) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    REP(i, n) cout << ans[i];
    cout << '\n';
  }
  return 0;
}