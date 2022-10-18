/* Written by Filip Hlasek 2012 */
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

#define MAXN 55
int N, a[MAXN], P;
double dp[MAXN][MAXN][MAXN];

double fac(int n){
  double ans = 1;
  REP(i, n) ans *= (i + 1);
  return ans;
}

int main(int argc, char *argv[]){
  scanf("%d", &N);
  REP(i, N) scanf("%d", a + i);
  scanf("%d", &P);
  dp[0][0][0] = 1;
  REP(i, N) FOR(in, 0, N) FOR(p, 0, P) if(dp[i][in][p]){
    dp[i+1][in][p] += dp[i][in][p];
    if(p + a[i] <= P) dp[i+1][in+1][p+a[i]] += dp[i][in][p];
  }
  double tmp = 0, ans = 0, sum;
  FORD(in, N, 0){
    sum = 0;
    FOR(p, 0, P) sum += dp[N][in][p];
    sum *= fac(in) * fac(N-in);
    ans += in * (sum - tmp);
    tmp = sum;
  }
  printf("%.9lf\n", ans / fac(N));
  return 0;
}