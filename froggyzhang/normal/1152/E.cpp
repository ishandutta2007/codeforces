#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
map<int,int> mp;
int n,tot,id[N],a[N],b[N],d[N],vis[N];
vector<pair<int,int> > G[N];
vector<int> ans;
void dfs(int u){
	while(!G[u].empty()){
		int v=G[u].back().first,t=G[u].back().second;
		G[u].pop_back();
		if(vis[t])continue;
		vis[t]=1;
		dfs(v);
	}	
	ans.push_back(id[u]);
}
int main(){
	n=read()-1;
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		b[i]=read();
	}
	for(int i=1;i<=n;++i){
		if(a[i]>b[i])return !printf("-1\n");
		if(!mp.count(a[i]))mp[a[i]]=++tot,id[tot]=a[i];
		if(!mp.count(b[i]))mp[b[i]]=++tot,id[tot]=b[i];
		int u=mp[a[i]],v=mp[b[i]];
		G[u].emplace_back(v,i);
		G[v].emplace_back(u,i);
		++d[u],++d[v];
	}
	int odd=0,S=1;
	for(int i=1;i<=n;++i){
		if(d[i]&1)++odd,S=i;
	}
	if(odd>2){
		return !printf("-1\n");
	}
	dfs(S);
	if((int)ans.size()<=n){
		return !printf("-1\n");
	}
	for(auto x:ans){
		printf("%d ",x);
	}
	printf("\n");
	return 0;
}