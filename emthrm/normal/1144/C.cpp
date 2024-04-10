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
  sort(ALL(a));
  vector<int> inc, dec;
  int now = -1;
  REP(i, n) {
    if (now < a[i]) {
      inc.emplace_back(a[i]);
      now = a[i];
    } else {
      dec.emplace_back(a[i]);
    }
  }
  int p = inc.size();
  FOR(i, 1, p) {
    if (inc[i - 1] >= inc[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  int q = dec.size();
  FOR(i, 1, q) {
    if (dec[i - 1] >= dec[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  reverse(ALL(dec));
  cout << "YES\n" << p << '\n';
  if (p == 0) {
    cout << '\n';
  } else {
    REP(i, p) cout << inc[i] << (i == p - 1 ? '\n' : ' ');
  }
  cout << q << '\n';
  if (q == 0) {
    cout << '\n';
  } else {
    REP(i, q) cout << dec[i] << (i == q - 1 ? '\n' : ' ');
  }
  return 0;
}