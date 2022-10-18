/* Writen by Filip Hlasek 2011 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

#define PI (2*acos(0))

int main(int argc, char *argv[]){
  int N,r,R; 
  scanf("%d%d%d",&N,&R,&r);
  if(r>R){
    printf("NO\n");
    return 0;
  }
  if(2*r>R){
    if(N==1) printf("YES\n");
    else printf("NO\n");
    return 0;
  }
  R-=r;
  double sum=N*asin((double)r/R);
  if(sum-1e-9<PI) printf("YES\n");
  else printf("NO\n");
  return 0;
}