#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> p2;
#define MAX 5010
p2 s[MAX];
vector<p2> nbr[MAX];
int n,start[MAX],when[MAX];
bool cmp(int a,int b){
  if(when[a]!=when[b])return when[a]<when[b];
  return a<b; 
}
void add(vector<int> &t,int c){  
  sort(t.begin(),t.end(),cmp);
  int i=0,time=0;
  priority_queue<int> q;
  while(i<t.size()||!q.empty()){
    if(i<t.size()){
      time=max(time,when[t[i]]);
      while(i<t.size()&&when[t[i]]<=time)q.push(-t[i++]);
    }
    int left=c; 
    while(!q.empty()&&left--){
//      printf("%d\n",-q.top());
      when[-q.top()]=time+1; 
      q.pop();
    }    
    ++time; 
  }
}
vector<int> dfs(int x,int y=0){
  vector<int> all(1,start[x]);
  when[start[x]]=0;
  for(int i=0;i<nbr[x].size();i++)if(nbr[x][i].first!=y){
    vector<int> t=dfs(nbr[x][i].first,x);
    add(t,nbr[x][i].second);
    for(int j=0;j<t.size();j++)all.push_back(t[j]);
  }
//  printf("%d : %d\n",x,start[x]);
//  for(int i=0;i<all.size();i++)printf("%d, %d\n",all[i],when[all[i]]);
  return all;
}
main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&s[i].first),s[i].second=i;
  sort(s+1,s+n+1);
  for(int i=1;i<=n;i++)start[s[i].second]=i;
  for(int i=1;i<n;i++){
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    nbr[x].push_back(p2(y,z)); 
    nbr[y].push_back(p2(x,z)); 
  }
  memset(when,-1,sizeof(when));
  dfs(1,0);
  for(int i=1;i<=n;i++)printf("%d%c",when[start[i]],i<n?' ':'\n');
}