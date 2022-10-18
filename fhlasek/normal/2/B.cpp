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
#define MAXN 1000
#define INF 1000000

using namespace std;

int matrix2[MAXN][MAXN],matrix5[MAXN][MAXN];
int best2[MAXN][MAXN],best5[MAXN][MAXN];
char dir2[MAXN][MAXN],dir5[MAXN][MAXN];
int N;

int find2(int x, int y){
  if(best2[x][y]!=-1) return best2[x][y];
  int d=INF,r=INF;
  if(x<N-1) d=find2(x+1,y);
  if(y<N-1) r=find2(x,y+1);
  if(d<=r){
    best2[x][y]=d+matrix2[x][y];
    dir2[x][y]='D';
  }
  else{
    best2[x][y]=r+matrix2[x][y];
    dir2[x][y]='R';
  }
  return best2[x][y];
}

int find5(int x, int y){
  if(best5[x][y]!=-1) return best5[x][y];
  int d=INF,r=INF;
  if(x<N-1) d=find5(x+1,y);
  if(y<N-1) r=find5(x,y+1);
  if(d<=r){
    best5[x][y]=d+matrix5[x][y];
    dir5[x][y]='D';
  }
  else{
    best5[x][y]=r+matrix5[x][y];
    dir5[x][y]='R';
  }
  return best5[x][y];
}
int main(int argc, char *argv[]){
  scanf("%d",&N);
  int i,j,num;
  bool zero=false;
  int zerox,zeroy;
  FOR(i,N) FOR(j,N){
    best2[i][j]=-1;best5[i][j]=-1;
    scanf("%d",&num);
    if(num==0){
      matrix2[i][j]=INF;
      matrix5[i][j]=INF;
      zero=true;
      zerox=i;
      zeroy=j;
    }
    else{
      matrix2[i][j]=0;
      while(num%2==0){ matrix2[i][j]++; num/=2;}
      matrix5[i][j]=0;
      while(num%5==0){ matrix5[i][j]++; num/=5;}
    }
  }
  best2[N-1][N-1]=matrix2[N-1][N-1];
  find2(0,0);
  best5[N-1][N-1]=matrix5[N-1][N-1];
  find5(0,0);
  if(zero&&best2[0][0]>1&&best5[0][0]>1){
    printf("1\n");
    FOR(i,zerox) printf("D");
    FOR(i,zeroy) printf("R");
    FOR(i,N-1-zerox) printf("D");
    FOR(i,N-1-zeroy) printf("R");
    printf("\n");
    return 0;
  }
  if(best2[0][0]<best5[0][0]){
    printf("%d\n",best2[0][0]);
    i=0;j=0;
    while(!(i==N-1&&j==N-1)){
      printf("%c",dir2[i][j]);
      if(dir2[i][j]=='D') i++;
      else j++;
    }
  }
  else{
    printf("%d\n",best5[0][0]);
    i=0;j=0;
    while(!(i==N-1&&j==N-1)){
      printf("%c",dir5[i][j]);
      if(dir5[i][j]=='D') i++;
      else j++;
    }
  }
  printf("\n");
  return 0;
}