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
#define MAXN 101
#define INF 100001

using namespace std;

int matrix[MAXN][MAXN];
int N,minimum;

int get(int here,int from){
  if(here==0) return 0;
  int i;
  FOR(i,N){
    if(i==from) continue;
    if(matrix[here][i]) return get(i,here);
    if(matrix[i][here]) return matrix[i][here]+get(i,here);
  }
}

int main(int argc, char *argv[]){
  int a,b,i;
  scanf("%d",&N);
  FOR(i,N){
    scanf("%d%d",&a,&b);
    scanf("%d",&(matrix[a-1][b-1]));
  }
  int tmp;
  minimum=INF;
  FOR(i,N){
    if(matrix[0][i]){ tmp=get(i,0); minimum=min(tmp,minimum);}
    if(matrix[i][0]){ tmp=matrix[i][0]+get(i,0); minimum=min(tmp,minimum);}
  }
  printf("%d\n",minimum);
  return 0;
}