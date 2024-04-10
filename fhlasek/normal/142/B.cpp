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

int main(int argc, char *argv[]){
  int N,M;
  scanf("%d%d",&N,&M); 
  if(N==1 || M==1){
    printf("%d\n",N*M);
    return 0;
  }
  int oldres=(N*M+1)/2;
  if(M==2) swap(N,M);
  if(N==2){
    int res = M/4*4;
    M%=4;
    if(M==1) res+=2;
    if(M>1) res+=4;
    printf("%d\n",max(res,oldres));
    return 0;
  }
  printf("%d\n",oldres);
  return 0;
}