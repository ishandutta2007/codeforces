#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define ff fflush(stdout)
int n,f[N],dp[N],g[N],rt;
vector<int> G[N];
void dfs1(int u){
	dp[u]=1;
	vector<int> vec;
	for(auto v:G[u]){if(v==f[u])continue;f[v]=u;dfs1(v);vec.push_back(dp[v]);}	
	sort(vec.begin(),vec.end(),greater<int>());
	for(int i=0;i<vec.size();++i)dp[u]=max(dp[u],vec[i]+i);
}
void dfs2(int u,int fw){
	vector<pair<int,int> > vec;
	for(auto v:G[u]){if(v==f[u])continue;vec.emplace_back(dp[v],v);}
	if(u^1)vec.emplace_back(fw,-1);
	sort(vec.begin(),vec.end(),greater<pair<int,int> >());
	for(int i=1;i<vec.size();++i)g[u]=max(g[u],vec[i].first+i-1);
	g[u]+=vec[0].first;
	vector<int> pre(vec.size()),suf(vec.size());
	pre[0]=vec[0].first,suf[(int)vec.size()-1]=vec.back().first+(int)vec.size()-2;
	for(int i=1;i<(int)vec.size();++i)pre[i]=max(pre[i-1],vec[i].first+i);
	for(int i=(int)vec.size()-2;i>=0;--i)suf[i]=max(suf[i+1],vec[i].first+i-1);
	for(int i=0;i<vec.size();++i){int v=vec[i].second;if(~v)dfs2(v,max(1,max(!i?0:pre[i-1],i==(int)vec.size()-1?0:suf[i+1])));	}
}
int Ask(int u){printf("? %d\n",u);ff;cin>>u;return u;}
vector<int> ans;
int dfs3(int u){
	vector<pair<int,int> > vec;
	for(auto v:G[u]){if(v==f[u])continue;vec.emplace_back(dp[v],v);}
	if(vec.empty())return Ask(u);
	sort(vec.begin(),vec.end(),greater<pair<int,int> >());
	if(u^rt){for(auto [w,v]:vec){int x=dfs3(v);if(x^u)return x;}return u;}
	for(auto [w,v]:vec){int x=dfs3(v);if(x^u)ans.push_back(x);if(ans.size()==2)break;}
	while(ans.size()<2)ans.push_back(u);
	return 233;
}
int main(){
	cin>>n;
	if(n==1){printf("0\n! 1 1\n");ff;return 0;}
	for(int i=1,u,v;i<n;++i)cin>>u>>v,G[u].push_back(v),G[v].push_back(u);
	dfs1(1),dfs2(1,-1);
	int mx=0;
	for(int i=1;i<=n;++i)mx=max(mx,g[i]);
	printf("%d\n",mx);ff;
	cin>>rt;
	f[rt]=0;
	dfs1(rt),dfs3(rt);
	printf("! %d %d\n",ans[0],ans[1]);ff;
	return 0;
}