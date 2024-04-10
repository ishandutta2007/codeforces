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

  int n; cin >> n;
  if (n % 2 == 0) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  vector<int> ans(2 * n);
  REP(i, n) {
    int here = i * 2 + 1 + (i % 2 == 0 ? 0 : 1);
    ans[i] = here;
    ans[n + i] = here + (i % 2 == 0 ? 1 : -1);
  }
  REP(i, 2 * n) cout << ans[i] << (i + 1 == 2 * n ? '\n' : ' ');
  return 0;
}