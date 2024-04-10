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

int N;

int main(int argc, char *argv[]){
  int i,j;
  scanf("%d",&N);
//  if(N==1){ printf("-1\n"); return 0; }
  FOR(j,2){
    FOR(i,N/2*2){
      if(i%4<2) printf("%c",'a'+j);
      else printf("%c",'c'+j);
    }
    if(N%2) printf("z");
    printf("\n");
  }
  FOR(j,2){
    printf("w");
    FOR(i,(N-1)/2*2){
      if(i%4<2) printf("%c",'e'+j);
      else printf("%c",'g'+j);
    }
    if(N%2==0) printf("z");
    printf("\n");
  }
  return 0;
}