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
const int MAX=110000;
void merge(const vector<int> &a,const vector<int> &b,vector<int> &ans){
  int i=0,j=0;
  while(i<a.size()&&j<b.size()&&ans.size()<10){
    if(a[i]<b[j]){
      ans.push_back(a[i]);
      ++i;
    }else{
      ans.push_back(b[j]);
      ++j;
    }
  }
  while(i<a.size()&&ans.size()<10){
    ans.push_back(a[i]);
    ++i;
  }
  while(j<b.size()&&ans.size()<10){
    ans.push_back(b[j]);
    ++j;
  }
}
vector<int> merge2(const vector<int> &a,const vector<int> &b){
  vector<int> tmp;
  merge(a,b,tmp);
  return tmp;
}
int n,m,q,depth[MAX],ancestor[MAX][18],pre[MAX],post[MAX],counter;
vector<int> s[MAX],people[MAX][18];
void dfs(int cur,int prev=0){
  pre[cur]=++counter;
  depth[cur]=depth[prev]+1;
  ancestor[cur][0]=prev;
  for(int i=1;i<=17;i++){
    ancestor[cur][i]=ancestor[ancestor[cur][i-1]][i-1];
    merge(people[cur][i-1],people[ancestor[cur][i-1]][i-1],people[cur][i]);
  //printf("%d %d\n",cur,i);
  //for(int j=0;j<people[cur][i].size();j++)printf(" %d",people[cur][i][j]);
  //printf("\n");
  }
  for(int i=0;i<s[cur].size();i++)if(s[cur][i]!=prev){
    dfs(s[cur][i],cur);
  }
  post[cur]=++counter;
}
bool inside(int u,int v){
  return pre[u]<=pre[v]&&pre[v]<post[u];
}
vector<int> find(int u,int cnt){
  //printf("find %d %d\n",u,cnt);
  vector<int> ans;
  for(int i=0;i<18;i++)if(cnt&1<<i){
    //printf("%d -> %d\n",u,ancestor[u][i]);
    ans=merge2(ans,people[u][i]);
    u=ancestor[u][i];
  }
  return ans;
}
int main(){
  scanf("%d %d %d",&n,&m,&q);
  for(int i=1;i<n;i++){
    int x,y;
    //x=i;y=i+1;
    scanf("%d %d",&x,&y);
    s[x].push_back(y);
    s[y].push_back(x);
  }
  for(int i=1;i<=m;i++){
    int x;
    //x=i;
    scanf("%d",&x);
    if(people[x][0].size()<10){
      people[x][0].push_back(i);
    }
  }
  dfs(1);
  while(q--){
    int u,v,a;
    scanf("%d %d %d",&u,&v,&a);
    //u=1;v=n;a=10;

    vector<int> ans;
    if(inside(u,v)){
      ans=find(v,depth[v]-depth[u]+1);
    }else if(inside(v,u)){
      ans=find(u,depth[u]-depth[v]+1);
    }else {
      int lca=u;
      for(int i=17;i>=0;i--)if(ancestor[lca][i]&&!inside(ancestor[lca][i],v)){
        //printf("%d -> %d\n",lca,ancestor[lca][i]);
        lca=ancestor[lca][i];
      }
      //printf("u=%d v=%d lca=%d\n",u,v,lca);
      ans=merge2(find(u,depth[u]-depth[lca]+1),find(v,depth[v]-depth[lca]+2));
    }
    while(ans.size()>a){
      ans.pop_back();
    }
    printf("%d",(int)ans.size());
    for(int i=0;i<ans.size();i++){
      printf(" %d",ans[i]);
    }
    printf("\n");
  }
  return 0;
}