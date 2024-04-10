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

  int n, m; cin >> n >> m;
  vector<vector<int> > a(n, vector<int>(m)), b(n, vector<int>(m));
  REP(i, n) REP(j, m) cin >> a[i][j];
  REP(i, n) REP(j, m) cin >> b[i][j];
  vector<vector<bool> > trans(n, vector<bool>(m));
  REP(i, n) REP(j, m) {
    if (a[i][j] == b[i][j]) trans[i][j] = false;
    else trans[i][j] = true;
  }
  REP(i, n) {
    int cnt = 0;
    REP(j, m) {
      if (trans[i][j]) ++cnt;
    }
    if (cnt & 1) {
      cout << "No\n";
      return 0;
    }
  }
  REP(j, m) {
    int cnt = 0;
    REP(i, n) {
      if (trans[i][j]) ++cnt;
    }
    if (cnt & 1) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}