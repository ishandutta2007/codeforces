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
#define MAXN 111111
#define INF 1000000111

using namespace std;

int N,a[MAXN],b[MAXN];
bool start[MAXN];

int main(int argc, char *argv[]){
  scanf("%d",&N);
  int i;
  FOR(i,N) scanf("%d",a+i);
  FOR(i,N) scanf("%d",b+i);
  FOR(i,N) start[i]=false;
  int gas=0,m=INF;
  FOR(i,N){
    gas+=a[i]-b[i];
    m=min(m,gas);
  }
  FOR(i,N){
    if(m>=0) start[i]=true;
    m=m-a[i]+b[i];
  }

  gas=0,m=INF;
  FOR(i,N){
    gas+=a[(N-i)%N]-b[(N-i+N-1)%N];
    m=min(m,gas);
  }
 
  FOR(i,N){
    if(m>=0) start[(N-i)%N]=true;
    m=m-a[(N-i)%N]+b[(N-i+N-1)%N];
  }

  int sum=0;
  FOR(i,N) if(start[i]) sum++;
  printf("%d\n",sum);
  FOR(i,N) if(start[i]) printf("%d ",i+1);
  printf("\n");
  return 0;
}