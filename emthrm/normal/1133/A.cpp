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

  int h1, h2, m1, m2; char c; cin >> h1 >> c >> m1 >> h2 >> c >> m2;
  int tmp = (h1 * 60 + m1 + h2 * 60 + m2) / 2;
  int h = tmp / 60, m = tmp % 60;
  if (h < 10) cout << 0;
  cout << h << ':';
  if (m < 10) cout << 0;
  cout << m << '\n';
  return 0;
}