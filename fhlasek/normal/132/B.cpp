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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

int N,X,Y,C=-1;

char m[111][111];
int c[111][111],rem[111*111];
int p[55*55][10];
int dp[55*55][10];

void dfs(int x,int y,int col){
  if(x<0||y<0||x==X||y==Y||c[x][y]!=col) return;
  c[x][y]=C;
  dfs(x-1,y,col);
  dfs(x+1,y,col);
  dfs(x,y-1,col);
  dfs(x,y+1,col);
}

int get(int x,int y){
  if(x<0||y<0||x==X||y==Y) return 0;
  return -c[x][y];
}

int main(int argc, char *argv[]){
  scanf("%d%d",&X,&N); 
  REP(i,X) scanf("%s",m[i]);
  for(Y=0;m[0][Y]!='\0';Y++);
  REP(i,X) REP(j,Y) c[i][j]=m[i][j]-'0';
  REP(i,X) REP(j,Y) if(c[i][j]>0){ rem[-C]=c[i][j]; dfs(i,j,c[i][j]); C--; }
  C=-C-1;
  FOR(cc,1,C){
    int minx=X,maxx=0,miny=Y,maxy=0;
    REP(i,X) REP(j,Y) if(c[i][j]==-cc){
      minx=min(minx,i);
      maxx=max(maxx,i);
      miny=min(miny,j);
      maxy=max(maxy,j);
    }
    p[cc][0]=get(minx,maxy+1);
    p[cc][1]=get(maxx,maxy+1);
    p[cc][2]=get(maxx+1,maxy);
    p[cc][3]=get(maxx+1,miny);
    p[cc][4]=get(maxx,miny-1);
    p[cc][5]=get(minx,miny-1);
    p[cc][6]=get(minx-1,miny);
    p[cc][7]=get(minx-1,maxy);
  }
  int pos=1,state=0;
  REP(i,C+1) REP(j,10) dp[i][j]=-1;
  while(N){
    if(dp[pos][state]!=-1&&2*N>=dp[pos][state]){
      N%=(dp[pos][state]-N);
      continue;
    }
    dp[pos][state]=N;
    if(p[pos][state]) pos=p[pos][state];
    else state=(state+1)%8;
    N--;
  }
  printf("%d\n",rem[pos]);
  return 0;
}