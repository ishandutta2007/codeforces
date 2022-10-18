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
#define MAXN 100001
#define INF 1000000000

using namespace std;

int N;
int seq[MAXN];
double q[MAXN];

int main(int argc, char *argv[]){
  int i;
  scanf("%d",&N);
  FOR(i,N) scanf("%d",seq+i);
  FOR(i,N-1){
    if(seq[i]) q[i]=(double)seq[i+1]/seq[i];
    else{
      if(seq[i+1]) q[i]=INF;
      else q[i]=0;
    }
  }
  if(N==1){
    printf("0\n");
    return 0;
  }
  double Q=q[0];
  bool ok=true;;
  FOR(i,N-1){ if(Q-q[i]>1e-8||Q-q[i]<-1e-8){ ok=false; break; }}
  if(ok&&Q!=INF){
    printf("0\n");
    return 0;
  }
  if(N==2){
    printf("1\n");
    return 0;
  }
  Q=q[1];
  ok=true;
  FOR(i,N-2){ if(Q-q[i+1]>1e-8||Q-q[i+1]<-1e-8){ ok=false; break; }}
  if(ok&&Q!=INF){
    printf("1\n");
    return 0;
  }
  if(seq[0]) Q=(double)seq[2]/seq[0];
  else{
    if(seq[2]) Q=INF;
    else Q=0;
  }
  ok=true;
  FOR(i,N-3){ if(Q-q[i+2]>1e-8||Q-q[i+2]<-1e-8){ ok=false; break; }}
  if(ok&&Q!=INF){
    printf("1\n");
    return 0;
  }
  Q=q[0];
  ok=true;
  bool change=false;
  FOR(i,N-1){
    if(Q-q[i]>1e-8||Q-q[i]<-1e-8){
      if(change){ ok=false; break; }
      if(i<N-2){
        double QQ=(double)seq[i+2]/seq[i];
        if(Q-QQ>1e-8||Q-QQ<-1e-8){ ok=false; break; }
        change=true;
        q[i+1]=QQ;
      }
    }
  }
  if(ok&&Q!=INF){
    printf("1\n");
    return 0;
  }
  printf("2\n");
  return 0;
}