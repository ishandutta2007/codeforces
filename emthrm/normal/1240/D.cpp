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
#include <stack>
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
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    vector<int> a(n); REP(i, n) cin >> a[i];
    vector<int> nxt(n, INF);
    vector<map<int, int> > nxtX(n);
    for (int i = n - 1; i >= 0; --i) {
      if (i + 1 < n) {
        if (a[i] == a[i + 1]) {
          nxt[i] = i + 1;
        } else if (nxtX[i + 1].count(a[i]) == 1) {
          nxt[i] = nxtX[i + 1][a[i]];
        }
      }
      if (nxt[i] + 1 < n) {
        swap(nxtX[i], nxtX[nxt[i] + 1]);
        nxtX[i][a[nxt[i] + 1]] = nxt[i] + 1;
      }
      nxtX[i][a[i]] = i;
    }
    vector<long long> dp(n + 1, 0);
    for (int i = n - 2; i >= 0; --i) {
      if (nxt[i] != INF) dp[i] = dp[nxt[i] + 1] + 1;
    }
    cout << accumulate(ALL(dp), 0LL) << '\n';
  }
  return 0;
}