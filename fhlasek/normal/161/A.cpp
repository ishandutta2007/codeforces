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

#define MAXN 111111
int a[MAXN],b[MAXN],resa[MAXN],resb[MAXN],R = 0;

int main(int argc, char *argv[]){
  int N,M,x,y,posa=0,posb=0; 
  scanf("%d%d%d%d",&N,&M,&x,&y);
  REP(i,N) scanf("%d",a+i);
  REP(i,M) scanf("%d",b+i);
  while(posa<N&&posb<M){
    if(a[posa] - x <= b[posb] && b[posb] <= a[posa] + y){
      resa[R] = posa++;
      resb[R++] = posb++;
    }
    else{
      if(a[posa] - x > b[posb]) posb++;
      else posa++;
    }
  }
  printf("%d\n",R);
  REP(i,R) printf("%d %d\n",resa[i]+1,resb[i]+1);
  return 0;
}