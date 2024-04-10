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
  int N,i;
  char num[101];
  scanf("%d",&N);
  scanf("%s",num);
  i=0;
  if(N%2){
    printf("%c%c%c",num[0],num[1],num[2]);
    i=3;
  }
  while(i<N){
    if(i) printf("-");
    printf("%c%c",num[i],num[i+1]);
    i+=2;
  }
  printf("\n");
  return 0;
}