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
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

#define MAXN 555555
#define C 26
int a[MAXN], b[MAXN], l[MAXN], N;
char name[C];
int dp[C];

int main(int argc, char *argv[]){
  scanf("%d",&N);
  REP(i,N){
    scanf("%s", name);
    l[i] = strlen(name);
    a[i] = name[0] - 'a';
    b[i] = name[l[i]-1] - 'a';
  }
  int ans = 0;
  REP(c,C){
    REP(j,C) dp[j] = -20*N;
    dp[c] = 0;
    REP(i,N) dp[b[i]] = max(dp[b[i]], dp[a[i]] + l[i]); 
    ans = max(ans, dp[c]);
  }
  printf("%d\n",ans);
  return 0;
}