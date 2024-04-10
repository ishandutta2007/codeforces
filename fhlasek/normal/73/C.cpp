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
#define INF 1000000000

using namespace std;

int c[255][255];
char name[111],N;
int dp[111][255][111];

int solve(int start,int ch,int K){
  if(dp[start][ch][K]!=-1) return dp[start][ch][K];
  if(start==N) return 0;
  char i;
  int best=-INF;
  for(i='a';i<='z';i++){
    if(i==name[start]) best=max(best,c[ch][i]+solve(start+1,i,K));
    else if(K) best=max(best,c[ch][i]+solve(start+1,i,K-1));
  }
  dp[start][ch][K]=best;
//  printf("%d %c %d, %d\n",start,ch,K,best);
  return best;
}

int main(int argc, char *argv[]){
  int K,n,i,j,k,C;
  FOR(i,111) FOR(j,255) FOR(k,111) dp[i][j][k]=-1;
  char a[3],b[3];
  scanf("%s",name);
  for(N=0;name[N]!='\0';N++);
  scanf("%d",&K);
  scanf("%d",&n);
  FOR(i,n){
    scanf("%s",a);
    scanf("%s",b);
    scanf("%d",&C);
    c[a[0]][b[0]]=C;
  }
  printf("%d\n",solve(0,'0',K));
  return 0;
}