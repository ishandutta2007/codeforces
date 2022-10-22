#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
 
vector<pair<int,int>>E[N];
vector<tuple<int,int,int>>ans;
int n,deg[N],rt;
 
int dfs(int u,int fa,int fw){
int sum=0,x=0,y=0;
for(auto e:E[u])
if(e.first^fa){
sum+=e.second;int z=dfs(e.first,u,e.second);
(x?y:x)=z;
}
if(u!=rt){
if(!x)x=u,ans.push_back(make_tuple(u,rt,fw));
else{
ans.push_back(make_tuple(x,rt,(fw-sum)/2));
ans.push_back(make_tuple(y,rt,(fw-sum)/2));
ans.push_back(make_tuple(x,y,(sum-fw)/2));
}
}
return x;
}
 
int main(){
cin>>n;
for(int i=1,u,v,w;i<n;i++)cin>>u>>v>>w,E[u].push_back(make_pair(v,w)),E[v].push_back(make_pair(u,w)),++deg[u],++deg[v];
for(int i=1;i<=n;i++){
if(deg[i]==2)return puts("NO"),0;
if(deg[i]==1)rt=i;
}
dfs(rt,0,0);
puts("YES");cout<<ans.size()<<'\n';
for(auto x:ans)cout<<get<0>(x)<<' '<<get<1>(x)<<' '<<get<2>(x)<<'\n';
return 0;
}