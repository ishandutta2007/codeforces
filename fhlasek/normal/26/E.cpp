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

int n[222];

int main(int argc, char *argv[]){
  int N,i,j,W,sum=0,M=0,printed=0,used=0;
  scanf("%d%d",&N,&W);
  FOR(i,N){
    scanf("%d",n+i);
    sum+=n[i];
    if(n[i]<n[M]) M=i;
  }
  if(W>sum||(W<2&&W<n[M])||(N==1&&W!=n[0])){
    printf("No\n");
    return 0;
  }
  if(W<n[M]){
    printf("Yes\n");
    printf("1");
    FOR(i,n[1]-W+1) printf(" 2 2");
    for(i=2;i<N;i++){
      FOR(j,n[i]) printf(" %d %d",i+1,i+1);
    }
    printf(" 1");
    printf(" 2");
    FOR(i,n[0]-1) printf(" 1 1");
    FOR(i,2*W-3) printf(" 2");
    printf("\n");
    return 0;
  }
  printf("Yes\n");
  sum=0;
  FOR(i,N){
    if(i!=M){
      FOR(j,n[i]){
        if(sum+n[M]==W){
          if(printed) printf(" ");
          printed=1;
          used=1;
          printf("%d",M+1);
        }
        if(printed) printf(" ");
        printed=1;
        printf("%d %d",i+1,i+1);
        sum++;
      }
    }
  }
  FOR(i,2*(n[M])-used){
    if(printed) printf(" ");
    printed=1;
    printf("%d",M+1);
  }
  printf("\n");
  return 0;
}