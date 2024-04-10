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

const int P[]={25,18,15,12,10,8,6,4,2,1};

int points[MAXN],positions[MAXN][51];
char names[MAXN][51];

bool compare1(int a,int b){
  if(points[a]!=points[b]) return points[a]>points[b];
  int i;
  FOR(i,50){
    if(positions[a][i]!=positions[b][i]) return positions[a][i]>positions[b][i];
  }
  return false;
}

bool compare2(int a,int b){
  if(positions[a][0]!=positions[b][0]) return positions[a][0]>positions[b][0];
  if(points[a]!=points[b]) return points[a]>points[b];
  int i;
  FOR(i,50){
    if(positions[a][i]!=positions[b][i]) return positions[a][i]>positions[b][i];
  }
  return false;
}

int main(int argc, char *argv[]){
  int T,M=0,n,i,j,N,k;
  char line[51];
  scanf("%d",&T);
  FOR(i,T){
    scanf("%d",&N);
    FOR(n,N){
      scanf("%s",line);
      FOR(j,M){
        for(k=0;line[k]!='\0'&&names[j][k]!='\0'&&line[k]==names[j][k];k++);
        if(line[k]==names[j][k]) break;
      }
      if(j==M){
        for(k=0;line[k]!='\0';k++) names[j][k]=line[k];
        names[j][k]='\0';
        M++;
      }
      if(n<10) points[j]+=P[n];
      positions[j][n]++;
    }
  }
  j=0;
  FOR(i,M) if(compare1(i,j)) j=i;
  printf("%s\n",names[j]);
  j=0;
  FOR(i,M) if(compare2(i,j)) j=i;
  printf("%s\n",names[j]);
  return 0;
}