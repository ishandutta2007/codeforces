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

int main(int argc, char *argv[]){
  int A,B,n,X,Xn,i;
  scanf("%d%d%d",&A,&B,&n);
  for(X=-1001;X<1001;X++){
    Xn=1;
    FOR(i,n){
      Xn*=X;
      if(Xn>10000||Xn<-10000) break;
    }
    if(A*Xn==B){
      printf("%d\n",X);
      return 0;
    }
  }
  printf("No solution\n");
  return 0;
}