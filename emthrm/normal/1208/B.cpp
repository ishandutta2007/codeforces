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
#include <numeric>
#include <queue>
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
  int ans = 0;
  REP(i, n) {
    set<int> st;
    REP(j, i) {
      if (st.count(a[j]) == 1) {
        cout << n - ans << '\n';
        return 0;
      }
      st.emplace(a[j]);
    }
    for (int j = n - 1; j >= i; --j) {
      if (st.count(a[j]) == 1) {
        ans = max(ans, i + n - 1 - j);
        break;
      }
      st.emplace(a[j]);
      if (j == i) ans = n;
    }
  }
  cout << n - ans << '\n';
  return 0;
}