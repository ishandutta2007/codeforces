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

int ok[111111];

int main(int argc, char *argv[]){
  int N,i,j,x,sum,y;
  scanf("%d",&N);
  FOR(i,111111) ok[i]=-111111;
  FOR(i,N){
    scanf("%d%d",&x,&y);
    sum=0;
    for(j=1;j*j<=x;j++){
      if(x%j==0){
        if(ok[j]<i-y) sum++;
        ok[j]=i;
        if(ok[x/j]<i-y) sum++;
        ok[x/j]=i;
      }
    }
    printf("%d\n",sum);
  }
  return 0;
}