#include<cstdio>
#include<vector>
using namespace std;
int n,m,a[5010],b[5010],d[5010];
bool seen[5010],seen2[5010];
vector<int> s[5010],s2[5010];
void dfs(int x){
  if(seen[x])return;
  seen[x]=true;
  for(int i=0;i<s[x].size();i++)dfs(s[x][i]);
}
void dfs2(int x){
  if(seen2[x])return;
  seen2[x]=true;
  for(int i=0;i<s2[x].size();i++)dfs2(s2[x][i]);
}
main(){
  scanf("%d %d",&n,&m);
  for(int i=1;i<=m;i++){
    scanf("%d %d",&a[i],&b[i]);
    s[a[i]].push_back(b[i]);
    s2[b[i]].push_back(a[i]);
  }
  dfs(1);
  dfs2(n);
  d[1]=0;
  for(int i=2;i<=n;i++)d[i]=1000000000;
  bool change=true;
  int iter=0;
  while(change){
    ++iter;
    if(iter>n){
      puts("No");
      return 0;
    }
    change=false;
    for(int i=1;i<=m;i++)if(seen[a[i]]&&seen2[b[i]]){
      if(d[a[i]]+2<d[b[i]])change=true,d[b[i]]=d[a[i]]+2;
      if(d[b[i]]-1<d[a[i]])change=true,d[a[i]]=d[b[i]]-1;
    }
  }
  puts("Yes");
  for(int i=1;i<=m;i++)printf("%d\n",seen[a[i]]&&seen2[b[i]]?d[b[i]]-d[a[i]]:1);
}