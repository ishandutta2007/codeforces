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
  int a1,a2,a3,a4,d,res = 0;
  scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&d); 
  REP(i,d) if((i+1)%a1==0 || (i+1)%a2==0 || (i+1)%a3==0 || (i+1)%a4==0) res++;
  printf("%d\n",res);
  return 0;
}