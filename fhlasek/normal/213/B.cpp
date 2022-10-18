/* Writen by Filip Hlasek 2012 */
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
#define MAXN 500

int comb[MAXN][MAXN];

int N, a[11];
int dp[11][MAXN];

int main(int argc, char *argv[]){
  REP(i, MAXN) REP(j, MAXN){
    if(i == j || j == 0) comb[i][j] = 1;
    else if(j < i) comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
  }

  scanf("%d", &N);
  REP(i,10) scanf("%d", a+i);

  int sum = 0;
  REP(i, 10) sum += a[i];
  int ans = 0;
  FOR(first,1,9) if(a[first]){
    a[first]--;
    FOR(len, sum - 1, N - 1){
      REP(i,11) REP(k,len+1) dp[i][k] = 0;
      dp[0][0] = 1;
      REP(i,10) REP(j,len+1) FOR(k,a[i],len-j) dp[i+1][j+k] = (dp[i+1][j+k] + (long long) dp[i][j] * comb[len-j][k]) % MOD;
      ans = (ans + dp[10][len]) % MOD;
    }
    a[first]++;
  }
  else{
    FOR(len, sum , N - 1){
      REP(i,11) REP(k,len+1) dp[i][k] = 0;
      dp[0][0] = 1;
      REP(i,10) REP(j,len+1) FOR(k,a[i],len-j) dp[i+1][j+k] = (dp[i+1][j+k] + (long long) dp[i][j] * comb[len-j][k]) % MOD;
      ans = (ans + dp[10][len]) % MOD;
    }

  }
  printf("%d\n", ans);

  return 0;
}