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
  vector<int> a(m), b(m); REP(i, m) cin >> a[i] >> b[i];
  int x = a.front(), y = 0;
  bool ans = true;
  REP(i, m) {
    if (a[i] == x || b[i] == x) {
      continue;
    } else if (y == 0) {
      y = a[i];
      FOR(j, i + 1, m) {
        if (a[j] != x && a[j] != y && b[j] != x && b[j] != y) {
          ans = false;
          break;
        }
      }
      if (ans) {
        cout << "YES\n";
        return 0;
      }
      ans = true;
      y = b[i];
      FOR(j, i + 1, m) {
        if (a[j] != x && a[j] != y && b[j] != x && b[j] != y) {
          ans = false;
          break;
        }
      }
      if (ans) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  if (ans) {
    cout << "YES\n";
    return 0;
  }
  x = b.front(); y = 0;
  ans = true;
  REP(i, m) {
    if (a[i] == x || b[i] == x) {
      continue;
    } else if (y == 0) {
      y = a[i];
      FOR(j, i + 1, m) {
        if (a[j] != x && a[j] != y && b[j] != x && b[j] != y) {
          ans = false;
          break;
        }
      }
      if (ans) {
        cout << "YES\n";
        return 0;
      }
      ans = true;
      y = b[i];
      FOR(j, i + 1, m) {
        if (a[j] != x && a[j] != y && b[j] != x && b[j] != y) {
          ans = false;
          break;
        }
      }
      if (ans) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << (ans ? "YES\n" : "NO\n");
  return 0;
}