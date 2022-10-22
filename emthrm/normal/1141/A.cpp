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

  int n, m; cin >> n >> m;
  if (m % n != 0) {
    cout << -1 << '\n';
    return 0;
  }
  m /= n;
  int ans = 0;
  while (m % 3 == 0) {
    ++ans;
    m /= 3;
  }
  while (m % 2 == 0) {
    ++ans;
    m /= 2;
  }
  if (m != 1) {
    cout << -1 << '\n';
    return 0;
  }
  cout << ans << '\n';
  return 0;
}