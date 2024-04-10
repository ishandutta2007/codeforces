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
#define MAXN 5555

using namespace std;

char **m;
int N,M;
typedef struct chip{
  int l,r,u,d;
}C;

C **o,**p;

int run(int i,int j){
  if(p[i][j].r!=-1){
    if(p[i][j].l==-1) p[i][j+p[i][j].r].l=-1;
    else              p[i][j+p[i][j].r].l=p[i][j].l+p[i][j].r;
  }
  if(p[i][j].l!=-1){
    if(p[i][j].r==-1) p[i][j-p[i][j].l].r=-1;
    else              p[i][j-p[i][j].l].r=p[i][j].l+p[i][j].r;
  }
  if(p[i][j].d!=-1){
    if(p[i][j].u==-1) p[i+p[i][j].d][j].u=-1;
    else              p[i+p[i][j].d][j].u=p[i][j].u+p[i][j].d;
  }
  if(p[i][j].u!=-1){
    if(p[i][j].d==-1) p[i-p[i][j].u][j].d=-1;
    else              p[i-p[i][j].u][j].d=p[i][j].u+p[i][j].d;
  }
  if(m[i][j]=='U') if(p[i][j].u!=-1) return 1+run(i-p[i][j].u,j);
  if(m[i][j]=='D') if(p[i][j].d!=-1) return 1+run(i+p[i][j].d,j);
  if(m[i][j]=='L') if(p[i][j].l!=-1) return 1+run(i,j-p[i][j].l);
  if(m[i][j]=='R') if(p[i][j].r!=-1) return 1+run(i,j+p[i][j].r);
  return 1;
}

int main(int argc, char *argv[]){
  scanf("%d%d",&N,&M); 
  int i,j,k,l;
  m=(char**)malloc(sizeof(char*)*N);
  FOR(i,N) m[i]=(char*)malloc(sizeof(char)*(M+1));
  o=(C**)malloc(sizeof(C*)*N);
  FOR(i,N) o[i]=(C*)malloc(sizeof(C)*(M+1));
  p=(C**)malloc(sizeof(C*)*N);
  FOR(i,N) p[i]=(C*)malloc(sizeof(C)*(M+1));

  int best=0,num=0;
  FOR(i,N) scanf("%s",m[i]);
  FOR(i,N) FOR(j,M){ o[i][j].l=-1; o[i][j].r=-1; o[i][j].u=-1; o[i][j].d=-1; }
  FOR(i,N) FOR(j,M) if(m[i][j]!='.'){
    for(k=1;j-k>=0;k++) if(m[i][j-k]!='.'){ o[i][j].l=k; o[i][j-k].r=k; break; }
    for(k=1;i-k>=0;k++) if(m[i-k][j]!='.'){ o[i][j].u=k; o[i-k][j].d=k; break; }
  }
  FOR(i,N) FOR(j,M){
    if(m[i][j]=='.') continue;
    FOR(k,N) FOR(l,M){ p[k][l].l=o[k][l].l; p[k][l].r=o[k][l].r; p[k][l].u=o[k][l].u; p[k][l].d=o[k][l].d; }
    k=run(i,j);
    if(k>best){ best=k; num=0; }
    if(k==best) num++;
  }
  printf("%d %d\n",best,num);
  return 0;
}