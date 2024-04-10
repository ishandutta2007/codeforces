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
#include <sstream>
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
long long dp[1000001][3][3];

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  map<int, int> mp;
  REP(i, n) {
    int a; cin >> a;
    ++mp[a];
  }
  REP(i, m) REP(j, 3) REP(k, 3) REP(l, 3) {
    if (j + k + l > mp[i+1]) continue;
    dp[i+1][k][l] = max(dp[i+1][k][l], dp[i][j][k] + l + (mp[i+1] - j - k - l) / 3);
  }
  cout << dp[m][0][0] << '\n';
  return 0;
}