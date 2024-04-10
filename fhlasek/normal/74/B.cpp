#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

#define FOR(i,n) for(i=1;i<=n;i++)
#define MAXN 555

using namespace std;

int N,M,K,d;
bool p[MAXN],pn[MAXN];
char l[MAXN];

bool check(){
  int i;
  FOR(i,N) if(p[i]) return true;
  return false;
}

int main(int argc, char *argv[]){
  scanf("%d%d%d",&N,&M,&K); 
  scanf("%s",l);
  scanf("%s",l);
  if(l[0]=='h') d=-1; else d=1;
  int i,j;
  FOR(i,N) p[i]=false;
  p[M]=true;
  scanf("%s",l);
  for(i=0;l[i]!='\0';i++){
    if(!check()){
      printf("Controller %d\n",i);
      return 0;
    }
    if(l[i]=='0'){
      FOR(j,N) pn[j]=false;
      FOR(j,N) if(j!=K&&((j<N&&p[j+1])||(j>1&&p[j-1]))) pn[j]=true;
      FOR(j,N) p[j]=p[j]||pn[j];
    }
    else FOR(j,N) p[j]=true;
    if(K+d==N+1||K+d==0) d=-d;
    K+=d;
    p[K]=false;
  }
  printf("Stowaway\n");
  return 0;
}