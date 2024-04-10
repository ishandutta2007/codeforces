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

  vector<int> cnt(4); REP(i, 4) cin >> cnt[i];
  if (cnt[2] > 0) {
    if (cnt[0] == 0 || cnt[3] == 0) {
      cout << 0 << '\n';
      return 0;
    }
  }
  if (cnt[0] != cnt[3]) {
    cout << 0 << '\n';
    return 0;
  }
  cout << 1 << '\n';
  return 0;
}