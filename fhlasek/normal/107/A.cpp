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

#define FOR(i,n) for(i=0;i<n;i++)

using namespace std;

int N,P,from[1111],to[1111],d[1111];
int r1[1111],r2[1111],r3[1111];

int main(int argc, char *argv[]){
  scanf("%d%d",&N,&P); 
  int i,A,B,D,t=0,dest,m;
  FOR(i,N){ from[i]=-1; to[i]=-1; }
  FOR(i,P){
    scanf("%d%d%d",&A,&B,&D);
    A--; B--;
    from[B]=A;
    to[A]=B;
    d[A]=D;
  }
  FOR(i,N){
    if(from[i]!=-1) continue;
    m=1000001;
    dest=i;
    while(to[dest]!=-1){ m=min(m,d[dest]); dest=to[dest]; }
    if(dest==i) continue;
    r1[t]=i;
    r2[t]=dest;
    r3[t]=m;
    t++;
  }
  printf("%d\n",t);
  FOR(i,t) printf("%d %d %d\n",r1[i]+1,r2[i]+1,r3[i]);
  return 0;
}