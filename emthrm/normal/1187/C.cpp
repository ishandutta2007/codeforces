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

  int n, m; cin >> n >> m;
  vector<int> a(n), t1(n), l, r;
  REP(i, n) t1[i] = i;
  while (m--) {
    int t, ll, rr; cin >> t >> ll >> rr; --ll; --rr;
    if (t == 1) {
      t1[ll] = max(t1[ll], rr);
    } else {
      l.emplace_back(ll);
      r.emplace_back(rr);
    }
  }
  int now = 1000, right = 0;
  REP(i, n) {
    right = max(right, t1[i]);
    a[i] = now;
    if (right == i) {
      ++right;
      --now;
    }
  }
  int sz = l.size();
  REP(i, sz) {
    if (a[l[i]] == a[r[i]]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  REP(i, n) cout << a[i] << (i == n - 1 ? '\n' : ' ');
  return 0;
}