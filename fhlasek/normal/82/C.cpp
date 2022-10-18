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
#define MAXN 5005

using namespace std;


int N,c[MAXN],a[MAXN],p[MAXN],x[MAXN],y[MAXN],t[MAXN];
vector<int> v[MAXN],cc[MAXN];
int turn=0;

class Compare{
  public:
    bool operator()(const int A, const int B){
      return a[A]>a[B];
    }
};

priority_queue<int,vector<int>,Compare > pq[MAXN];
/*
void dfs(int start,int father,int capacity){
  p[start]=father;
  c[start]=capacity;
  int i;
  FOR(i,v[start].size()) if(v[start][i]!=father) dfs(v[start][i],start,cc[start][i]);
}*/

void dfs(int start,int father,int capacity){
  if(start!=0){
    while(capacity&&!pq[start].empty()){
//      printf("father:%d i:%d turn:%d\n",father,pq[start].top(),turn);
      if(father==0) t[pq[start].top()]=turn;
      pq[father].push(pq[start].top());
      pq[start].pop();
      capacity--;
    }
  }
  int i;
  FOR(i,v[start].size()) if(v[start][i]!=father) dfs(v[start][i],start,cc[start][i]);
}


int main(int argc, char *argv[]){
  int i,A,B,C;
  scanf("%d",&N);
  FOR(i,N){ x[i]=-1; y[i]=-1; }
  FOR(i,N) scanf("%d",a+i);
  FOR(i,N-1){
    scanf("%d%d%d",&A,&B,&C);
    A--; B--;
    v[A].push_back(B);
    v[B].push_back(A);
    cc[A].push_back(C);
    cc[B].push_back(C);
  }
  FOR(i,N) pq[i].push(i);
  turn=1;
  while(pq[0].size()!=N){
    dfs(0,-1,-1);
    turn++;
  }
  FOR(i,N){
    if(i) printf(" ");
    printf("%d",t[i]);
  }
  printf("\n");
  //FOR(i,N) printf("i:%d p[i]:%d c[i]:%d\n",i+1,p[i]+1,c[i]);
  return 0;
}