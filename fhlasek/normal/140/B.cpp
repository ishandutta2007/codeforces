/* Writen by Filip Hlasek 2011 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

#define MAXN 333

int N,a[MAXN],b[MAXN][MAXN];
set<int> s;

int main(int argc, char *argv[]){
  scanf("%d",&N);
  int x;
  REP(i,N) REP(j,N){
    scanf("%d",&x);
    b[i][j]=x;
  }
  REP(i,N) scanf("%d",a+i);
  REP(i,N){
    if(i) printf(" ");
    s.clear();
    int best=N+1;
    REP(j,N){
      if(a[j]==i+1) continue;
      best=min(best,a[j]);
      s.insert(best);
    }
    REP(j,N){
      if(b[i][j]==i+1) continue;
      if(s.count(b[i][j])){
        printf("%d",b[i][j]);
        break;
      }
    }
  }
  printf("\n");
  return 0;
}