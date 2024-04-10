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

bool matrix[MAXN][MAXN];
int resx[MAXN],resy[MAXN],reslen;
bool visited[MAXN];
int N;

void dfs(int x,int last){
  visited[x]=true;
  int i;
  FOR(i,N){
    if(matrix[x][i]&&i!=last){
      if(visited[i]){
        matrix[x][i]=false;
        matrix[i][x]=false;
        resx[reslen]=x;
        resy[reslen]=i;
        reslen++;
      }
      else dfs(i,x);
    }
  }
}

int main(int argc, char *argv[]){
  int i,x,y;
  scanf("%d",&N);
  FOR(x,N) FOR(y,N) matrix[x][y]=false;
  FOR(i,N-1){
    scanf("%d%d",&x,&y);
    x--;y--;
    matrix[x][y]=true;
    matrix[y][x]=true;
  }
  FOR(i,N) visited[i]=false;
  FOR(i,N) if(!visited[i]) dfs(i,-1);
  FOR(i,N) visited[i]=false;
  dfs(0,-1);
  printf("%d\n",reslen);
  x=0;
  FOR(i,reslen){
    while(visited[x]) x++;
    printf("%d %d %d %d\n",resx[i]+1,resy[i]+1,1,x+1);
    dfs(x,-1);
  }
  return 0;
}