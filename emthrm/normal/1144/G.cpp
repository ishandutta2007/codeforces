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
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<bool> ans(n, false);
  int mx = INF, mn = -1;
  REP(i, n) {
    if (mn < a[i] && mx > a[i]) {
      if (i < n - 1) {
        if (a[i] < a[i + 1]) {
          mn = a[i];
          ans[i] = false;
        } else {
          mx = a[i];
          ans[i] = true;
        }
      }
    } else if (mn < a[i]) {
      mn = a[i];
      ans[i] = false;
    } else if (mx > a[i]) {
      mx = a[i];
      ans[i] = true;
    } else {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  REP(i, n) cout << (ans[i] ? 1 : 0) << (i == n - 1 ? '\n' : ' ');
  return 0;
}