#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
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
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1},
//           dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
/*-------------------------------------------------*/
int main() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  queue<int> que;
  vector<vector<int> > graph(n);
  vector<int> ans(n, -1);
  REP(i, n) {
    int x = i - a[i];
    if (x >= 0) {
      if ((a[x] & 1) ^ (a[i] & 1)) {
        ans[i] = 1;
        que.emplace(i);
      } else {
        graph[x].emplace_back(i);
      }
    }
    x = i + a[i];
    if (x < n) {
      if (ans[i] == -1 && ((a[x] & 1) ^ (a[i] & 1))) {
        ans[i] = 1;
        que.emplace(i);
      } else {
        graph[x].emplace_back(i);
      }
    }
  }
  while (!que.empty()) {
    int ver = que.front(); que.pop();
    for (int e : graph[ver]) {
      if (ans[e] == -1) {
        ans[e] = ans[ver] + 1;
        que.emplace(e);
      }
    }
  }
  REP(i, n) cout << ans[i] << " \n"[i + 1 == n];
  return 0;
}