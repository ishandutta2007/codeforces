#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 200020
typedef long long ll;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N];
vector<int> G[N],rts;
ll dp[N],ans;
void dfs1(int u,int fa){
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs1(v,u);
		if(dp[v]>=0){
			dp[u]+=dp[v];
		}
	}
	dp[u]+=a[u];
	ans+=dp[u];
}
void dfs2(int u,int fa){
	for(auto v:G[u]){
		if(v==fa)continue;
		if(dp[v]>=0)dfs2(v,u);
	}
	printf("%d ",u);
	for(auto v:G[u]){
		if(v==fa)continue;
		if(dp[v]<0)dfs2(v,u);
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		int x=read();
		if(~x)G[x].push_back(i);
		else rts.push_back(i);
	}
	for(auto u:rts){
		dfs1(u,0);
	}
	printf("%I64d\n",ans);
	for(auto u:rts){
		dfs2(u,0);
	}
	return 0;
}