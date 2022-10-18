/* Written by Filip Hlasek 2014 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MOD 1000000007
#define MAXN 333333
vector<int> sons[MAXN];
int N, black[MAXN];
int dp[2][MAXN];

int solve(int v, int has_black) {
  if (dp[has_black][v] != -1) return dp[has_black][v];
  int n = sons[v].size();
  vector<int> ans0, ans1;
  REP(i, n) {
    ans0.push_back(solve(sons[v][i], 0));
    ans1.push_back(solve(sons[v][i], 1));
  }

  int Ans0 = 1, Ans1 = 0;
  REP(i, n) Ans0 = ((long long)Ans0 * ans0[i]) % MOD;
  vector<int> pref0, suff0;
  pref0.push_back(1);
  REP(i, n) pref0.push_back(((long long)pref0[i] * ans0[i]) % MOD);
  suff0.push_back(1);
  REP(i, n) suff0.push_back(((long long)suff0[i] * ans0[n - i - 1]) % MOD);
  REP(i, n) Ans1 = (Ans1 + (long long)pref0[i] * ans1[i] % MOD * suff0[n - 1 - i]) % MOD;

  int ans;
  if (black[v]) ans = Ans0;
  else {
    if (has_black) ans = Ans1;
    else ans = (Ans0 + Ans1) % MOD;
  }

  return dp[has_black][v] = ans;
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N - 1) {
    int p;
    scanf("%d", &p);
    sons[p].push_back(i + 1);
  }
  REP(i, N) scanf("%d", black + i);
  REP(i, N) dp[0][i] = dp[1][i] = -1;
  printf("%d\n", solve(0, 1));
  // REP(i, N) printf("i: %d dp0: %d dp1: %d\n", i, dp[0][i], dp[1][i]);
  return 0;
}