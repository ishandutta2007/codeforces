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

  int n, b, a; cin >> n >> b >> a;
  int battery = b, accumulator = a;
  vector<int> s(n); REP(i, n) cin >> s[i];
  REP(i, n) {
    if (accumulator == 0 && battery == 0) {
      cout << i << '\n';
      return 0;
    }
    if (s[i] == 0) {
      if (accumulator > 0) --accumulator;
      else --battery;
    } else {
      if (battery > 0 && accumulator < a) {
        --battery;
        ++accumulator;
      } else {
        --accumulator;
      }
    }
  }
  cout << n << '\n';
  return 0;
}