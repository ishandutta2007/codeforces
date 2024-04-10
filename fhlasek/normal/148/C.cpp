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

int res[1111],R=0;

int main(int argc, char *argv[]){
  int n,a,b; 
  scanf("%d%d%d",&n,&a,&b);
  res[R++] = 1;
  if(!b && a) res[R++] = 1;
  REP(i,b) res[R++] = 1<<(i+1);
  REP(i,a) res[R++] = res[R-1]+1;
  if(R>n) printf("-1\n");
  else{
    while(R<n) res[R++]=1;
    REP(i,n){
      if(i) printf(" ");
      printf("%d",res[i]);
    }
    printf("\n");
  }
  return 0;
}