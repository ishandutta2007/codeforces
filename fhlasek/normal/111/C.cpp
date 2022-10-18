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
#include <map>

#define FOR(i,n) for(i=0;i<n;i++)

using namespace std;

int N,M;
map<long long,int> m;

long long add(long long mask,int x,int y){
  if(x<0||y<0||x==M||y==N) return mask;
  int n=N*x+y;
  if((mask&((long long)1<<n))==0) return mask+((long long)1<<n);
  else return mask;
}

long long t(long long mask,int x,int y){
  mask=add(mask,x-1,y);
  mask=add(mask,x+1,y);
  mask=add(mask,x,y-1);
  mask=add(mask,x,y+1);
  mask=add(mask,x,y);
  return mask;
}

int dfs(long long mask){
  int i,x,y,best=0;
  if(m.count(mask)) return m[mask];
  FOR(i,N*M){
    if((mask&((long long)1<<i))==0){
      best=40;
      x=i/N;
      y=i%N;
      if(x) best=min(best,1+dfs(t(mask,x-1,y)));
      if(y) best=min(best,1+dfs(t(mask,x,y-1)));
      if(x<M-1) best=min(best,1+dfs(t(mask,x+1,y)));
      if(y<N-1) best=min(best,1+dfs(t(mask,x,y+1)));
      best=min(best,1+dfs(t(mask,x,y)));
      return m[mask]=best;
    }
  }
  return m[mask]=best;
}

int main(int argc, char *argv[]){
  scanf("%d%d",&N,&M);   
  printf("%d\n",N*M-dfs(0));
  return 0;
}