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

  int n, q; cin >> n >> q;
  int mx = 0;
  vector<int> a(n);
  REP(i, n) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  int goal = 0;
  REP(i, n) {
    if (a[i] == mx) {
      goal = i;
      break;
    }
  }
  vector<int> ans1(goal), ans2(goal);
  int sento = 0, nx = 1;
  REP(i, goal) {
    ans1[i] = a[sento];
    ans2[i] = a[nx];
    if (a[sento] > a[nx]) {
      a.emplace_back(a[nx]);
      a[nx] = -1;
    } else {
      a.emplace_back(a[sento]);
      a[sento] = -1;
      sento = nx;
    }
    ++nx;
    // cout << sento << ' ' << nx << '|';
    // for (int e : a) cout << e << ' ';
    // cout << '\n';
  }
  vector<int> guruguru;
  for (int e : a) {
    if (e != -1) guruguru.emplace_back(e);
  }
  while (q--) {
    long long m; cin >> m;
    if (m <= goal) {
      cout << ans1[m - 1] << ' ' << ans2[m - 1] << '\n';
    } else {
      m -= goal;
      cout << guruguru.front() << ' ' << guruguru[(m % (n - 1) == 0 ? n - 1 : m % (n - 1))] << '\n';
    }
  }
  return 0;
}