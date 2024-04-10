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

  int n, k; cin >> n >> k;
  vector<int> d;
  int ans = 0;
  REP(i, n) {
    int dd; cin >> dd;
    dd %= k;
    if (dd == 0) ++ans;
    else d.emplace_back(dd);
  }
  ans /= 2;
  sort(ALL(d));
  // for (int e : d) cout << e << '\n';
  int mae = 0, ushiro = d.size() - 1;
  while (mae < ushiro) {
    if (d[mae] + d[ushiro] == k) {
      ++ans;
      ++mae;
      --ushiro;
    } else if (d[mae] + d[ushiro] > k) {
      --ushiro;
    } else {
      ++mae;
    }
  }
  cout << ans * 2 << '\n';
  return 0;
}