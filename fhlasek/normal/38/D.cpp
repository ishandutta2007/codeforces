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
#define MAXN 111
#define CU(a) ((a)*(a)*(a))

using namespace std;

int N,X1[MAXN],X2[MAXN],Y1[MAXN],Y2[MAXN],Tm[MAXN];
double Tx[MAXN],Ty[MAXN];

bool fit(double x,double y,int x1,int y1,int x2,int y2){
  if(x+1e-8<x1||y+1e-8<y1||x-1e-8>x2||y-1e-8>y2) return false;
  return true;
}

bool add(int a){
  int i;
  double ntx,nty;
  Tx[a]=((double)X2[a]+X1[a])/2;
  Ty[a]=((double)Y2[a]+Y1[a])/2;
  Tm[a]=CU(X2[a]-X1[a]);
  FOR(i,a){
    ntx=(double)(Tm[i]*Tx[i]+Tm[a]*Tx[a])/(Tm[i]+Tm[a]);
    nty=(double)(Tm[i]*Ty[i]+Tm[a]*Ty[a])/(Tm[i]+Tm[a]);
    Tx[i]=ntx;
    Ty[i]=nty;
    Tm[i]=Tm[i]+CU(X2[a]-X1[a]);
  }
  FOR(i,a){
    if(!fit(Tx[i+1],Ty[i+1],X1[i],Y1[i],X2[i],Y2[i])) return false;
  }
  return true;
}

int main(int argc, char *argv[]){
  int i,a1,a2;
  scanf("%d",&N);
  FOR(i,N){
    scanf("%d%d%d%d",X1+i,Y1+i,X2+i,Y2+i);
    a2=max(X1[i],X2[i]);
    a1=min(X1[i],X2[i]);
    X2[i]=a2;
    X1[i]=a1;
    a2=max(Y1[i],Y2[i]);
    a1=min(Y1[i],Y2[i]);
    Y2[i]=a2;
    Y1[i]=a1;
  }
  FOR(i,N){
    if(!add(i)){
      printf("%d\n",i);
      return 0;
    }
  }
  printf("%d\n",N);
  return 0;
}