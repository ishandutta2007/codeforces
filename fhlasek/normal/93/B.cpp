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

#define FOR(i,n) for(i=0;i<n;i++)
#define MAX 55
#define EPS 0.000000001

using namespace std;

int N,M,W;
double a[MAX][MAX];
int t[MAX][MAX],k[MAX];

int main(int argc, char *argv[]){
  scanf("%d%d%d",&N,&W,&M);
  int i,pos=0;
  double fill=0,e=(double)W*N/M,rem;
  FOR(i,N){
    if(fill+EPS>e){ pos++; fill=0; }
    if(e-fill+e+EPS<W){
      printf("NO\n");
      return 0;
    }
    if(e-fill+EPS>W){
      fill+=W;
      a[pos][k[pos]]=W;
      t[pos][k[pos]]=i;
      k[pos]++;
    }
    else{
      rem=W-(e-fill);
      a[pos][k[pos]]=e-fill;
      t[pos][k[pos]]=i;
      k[pos]++;
      pos++;
      a[pos][k[pos]]=rem;
      t[pos][k[pos]]=i;
      k[pos]++; 
      fill=rem;
    }
  }
  int j;
  printf("YES\n");
  FOR(i,M){
    FOR(j,k[i]){
      if(j) printf(" ");
      printf("%d %.7lf",t[i][j]+1,a[i][j]);
    }
    printf("\n");
  }
  return 0;
}