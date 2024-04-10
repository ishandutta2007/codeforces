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

#define MAXN 2222
#define MOD 1000000007
int c[MAXN][MAXN];

int main(int argc, char *argv[]){
  REP(i,MAXN) REP(j,MAXN){
    if(i==j || j==0) c[i][j] = 1;
    else{
      if(j>i) c[i][j] = 0;
      else    c[i][j] = (c[i-1][j-1] + c[i-1][j])%MOD;
    }
  }
  int N,M,K;
  scanf("%d%d%d",&N,&M,&K);
  printf("%d\n",(int)(((long long)c[N-1][2*K]*c[M-1][2*K])%MOD));
  return 0;
}