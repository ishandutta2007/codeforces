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
    vector<int> p(n); REP(i, n) cin >> p[i];
    sort(ALL(p), greater<int>());
    int x, a, y, b; cin >> x >> a >> y >> b;
    vector<int> price(n + 1, 0);
    sort(ALL(price));
    for (int i = a; i <= n; i += a) price[i] += x;
    for (int i = b; i <= n; i += b) price[i] += y;
    // FOR(i, 1, n + 1) cout << price[i] << ' ';
    // cout << '\n';
    long long k; cin >> k;
    int lb = 0, ub = n;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      priority_queue<pair<int, int> > que;
      FOR(i, 1, mid + 1) que.emplace(price[i], i);
      vector<long long> ans(mid + 1);
      REP(i, mid) {
        auto pr = que.top(); que.pop();
        ans[pr.second] = p[i];
      }
      long long cont = 0;
      FOR(i, 1, mid + 1) cont += ans[i] / 100 * price[i];
      (cont >= k ? ub : lb) = mid;
    }
    priority_queue<pair<int, int> > que;
    FOR(i, 1, ub + 1) que.emplace(price[i], i);
    vector<long long> ans(ub + 1);
    REP(i, ub) {
      auto pr = que.top(); que.pop();
      // cout << p[i] << ' ' << pr.first << ' ' << pr.second << ':';
      ans[pr.second] = p[i];
    }
    // FOR(i, 1, ub + 1) cout << ans[i] << ' ';
    // cout << '\n';
    long long cont = 0;
    FOR(i, 1, ub + 1) cont += ans[i] / 100 * price[i];
    cout << (cont >= k ? ub : -1) << '\n';
  }
  return 0;
}