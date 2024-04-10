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

int conv(int x){
  int res=0,m=1;
  while(x){
    if(x%10){
      res+=m*(x%10);
      m*=10;
    }
    x/=10;
  }
  return res;
}

int main(int argc, char *argv[]){
  int a,b;
  scanf("%d%d",&a,&b);
  if(conv(a)+conv(b)==conv(a+b)) printf("YES\n");
  else printf("NO\n");
  return 0;
}