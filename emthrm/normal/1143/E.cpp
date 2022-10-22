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
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m, q; cin >> n >> m >> q;
  vector<int> p(n), a(m); REP(i, n) cin >> p[i]; REP(i, m) cin >> a[i];
  vector<vector<int> > idx(n + 1);
  REP(i, m) idx[a[i]].emplace_back(i);
  vector<vector<int> > nx(19, vector<int>(m));
  REP(i, n) {
    int src = p[i], dst = p[(i + 1) % n];
    for (int e : idx[src]) {
      nx[0][e] = lower_bound(ALL(idx[dst]), e) - idx[dst].begin();
      nx[0][e] = (nx[0][e] == idx[dst].size() ? m : idx[dst][nx[0][e]]);
    }
  }
  REP(i, 18) REP(j, m) {
    nx[i + 1][j] = (nx[i][j] == m ? m : nx[i][nx[i][j]]);
  }
  vector<int> right(m);
  REP(i, m) {
    int pos = i;
    REP(j, 19) {
      if (((n - 1) >> j & 1) && pos < m) pos = nx[j][pos];
    }
    right[i] = pos;
  }
  for (int i = m - 2; i >= 0; --i) right[i] = min(right[i], right[i + 1]);
  while (q--) {
    int l, r; cin >> l >> r; --l; --r;
    cout << (right[l] <= r ? 1 : 0);
  }
  cout << '\n';
  return 0;
}