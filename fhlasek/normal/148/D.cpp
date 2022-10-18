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

double dp[1111][1111];

double prob(int w,int b,bool princess){
  if(w==0) return 0;
  if(b==0) return princess;
  if(dp[w][b]>-0.5) return dp[w][b];
  if(princess) dp[w][b] = (double)w/(w+b) + (double)b/(w+b) * prob(w,b-1,false);
  else dp[w][b] = (double)b/(w+b)*((b>1?(double)(b-1)/(w+b-1)*prob(w,b-2,true):0) + (double)w/(w+b-1)*prob(w-1,b-1,true));
  return dp[w][b];
}

int main(int argc, char *argv[]){
  int W,B; 
  scanf("%d%d",&W,&B);
  REP(i,W+1) REP(j,B+1) dp[i][j] = -1;
  printf("%.12lf\n",prob(W,B,true));
  return 0;
}