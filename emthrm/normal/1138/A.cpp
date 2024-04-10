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
  vector<int> sushi;
  int now; cin >> now;
  int cnt = 1;
  FOR(i, 1, n) {
    int t; cin >> t;
    if (now != t) {
      sushi.emplace_back(cnt);
      now = t;
      cnt = 1;
    } else {
      ++cnt;
    }
  }
  sushi.emplace_back(cnt);
  int ans = 0, sz = sushi.size();
  REP(i, sz - 1) {
    ans = max(ans, min(sushi[i], sushi[i + 1]) * 2);
  }
  cout << ans << '\n';
  return 0;
}