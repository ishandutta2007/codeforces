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
  vector<int> a(n); REP(i, n) cin >> a[i];
  sort(ALL(a));
  int ans = 0;
  FOR(i, 2, 200000) {
    int tmp = 0, mae = 0, ushiro = n - 1;
    while (ushiro > mae) {
      int now = a[mae] + a[ushiro];
      if (now > i) {
        --ushiro;
      } else if (now == i) {
        ++mae;
        --ushiro;
        ++tmp;
      } else {
        ++mae;
      }
    }
    ans = max(ans, tmp);
  }
  cout << ans << '\n';
  return 0;
}