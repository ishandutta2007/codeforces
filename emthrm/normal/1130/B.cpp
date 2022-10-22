#include <algorithm>
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
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f, MOD = 1000000007;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*-----------------------------------------*/
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<bool> bought(n + 1, false);
  vector<int> sasha(n + 1, 0), dima(n + 1, 0);
  REP(i, 2 * n) {
    int a; cin >> a;
    if (!bought[a]) {
      bought[a] = true;
      sasha[a] = i;
    } else {
      dima[a] = i;
    }
  }
  long long ans = 0;
  REP(i, n) ans += abs(sasha[i] - sasha[i + 1]) + abs(dima[i] - dima[i + 1]);
  cout << ans << '\n';
  return 0;
}