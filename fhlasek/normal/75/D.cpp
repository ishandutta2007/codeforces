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
#define MAXN 55
#define MAXB 255000
#define MAXL 5555
#define INF (1LL<<50)

using namespace std;

int N,B,L[MAXN],b[MAXB];
long long sum[MAXN],end[MAXN],begin[MAXN];
bool used[MAXN];
int a[MAXN][MAXL];

int main(int argc, char *argv[]){
  int i,j;
  scanf("%d%d",&N,&B);
  FOR(i,N){
    scanf("%d",L+i);
    FOR(j,L[i]) scanf("%d",&(a[i][j]));
  }
  FOR(i,B){ scanf("%d",b+i); used[b[i]-1]=true; }
  long long best=-INF,t;
  FOR(i,N){
    if(!used[i]) continue;
    sum[i]=0;
    FOR(j,L[i]) sum[i]+=a[i][j];
    t=0;
    end[i]=-INF;
    FOR(j,L[i]){
      t+=a[i][j];
      end[i]=max(end[i],t);
    }
    t=0;
    begin[i]=-INF;
    for(j=L[i]-1;j>=0;j--){
      t+=a[i][j];
      begin[i]=max(begin[i],t);
    }
    t=-INF;
    for(j=0;j<L[i];j++){
      t=max(t+a[i][j],(long long)a[i][j]);
      best=max(best,t);            
    }
  }
  t=begin[b[0]-1];
  for(i=1;i<B;i++){
    j=b[i]-1;
    best=max(best,t+end[j]);
    t=max(t+sum[j],begin[j]);
    best=max(best,t);
  }
  printf("%I64d\n",best);
//  printf("%lld\n",best);
  return 0;
}