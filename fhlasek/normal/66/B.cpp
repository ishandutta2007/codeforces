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
#define MAXN 1111

using namespace std;

int N,seq[MAXN];

int main(int argc, char *argv[]){
  scanf("%d",&N);
  int i,result=0,sum,j;
  FOR(i,N) scanf("%d",seq+i);
  FOR(i,N){
    sum=1;
    for(j=i-1;j>=0&&seq[j]<=seq[j+1];j--) sum++;
    for(j=i+1;j<N&&seq[j]<=seq[j-1];j++) sum++;
    result=max(result,sum);
  }
  printf("%d\n",result);
  return 0;
}