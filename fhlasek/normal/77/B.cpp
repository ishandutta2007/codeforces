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

void out(double x){ printf("%.9lf\n",x); }

double get(double a,double b){
  if(a>b) return (a-b)/a+b/a*0.5;
  else return a/b*0.5;
}

int main(int argc, char *argv[]){
  int T,t,A,B;
  scanf("%d",&T);
  FOR(t,T){
    scanf("%d%d",&A,&B);
    if(B==0){ out(1); continue; }
    if(A==0){ out(0.5);  continue; }
    out(0.5+0.5*get(A,4*B));
  }
  return 0;
}