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

int a[111],b[111],c[111],p[111];

int main(int argc, char *argv[]){
  int N,i,j,best=-1; 
  bool ok;
  scanf("%d",&N);
  FOR(i,N) scanf("%d%d%d%d",a+i,b+i,c+i,p+i);
  FOR(i,N){
    ok=true;
    FOR(j,N) if(a[i]<a[j]&&b[i]<b[j]&&c[i]<c[j]){ ok=false; break; }
    if(ok&&(best==-1||p[i]<p[best])) best=i;
  }
  printf("%d\n",best+1);
  return 0;
}