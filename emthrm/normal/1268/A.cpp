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
  int n, k; cin >> n >> k;
  vector<int> a(n);
  REP(i, n) {
    char c; cin >> c;
    a[i] = c - '0';
  }
  vector<int> b(n);
  REP(i, k) b[i] = a[i];
  FOR(i, k, n) b[i] = b[i - k];
  bool ok = true;
  REP(i, n) {
    if (a[i] > b[i]) {
      ok = false;
      break;
    } else if (a[i] < b[i]) {
      break;
    }
  }
  if (!ok) {
    ++b[k - 1];
    for (int i = k - 1; i >= 0; --i) {
      if (b[i] == 10) {
        ++b[i - 1];
        b[i] = 0;
      }
    }
    FOR(i, k, n) b[i] = b[i - k];
  }
  cout << n << '\n';
  REP(i, n) cout << b[i];
  cout << '\n';
  return 0;
}