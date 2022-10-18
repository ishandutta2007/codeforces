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

int main(int argc, char *argv[]){
  int a,c,b=0,m=1; 
  scanf("%d%d",&a,&c);
  while(a||c){
    b+=m*((c%3-a%3+3)%3);
    a/=3;
    c/=3;
    m*=3;
  }
  printf("%d\n",b);
  return 0;
}