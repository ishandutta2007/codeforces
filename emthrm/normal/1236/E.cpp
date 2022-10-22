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
/*-------------------------------------------------*/
int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  if (n == 1) {
    cout << 0 << '\n';
    return 0;
  }
  vector<int> a(m);
  REP(i, m) {
    cin >> a[i]; --a[i];
  }
  long long ans = 0;
  vector<int> r(n + m + 1, 0);
  REP(i, n) r[i + m + 1] = 1; // 
  REP(i, m) {
    int idx = a[i] + m + 1 - (i + 1);
    r[idx - 1] += r[idx];
    r[idx] = 0;
  }
  // REP(i, n + m + 1) cout << r[i] << ' ';
  // cout << '\n';
  REP(i, n) ans += n - 1 - i;
  REP(i, n) ans -= (long long)r[i] * (n - 1 - i);
  vector<int> l(n + m + 1, 0);
  REP(i, n) l[i] = 1;
  REP(i, m) {
    int idx = a[i] - (m + 1) + (i + 1) + m + 1;
    l[idx + 1] += l[idx];
    l[idx] = 0;
  }
  REP(i, n) ans += i;
  FOR(i, m + 1, n + m + 1) ans -= (long long)l[i] * (i - (m + 1));
  cout << ans + n << '\n';
  return 0;
}