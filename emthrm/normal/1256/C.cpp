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
  int n, m, d; cin >> n >> m >> d;
  vector<int> c(m); REP(i, m) cin >> c[i];
  vector<int> l(m);
  int pos = 0;
  REP(i, m) {
    pos += d;
    l[i] = pos;
    pos += c[i] - 1;
  }
  if (pos + d <= n) {
    cout << "NO\n";
    return 0;
  }
  vector<int> ans(l);
  int last = n + 1;
  for (int i = m - 1; i >= 0; --i) {
    if (ans[i] + c[i] - 1 >= last) {
      ans[i] = last - c[i];
    }
    last = ans[i];
  }
  vector<int> plats(n + 1, 0);
  REP(i, m) {
    FOR(j, ans[i], ans[i] + c[i]) plats[j] = i + 1;
  }
  cout << "YES\n";
  FOR(i, 1, n + 1) cout << plats[i] << (i == n ? '\n' : ' ');
  return 0;
}