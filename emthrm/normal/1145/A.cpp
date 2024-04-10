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
int a[1 << 16], ans = 1;
void calc(int s, int t) {
  if (s + 1 == t) return;
  bool ok = true;
  FOR(i, s + 1, t) {
    if (a[i - 1] > a[i]) {
      ok = false;
      break;
    }
  }
  if (ok) {
    ans = max(ans, t - s);
  } else {
    calc(s, (s + t) / 2);
    calc((s + t) / 2, t);
  }
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  REP(i, n) cin >> a[i];
  calc(0, n);
  cout << ans << '\n';
  return 0;
}