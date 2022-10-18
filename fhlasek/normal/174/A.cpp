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

int N,a[111],sum = 0,b;

int main(int argc, char *argv[]){
  scanf("%d%d",&N,&b);
  REP(i,N) scanf("%d",a+i);
  sum = b;
  REP(i,N) sum += a[i];
  bool ok = true;
  REP(i,N) if(sum/N < a[i]) ok = false;
  if(ok) REP(i,N) printf("%.9lf\n",(double)sum/N - a[i]);
  else printf("-1\n");
   
  return 0;
}