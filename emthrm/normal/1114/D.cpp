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
int dp[5000][5000][2]; // dp[i][j][L/R]

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<int> c(n); REP(i, n) cin >> c[i];
  FOR(width, 1, n) {
    for (int i = 0; i + width < n; ++i) {
      int j = i + width;
      dp[i][j][0] = min(dp[i+1][j][0] + (c[i] == c[i+1] ? 0 : 1), dp[i+1][j][1] + (c[i] == c[j] ? 0 : 1));
      dp[i][j][1] = min(dp[i][j-1][0] + (c[i] == c[j] ? 0 : 1), dp[i][j-1][1] + (c[j-1] == c[j] ? 0 : 1));
    }
  }
  cout << min(dp[0][n-1][0], dp[0][n-1][1]) << '\n';
  return 0;
}