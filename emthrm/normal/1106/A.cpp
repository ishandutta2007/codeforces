#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
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
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int m; cin >> m;
  vector<string> x(m); REP(i, m) cin >> x[i];
  int ans = 0;
  FOR(i, 1, m-1) FOR(j, 1, m-1) {
    if (x[i][j] == 'X' && x[i-1][j-1] == 'X' && x[i-1][j+1] == 'X' && x[i+1][j-1] == 'X' && x[i+1][j+1] == 'X') ++ans;
  }
  cout << ans << '\n';
  return 0;
}