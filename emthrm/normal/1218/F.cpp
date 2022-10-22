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
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; long long k; cin >> n >> k;
  vector<int> x(n), c(n);
  REP(i, n) cin >> x[i];
  int a; cin >> a;
  REP(i, n) cin >> c[i];
  priority_queue<int, vector<int>, greater<int> > que;
  long long ans = 0;
  REP(i, n) {
    que.emplace(c[i]);
    if (k < x[i]) {
      while (k < x[i] && !que.empty()) {
        ans += que.top(); que.pop();
        k += a;
      }
      if (k < x[i]) {
        cout << -1 << '\n';
        return 0;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}