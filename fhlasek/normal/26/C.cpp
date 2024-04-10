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

char res[102][102];

int main(int argc, char *argv[]){
  int a,b,c,n,m,i,j,N,M;
  scanf("%d%d%d%d%d",&N,&M,&a,&b,&c);
  n=N;
  m=M;
  FOR(i,n) res[i][m]='\0';
  if((n*m)%2){
    printf("IMPOSSIBLE\n");
    return 0;
  }
  if(n%2){
    if(a<m/2){
      printf("IMPOSSIBLE\n");
      return 0;
    }
    a-=m/2;
    n--;
    FOR(i,m){
      if(i%4==0||i%4==1) res[n][i]='x';
      else res[n][i]='y';
    }
  }
  if(m%2){
    if(b<n/2){
      printf("IMPOSSIBLE\n");
      return 0;
    }
    b-=n/2;
    m--;
    FOR(i,n){
      if(i%4==0||i%4==1) res[i][m]='x';
      else res[i][m]='y';
    }
  }
  if(a+b+c<n*m/4){
    printf("IMPOSSIBLE\n");
    return 0;
  }
  FOR(i,n/2){
    FOR(j,m/2){
      if(c){
        if((i+j)%2){ res[2*i][2*j]='a'; res[2*i+1][2*j]='a'; res[2*i][2*j+1]='a'; res[2*i+1][2*j+1]='a'; }
        else{ res[2*i][2*j]='c'; res[2*i+1][2*j]='c'; res[2*i][2*j+1]='c'; res[2*i+1][2*j+1]='c'; }
        c--;
        continue;
      }
      if(a>1){
        if((i+j)%2){ res[2*i][2*j]='a'; res[2*i+1][2*j]='b'; res[2*i][2*j+1]='a'; res[2*i+1][2*j+1]='b'; }
        else{ res[2*i][2*j]='c'; res[2*i+1][2*j]='d'; res[2*i][2*j+1]='c'; res[2*i+1][2*j+1]='d'; }
        a-=2;
        continue;
      }
      if(b>1){
        if((i+j)%2){ res[2*i][2*j]='a'; res[2*i+1][2*j]='a'; res[2*i][2*j+1]='b'; res[2*i+1][2*j+1]='b'; }
        else{ res[2*i][2*j]='c'; res[2*i+1][2*j]='c'; res[2*i][2*j+1]='d'; res[2*i+1][2*j+1]='d'; }
        b-=2;
        continue;
      }
      printf("IMPOSSIBLE\n");
      return 0;
    }
  }
  FOR(i,N) printf("%s\n",res[i]);
  return 0;
}