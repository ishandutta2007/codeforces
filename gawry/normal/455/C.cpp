#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
const int MAX=1000000;
int n,m,q,parent[MAX],diam[MAX];
int find(int x){return x==parent[x]?x:parent[x]=find(parent[x]);}
int seen[MAX];
int largest_dist,largest_where;
vector<int> s[MAX];
void dfs(int x,int dist=0,int phase=1){
  if(seen[x]==phase)return;
  seen[x]=phase;
  FOR(i,s[x].size()){
    dfs(s[x][i],dist+1,phase);
  }
  if(dist>largest_dist){
    largest_dist=dist;
    largest_where=x;
  }
}
int main(){
  scanf("%d %d %d",&n,&m,&q);
  for(int i=1;i<=n;i++)parent[i]=i;
  while(m--){
    int x,y;
    scanf("%d %d",&x,&y);
    s[x].push_back(y);
    s[y].push_back(x);
    x=find(x);
    y=find(y);
    parent[x]=y;
  }
  for(int i=1;i<=n;i++)if(!seen[i]){
    largest_dist=-1;
    dfs(i,0,1);
    //printf("where=%d\n",largest_where);
    dfs(largest_where,0,2);
    diam[find(i)]=largest_dist;
  //printf("%d -> %d\n",find(i),largest_dist);
  }
  while(q--){
    int x,y,z;
    scanf("%d %d",&x,&y);
    if(x==1){
      y=find(y);
      printf("%d\n",diam[y]);
    }else{
      scanf("%d",&z);
      y=find(y);
      z=find(z);
      if(y==z)continue;
      diam[z]=max((diam[y]+1)/2+(diam[z]+1)/2+1,max(diam[y],diam[z]));
      parent[y]=z;
//    printf("%d ---> %d\n",z,diam[z]);
    }
  }
  return 0;
}