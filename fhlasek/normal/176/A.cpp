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

int N,M,K;
char name[111];
int a[111][111],b[111][111],c[111][111];
int best;
int profit[111], provide[111];
int dp[111][111];

int get(int f, int pos){
  if(pos == M) return 0;
  if(dp[f][pos] != -1) return dp[f][pos];
  dp[f][pos] = 0;
  REP(i,provide[pos]+1) if(f+i <= K) dp[f][pos] = max(dp[f][pos], profit[pos] * i + get(f+i, pos+1));
  return dp[f][pos];
}

void solve(int x,int y){
  REP(i,M) profit[i] = b[y][i] - a[x][i];
  REP(i,M) provide[i] = c[x][i];
  REP(i,111) REP(j,111) dp[i][j] = -1;
  best = max(best, get(0,0));
}

int main(int argc, char *argv[]){
  scanf("%d%d%d",&N,&M,&K);
  best = 0;
  REP(i,N){
    scanf("%s",name);
    REP(j,M) scanf("%d%d%d",&(a[i][j]),&(b[i][j]),&(c[i][j]));
  }
  REP(i,N) REP(j,N) solve(i,j);   
  printf("%d\n",best);
  return 0;
}