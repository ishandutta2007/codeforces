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
#define MAXN 11111

using namespace std;

int N,M,K;
int a[MAXN];

int main(int argc, char *argv[]){
  scanf("%d%d%d",&N,&M,&K); 
  int m=MAXN*111,i;
  FOR(i,N) scanf("%d",a+i);
  if(N%2==0){ printf("0\n"); return 0; }
  FOR(i,N) if(i%2==0) m=min(m,a[i]);
  N=(N+1)/2;
  M/=N;
  if((long long)K*M<m) printf("%d\n",K*M);
  else printf("%d\n",m);
  return 0;
}