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
  vector<long long> three{1};
  REP(_, 38) three.emplace_back(three.back() * 3);
  int m = three.size();
  vector<long long> sum(m - 1);
  sum[0] = three[0];
  FOR(i, 1, m - 1) sum[i] = sum[i - 1] + three[i];
  int q; cin >> q;
  while (q--) {
    long long n; cin >> n;
    int idx = lower_bound(ALL(three), n) - three.begin();
    long long ans = three[idx];
    if (idx - 1 >= 0 && sum[idx - 1] >= n) {
      ans = 0;
      for (int i = idx - 1; i >= 0; --i) {
        if (i - 1 >= 0 && ans + sum[i - 1] >= n) continue;
        ans += three[i];
        if (ans >= n) break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}