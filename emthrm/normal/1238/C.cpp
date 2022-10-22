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

  int q; cin >> q;
  while (q--) {
    int h, n; cin >> h >> n;
    vector<int> p(n); REP(i, n) cin >> p[i];
    int ans = 0;
    for (int i = 0; i < n;) {
      if (i == n - 1) break;
      if (p[i] - p[i + 1] >= 2) p[i] = p[i + 1] + 1;
      if (p[i] - 2 <= 0) break;
      if (i + 2 < n && p[i + 1] - 1 == p[i + 2]) {
        i += 2;
      } else {
        ++ans;
        --p[i + 1];
        ++i;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}