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

char m[3][4];

bool win(char c){
  int i;
  bool ok=true;
  FOR(i,3) if(m[0][i]!=c) ok=false;
  if(ok) return true;
  ok=true;
  FOR(i,3) if(m[i][0]!=c) ok=false;
  if(ok) return true;
  ok=true;
  FOR(i,3) if(m[i][2]!=c) ok=false;
  if(ok) return true;
  ok=true;
  FOR(i,3) if(m[2][i]!=c) ok=false;
  if(ok) return true;
  ok=true;
  FOR(i,3) if(m[i][1]!=c) ok=false;
  if(ok) return true;
  ok=true;
  FOR(i,3) if(m[1][i]!=c) ok=false;
  if(ok) return true;
  ok=true;
  FOR(i,3) if(m[i][i]!=c) ok=false;
  if(ok) return true;
  ok=true;
  FOR(i,3) if(m[i][2-i]!=c) ok=false;
  if(ok) return true;
  return false;
}

int main(int argc, char *argv[]){
  int i,j;
  FOR(i,3) scanf("%s",m[i]);
  int cross=0,nought=0,dot=0;
  FOR(i,3) FOR(j,3){
    if(m[i][j]=='X') cross++;
    if(m[i][j]=='0') nought++;
    if(m[i][j]=='.') dot++;
  }
  if(nought>cross||cross-nought>1){ printf("illegal\n"); return 0; }
  if(win('X')&&win('0')){ printf("illegal\n"); return 0; }
  if(win('X')){
    if(cross==nought+1){ printf("the first player won\n"); return 0; }
    else{ printf("illegal\n"); return 0;}
  }
  if(win('0')){
    if(cross==nought){ printf("the second player won\n"); return 0; }
    else{ printf("illegal\n"); return 0; }
  }
  if(dot==0){ printf("draw\n"); return 0; }
  if(cross==nought){ printf("first\n"); return 0; }
  printf("second\n");
  return 0;
}