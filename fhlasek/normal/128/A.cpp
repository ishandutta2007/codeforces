/* Writen by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

char m[8][8];

void step(){
  char newm[8][8];
  REP(i,8) REP(j,8) newm[i][j]=m[i][j];
  REP(i,8) REP(j,8) if(m[i][j]=='.'){
    FOR(dx,-1,1) FOR(dy,-1,1){
      int x = i+dx, y = j+dy;
      if(x>=0&&y>=0&&x<8&&y<8&&m[x][y]=='M') newm[i][j]='M';
    }
  }
  REP(i,8) REP(j,8) m[i][j]=newm[i][j];
  FORD(i,7,0) REP(j,8) if(m[i][j]=='S'){
    m[i][j]='.';
    if(i<7) m[i+1][j] = 'S';
  }
}

int main(int argc, char *argv[]){
  REP(i,8) scanf("%s",m[i]);
  m[0][7] = '.';
  REP(i,60) step();
  if(m[0][7]=='M') printf("WIN\n");
  else printf("LOSE\n");
  return 0;
}