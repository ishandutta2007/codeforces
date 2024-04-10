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
long long __lcm(long long a, long long b) { return a / __gcd(a, b) * b; }

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, k, a, b; cin >> n >> k >> a >> b;
  long long nk = (long long)n * k, mn = INF, mx = 1, mae = k - a - b, ushiro = k - a + b;
  REP(i, n) {
    long long g1 = __gcd(nk, mae), g2 = __gcd(nk, ushiro);
    mn = min({mn, g1, g2});
    mx = max({mx, g1, g2});
    mae += k;
    ushiro += k;
  }
  cout << nk / mx << ' ' << nk / mn << '\n';
}