#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

#define N 8
#define FOR(i,n) for(i=0;i<n;i++)

using namespace std;

int main(int argc, char *argv[]){
  char board[N+1][N+1];
  int i,j; 
  int sum=0;
  bool full;
  FOR(i,N) scanf("%s",board[i]);
  FOR(i,N){
    full=true;
    FOR(j,N) if(board[i][j]=='W') full=false;
    if(full) sum++;
  }
  FOR(i,N){
    full=true;
    FOR(j,N) if(board[j][i]=='W') full=false;
    if(full) sum++;
  }
  if(sum==16) printf("8\n");
  else printf("%d\n",sum);
  return 0;
}