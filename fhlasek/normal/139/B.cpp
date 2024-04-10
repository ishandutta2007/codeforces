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

int a[1111],b[1111],c[1111];
int k[1111],l[1111],m[1111];

int main(int argc, char *argv[]){
  int N,M,best,sum=0; 
  scanf("%d",&N);
  REP(i,N) scanf("%d%d%d",a+i,b+i,c+i);
  scanf("%d",&M);
  REP(i,M) scanf("%d%d%d",k+i,l+i,m+i);
  REP(i,N){
    best = 111111111;
    REP(j,M) if(k[j] >= c[i]) best = min(best,(((2*(a[i]+b[i])-1)/l[j])/(k[j]/c[i])+1)*m[j]);
    sum+=best;
  }
  printf("%d\n",sum);
  return 0;
}