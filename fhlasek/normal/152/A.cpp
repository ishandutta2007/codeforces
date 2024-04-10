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

char a[111][111];
int best[111];

int main(int argc, char *argv[]){
  int N,M;
  scanf("%d%d",&N,&M);   
  REP(i,N) scanf("%s",a[i]);
  REP(i,N) REP(j,M) best[j] = max(best[j],(int)a[i][j]);
  bool ok;
  int res=0;
  REP(i,N){
    ok = false;
    REP(j,M) if(a[i][j] == best[j]) ok = true;
    res += ok;
  }
  printf("%d\n",res);
  return 0;
}