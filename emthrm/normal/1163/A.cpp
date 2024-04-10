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
#include <random>
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

  int n, m; cin >> n >> m;
  if (m == 0) {
    cout << 1 << '\n';
    return 0;
  }
  --n; --m;
  vector<bool> exist(n, true);
  for (int i = 1; i < n && m > 0; i += 2) {
    exist[i] = false;
    --m;
  }
  for (int i = ((n-1)&1?n-2:n-1); i >= 0 && m > 0; i -= 2) {
    exist[i] = false;
    --m;
  }
  int ans = 0;
  bool iru = false;
  REP(i, n) {
    if (iru && !exist[i]) {
      ++ans;
      iru = false;
    }
    if (exist[i]) iru = true;
  }
  if (iru) ++ans;

  cout << ans << '\n';
  return 0;
}