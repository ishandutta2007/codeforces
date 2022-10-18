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
#define MAXN 111111

using namespace std;

typedef struct tree{
  int left,right,v,rm,lm,num,p,tmp;
  long long sum;
  double res;
  bool leaf;
}Tree;

bool mycompare(Tree a,Tree b){ return a.v<b.v; }

int N,root,K;

Tree T[MAXN];
queue<int> q;

void bfs(){
  int i;
  FOR(i,N) if(T[i].tmp==0){ q.push(i); T[i].leaf=true; }
  while(!q.empty()){
    i=q.front(); q.pop();
    if(T[i].left!=-1) T[i].lm=T[T[i].left].lm;
    else T[i].lm=T[i].v;
    if(T[i].right!=-1) T[i].rm=T[T[i].right].rm;
    else T[i].rm=T[i].v;
    if(T[i].p!=-1&&(--T[T[i].p].tmp)==0) q.push(T[i].p);
  }
}

void dfs(){
  int i;
  q.push(root);
  T[root].num=0;
  T[root].sum=0;
  while(!q.empty()){
    i=q.front(); q.pop();
    if(T[i].right==-1) continue;
    T[T[i].right].num=T[i].num+1;
    T[T[i].right].sum=T[i].sum+T[T[i].left].rm;
    T[T[i].left].num=T[i].num+1;
    T[T[i].left].sum=T[i].sum+T[T[i].right].lm;
    q.push(T[i].right);
    q.push(T[i].left);
  }
}


double solve(int k){
  int l=0,r=N-1,middle;
  while(r>l+1){
    middle=(l+r)/2;
    if(middle<0||middle>=N) break;
    if(T[middle].v<k) l=middle;
    else r=middle;
  }
  if(r>=N||r<0) return T[l].res;
  if(l>=N||l<0) return T[r].res;
  if(T[r].leaf) return T[r].res;
  else return T[l].res;
}

int main(int argc, char *argv[]){
  int i,p,v,k;
  scanf("%d",&N);
  FOR(i,N){ T[i].left=-1; T[i].right=-1; T[i].num=0; T[i].sum=0; T[i].tmp=0; T[i].leaf=false; }
  FOR(i,N){
    scanf("%d%d",&p,&v);
    if(p!=-1) p--;
    T[i].v=v;
    T[i].p=p;
  }
  FOR(i,N){
    p=T[i].p;
    v=T[i].v;
    if(p==-1) root=i;
    else{
      if(v<T[p].v) T[p].left=i;
      else T[p].right=i;
      T[p].tmp++;
    }
  }
  bfs();
  dfs();
  FOR(i,N){
    if(T[i].num) T[i].res=(double)((long double)T[i].sum/T[i].num);
    else T[i].res=0;
  }
  sort(T,T+N,mycompare);
  scanf("%d",&K);
  FOR(i,K){
    scanf("%d",&k);
    printf("%.9lf\n",solve(k));
  }
  //FOR(i,N) printf("i:%d res:%lf\n",i,T[i].res);
  //FOR(i,N) printf("i:%d v:%d left:%d right:%d lm:%d rm:%d\n",i,T[i].v,T[i].left,T[i].right,T[i].lm,T[i].rm);
  return 0;
}