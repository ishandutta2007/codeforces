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
#define MAXN 1001

using namespace std;

typedef struct point{
  int x,y,t;
  double p,dp;
}Point;

bool mycompare(Point a,Point b){ return a.t<b.t; }

Point P[MAXN];
int N;

int main(int argc, char *argv[]){
  scanf("%d",&N);
  int i,j;
  FOR(i,N){
    scanf("%d%d%d%lf",&(P[i].x),&(P[i].y),&(P[i].t),&(P[i].p));
    P[i].dp=0;
  }
  sort(P,P+N,mycompare);
  FOR(i,N){
    if(P[i].p>P[i].dp) P[i].dp=P[i].p;
    for(j=i+1;j<N;j++){
      if(P[j].t-P[i].t>=sqrt((P[j].x-P[i].x)*(P[j].x-P[i].x)+(P[j].y-P[i].y)*(P[j].y-P[i].y))-1e-8){
        if(P[i].dp+P[j].p>P[j].dp) P[j].dp=P[i].dp+P[j].p;
      }
    }
  }
  double m=0;
  FOR(i,N) m=max(m,P[i].dp);
  printf("%lf\n",m);
  return 0;
}