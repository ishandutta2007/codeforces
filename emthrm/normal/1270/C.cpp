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
    long long sum = 0, x = 0;
    while (n--) {
      int a; cin >> a;
      sum += a;
      x ^= a;
    }
    if (sum == x * 2) {
      cout << 0 << '\n';
      continue;
    }
    vector<long long> b{x};
    sum += x;
    int l = 0;
    REP(i, 62) {
      if (sum >> i & 1) l = i;
    }
    long long diff = (1LL << (l + 2)) - sum;
    long long b1 = (1LL << (l + 1)), b2 = 0;
    diff -= b1;
    assert(diff % 2 == 0);
    b1 += diff / 2;
    b2 += diff / 2;
    b.emplace_back(b1);
    b.emplace_back(b2);
    cout << b.size() << '\n';
    REP(i, b.size()) cout << b[i] << " \n"[i + 1 == b.size()];
  }
  return 0;
}