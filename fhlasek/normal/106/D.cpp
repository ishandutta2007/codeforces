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
#define X 1111

using namespace std;

int N,M,x[30],y[30],K;
char m[X][X];
int n[X][X],e[X][X],s[X][X],w[X][X];
char dir[111111][3];
int len[111111];

int main(int argc, char *argv[]){
  scanf("%d%d",&N,&M); 
  int i,j;
  FOR(i,N) scanf("%s",m[i]);
  FOR(i,30) x[i]=-1;
  FOR(i,N) FOR(j,M) if(m[i][j]>='A'&&m[i][j]<='Z'){ x[m[i][j]-'A']=i; y[m[i][j]-'A']=j; m[i][j]='.'; }
  FOR(j,M) FOR(i,N) if(m[i][j]=='.') n[i+1][j]=n[i][j]+1;
  FOR(i,N) FOR(j,M) if(m[i][j]=='.') w[i][j+1]=w[i][j]+1;
  FOR(j,M) for(i=N-1;i>0;i--) if(m[i][j]=='.') s[i-1][j]=s[i][j]+1;
  FOR(i,N) for(j=M-1;j>0;j--) if(m[i][j]=='.') e[i][j-1]=e[i][j]+1;
  scanf("%d",&K);
  FOR(i,K) scanf("%s %d",dir[i],len+i);
  bool solution=false,ok;
  int posx,posy;
  FOR(i,30){
    if(x[i]==-1) continue;
    posx=x[i];
    posy=y[i];
    ok=true;
    FOR(j,K){
      if(dir[j][0]=='N'){
        if(n[posx][posy]<len[j]){ ok=false; break; }
        posx-=len[j];
      }
      if(dir[j][0]=='E'){
        if(e[posx][posy]<len[j]){ ok=false; break; }
        posy+=len[j];
      }
      if(dir[j][0]=='S'){
        if(s[posx][posy]<len[j]){ ok=false; break; }
        posx+=len[j];
      }
      if(dir[j][0]=='W'){
        if(w[posx][posy]<len[j]){ ok=false; break; }
        posy-=len[j];
      }
    }
    if(ok){ solution=true; printf("%c",i+'A'); }
  }
  if(!solution) printf("no solution");
  printf("\n");
  return 0;
}