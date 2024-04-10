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

  int n, k; cin >> n >> k;
  vector<vector<int> > a(200001, vector<int>(20, 0));
  REP(i, n) {
    int ai; cin >> ai;
    ++a[ai][0];
  }
  for (int i = 200000; i >= 0; --i) {
    int nx = i * 2;
    if (nx > 200000) continue;
    REP(j, 19) a[i][j + 1] += a[nx][j];
    ++nx;
    if (nx > 200000) continue;
    REP(j, 19) a[i][j + 1] += a[nx][j];
  }
  long long ans = LINF;
  REP(i, 200001) {
    int cnt = 0;
    long long cost = 0;
    REP(j, 20) {
      if (cnt + a[i][j] < k) {
        cnt += a[i][j];
        cost += a[i][j] * j;
      } else {
        cost += (k - cnt) * j;
        cnt += k - cnt;
        break;
      }
    }
    if (cnt == k) ans = min(ans, cost);
  }
  cout << ans << '\n';
  return 0;
}