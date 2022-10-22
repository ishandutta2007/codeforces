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
  int n; cin >> n;
  vector<pair<pair<long long, long long>, long long> > masters(n + 1);
  REP(i, n) {
    long long a, b, t; cin >> a >> b >> t;
    masters[i] = {{a, b}, t};
  }
  masters[n] = {{LINF, LINF}, LINF};
  sort(ALL(masters));
  using P = pair<long long, long long>;
  priority_queue<P, vector<P>, greater<P> > que;
  long long now = 0, ans = 0;
  for (auto e : masters) {
    long long a = e.first.first, b = e.first.second, t = e.second;
    while (!que.empty()) {
      long long len = que.top().first, lim = que.top().second;
      if (lim <= now) {
        que.pop();
        continue;
      } else if (lim <= a) {
        long long swords = (lim - now) / len;
        now += swords * len;
        ans += swords;
      } else {
        long long swords = (a - now) / len;
        now += swords * len;
        ans += swords;
        if (now + len <= lim) {
          que.emplace(len - (a - now), now + len);
          now = a;
          break;
        }
      }
      que.pop();
    }
    now = a;
    que.emplace(t, b);
  }
  cout << ans << '\n';
  return 0;
}