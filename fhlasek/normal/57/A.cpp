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

int abs(int x){ if(x>0) return x; return -x; }

int main(int argc, char *argv[]){
  int n,x1,y1,x2,y2;
  scanf("%d%d%d%d%d",&n,&x1,&y1,&x2,&y2);
  if((abs(x2-x1)==n)){
    printf("%d\n",n+min(y1+y2,n-y1+n-y2));
    return 0;
  }
  if((abs(y2-y1)==n)){
    printf("%d\n",n+min(x1+x2,n-x1+n-x2));
    return 0;
  }
  printf("%d\n",abs(x1-x2)+abs(y1-y2));
  return 0;
}