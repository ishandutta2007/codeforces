/* Writen by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

int mask(int x){
  int res=0,m=1;
  while(x){
    if(x%10 == 4 || x%10 == 7){
      res += m*(x%10);
      m*=10;
    }
    x/=10;
  }
  return res;
}

int main(int argc, char *argv[]){
  int a,b; 
  scanf("%d%d",&a,&b);
  int i=a+1;
  while(true){
    if(mask(i) == b){
      printf("%d\n",i);
      break;
    }
    i++;
  }
  return 0;
}