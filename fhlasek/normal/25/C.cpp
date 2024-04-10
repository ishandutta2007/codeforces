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
#define MAXN 301

using namespace std;

int a[MAXN][MAXN];

int main(int argc, char *argv[]){
  int N,i,j,k,K,tmp,ii,jj;
  long long sum;
  scanf("%d",&N);
  FOR(i,N) FOR(j,N) scanf("%d",&(a[i][j]));
  scanf("%d",&K);
  FOR(k,K){
    scanf("%d%d%d",&i,&j,&tmp);
    i--; j--;
    if(tmp<a[i][j]){ a[i][j]=tmp; a[j][i]=tmp; }
    FOR(ii,N) FOR(jj,N){
      a[ii][jj]=min(a[ii][i]+a[i][j]+a[j][jj],a[ii][jj]);
      a[ii][jj]=min(a[ii][j]+a[j][i]+a[i][jj],a[ii][jj]);
      a[jj][ii]=a[ii][jj];
    }
    if(k) printf(" ");
    sum=0;
    FOR(i,N) FOR(j,N) sum+=a[i][j];
    printf("%lld",sum/2);
  }
  printf("\n");
  return 0;
}