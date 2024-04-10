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

  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    vector<int> p(n); REP(i, n) cin >> p[i];
    int start;
    REP(i, n) {
      if (p[i] == 1) start = i;
    }
    bool ok = true;
    int pos = 1;
    FOR(i, start, n) {
      if (p[i] != pos) ok = false;
      ++pos;
    }
    REP(i, start) {
      if (p[i] != pos) ok = false;
      ++pos;
    }
    if (ok) {
      cout << "YES\n";
      continue;
    }
    ok = true;
    pos = 1;
    for (int i = start; i >= 0; --i) {
      if (p[i] != pos) ok = false;
      ++pos;
    }
    for (int i = n - 1; i > start; --i) {
      if (p[i] != pos) ok = false;
      ++pos;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}