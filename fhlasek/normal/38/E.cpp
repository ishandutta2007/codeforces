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
#define MAXN 3333

using namespace std;

typedef struct marble{
  int x,c;
}Marble;

typedef long long int int64;

Marble M[MAXN];
int N;
bool mycompare(Marble a,Marble b){ return a.x<b.x; }

long long dp[MAXN][MAXN];
bool used[MAXN][MAXN];

long long solve(int last,int pos){
  if(pos==N) return 0;
  if(used[last][pos]) return dp[last][pos];
  used[last][pos]=true;
  dp[last][pos]=min((long long)M[pos].c+solve(pos,pos+1),(long long)M[pos].x-M[last].x+solve(last,pos+1));
  return dp[last][pos];
}

int main(int argc, char *argv[]){
  int i,j;
  scanf("%d",&N);
  FOR(i,N) FOR(j,N) used[i][j]=false;
  FOR(i,N) scanf("%d%d",&(M[i].x),&(M[i].c));
  sort(M,M+N,mycompare);
  printf("%lld\n",M[0].c+solve(0,1));
  return 0;
}