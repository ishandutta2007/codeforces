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
#define MAXN 555555

using namespace std;

int N;
int pos[MAXN];

bool possible(int d){
  int i=0,j,c=1;
  for(j=0;j<N;j++){
    if(pos[j]-pos[i]>2*d){
      c++;
      i=j;
    }
  }
  return c<=3;
}

void print(int d){
  int i=0,j,c=1;
  for(j=0;j<N;j++){
    if(pos[j]-pos[i]>2*d){
      if(c>1) printf(" ");
      printf("%.6lf",(double)(pos[i]+d)/2);
      c++;
      i=j;
    }
  }
  while(c<=3){
    c++;
    if(c>1) printf(" ");
    printf("%.6lf",(double)(pos[i]+d)/2);
  }
  printf("\n");
}

int main(int argc, char *argv[]){
  int i;
  scanf("%d",&N);
  FOR(i,N){
    scanf("%d",pos+i);
    pos[i]*=2;
  }
  sort(pos,pos+N);
  int left=0,right=2000000000,middle;
  while(left<right){
    middle=(left+right)/2;
    if(possible(middle)) right=middle;
    else left=middle+1;
  }
  printf("%lf\n",(double)left/2);
  print(left);
  return 0;
}