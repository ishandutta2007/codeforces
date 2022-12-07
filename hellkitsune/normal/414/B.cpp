#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

const int mod = 1e9 + 7;

int n, k;
int dp[2003][2003];
vector<int> v[2003];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    dp[1][i] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j * j <= i; ++j) if (i % j == 0) {
      v[i].pb(j);
      if (j * j != i)
        v[i].pb(i / j);
    }
  }
  for (int i = 2; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = 0;
      REP(t, v[j].size())
        dp[i][j] = (dp[i][j] + dp[i - 1][v[j][t]]) % mod;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    ans = (ans + dp[k][i]) % mod;
  cout << ans << endl;
  return 0;
}