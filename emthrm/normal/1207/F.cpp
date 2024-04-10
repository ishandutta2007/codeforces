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
const int N = 500000, SQR = 707;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int q; cin >> q;
  vector<long long> a(N + 1, 0);
  vector<vector<long long> > b(SQR + 1, vector<long long>(SQR, 0));
  while (q--) {
    int t, x, y; cin >> t >> x >> y;
    if (t == 1) {
      a[x] += y;
      FOR(i, 1, SQR + 1) b[i][x % i] += y;
    } else if (t == 2) {
      long long ans = 0;
      if (x > SQR) {
        for (int i = y; i <= N; i += x) if (i >= 1) {
          ans += a[i];
        }
      } else {
        ans += b[x][y];
      }
      cout << ans << '\n';
    }
  }
  return 0;
}