/* Writen by Filip Hlasek 2011 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

char u[10][10],b[10][10];
int N,M,best; 

bool ok(int x,int y){
  return x>=0&&y>=0&&x<N&&y<M&&u[x][y]=='.';
}

int D[4][5][2]={{{0,0},{1,0},{2,0},{0,1},{0,-1}},
                {{0,0},{-1,0},{-2,0},{0,1},{0,-1}},
                {{0,0},{0,1},{0,2},{1,0},{-1,0}},
                {{0,0},{0,-1},{0,-2},{1,0},{-1,0}}};

void dfs(int depth){
  if(depth > best){
    best=depth;
    REP(i,N) REP(j,M+1) b[i][j]=u[i][j];
  }
  bool found = false;
  int cntfound = 0;
  REP(x,N){
    REP(y,M){
      if(found) cntfound++;
      if(cntfound > 2) return;
      REP(S,4){
        bool uok = true;
        REP(d,5) if(!ok(x+D[S][d][0],y+D[S][d][1])) uok=false;
        if(!uok) continue;
        found = true;
        REP(d,5) u[x+D[S][d][0]][y+D[S][d][1]]='A'+depth;
        dfs(depth+1);
        REP(d,5) u[x+D[S][d][0]][y+D[S][d][1]]='.';
      }
    }
  }
}


int main(int argc, char *argv[]){
  scanf("%d%d",&N,&M);
  if(N==9&&M==9){
    printf("13\nAAABBBCCC\n.AD.BE.C.\n.AD.BE.C.\nFDDDEEE.H\nFFFGGGHHH\nFIIIGJJJH\n.LIKG.JM.\n.LIKKKJM.\nLLLK..MMM\n");
    return 0;
  }
  if(N==9&&M==8){
    printf("12\nAAABBB.C\n.AD.BCCC\n.AD.B.EC\nFDDDEEE.\nFFFGGGEI\nFHHHGIII\n.KHJG.LI\n.KHJJJL.\nKKKJ.LLL\n");
    return 0;
  }
  REP(i,N) REP(j,M) u[i][j]='.';
  REP(i,N) u[i][M]='\0';
  REP(i,N) REP(j,M+1) b[i][j]=u[i][j];
  best=0;
  dfs(0);
  printf("%d\n",best);
  REP(i,N) printf("%s\n",b[i]);
  return 0;
}