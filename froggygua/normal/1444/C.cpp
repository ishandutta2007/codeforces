#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<cassert>
#include<algorithm>
using namespace std;
#define N 1000050
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
int n,m,K,a[N],ok[N],col[N],x[N],y[N],id[N],num;
ll ans;
int myh;
vector<int> d[N],G[N];
inline int fan(int x){
	return ((x-1)^1)+1;
}
bool dfs(int u){
	id[u]=num-col[u];
	for(auto v:G[u]){
		if(a[u]^a[v])continue;
		if(~col[v]){
			if(col[u]==col[v])return false;
		}
		else{
			col[v]=col[u]^1;
			if(!dfs(v))return false;
		}
	}
	return true;
}
map<pair<int,int>,vector<int> > mp;
map<pair<int,int>,bool> vis;
vector<int> vec,T[N];
void adde(int u,int v){
	vec.push_back(u),vec.push_back(v);
	T[u].push_back(v);
	T[v].push_back(u);
}
bool dfs2(int u){
	for(auto v:T[u]){
		if(~col[v]){
			if(col[u]==col[v])return false;
		}
		else{
			col[v]=col[u]^1;
			if(!dfs2(v))return false;
		}
	}
	return true;
}
bool check(){
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	int las=-1;
	for(auto u:vec){
		if(las==fan(u)){
			T[u].push_back(las);
			T[las].push_back(u);
		}
		las=u;
	}
	for(auto u:vec)col[u]=-1;
	for(auto u:vec){
		if(~col[u])continue;
		col[u]=0;
		if(!dfs2(u))return false;
	}
	return true;
}
void Clear(){
	for(auto u:vec){
		T[u].clear();
	}
	vec.clear();
}
int main(){
	n=read(),m=read(),K=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		d[a[i]].push_back(i);
	}
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
		if(a[u]>a[v])swap(u,v);
		x[i]=u,y[i]=v;
		mp[make_pair(a[u],a[v])].push_back(i);
	}
	memset(col,255,sizeof(col));
	for(int i=1;i<=K;++i){
		ok[i]=1;
		for(int u:d[i]){
			if(~col[u])continue; 
			col[u]=0;
			num+=2;
			if(!dfs(u)){
				ok[i]=0;
				break;
			}
		}
	}
	for(int i=1;i<=K;++i)myh+=ok[i];
	ans=1LL*myh*(myh-1)/2;
	for(int i=1;i<=m;++i){
		pair<int,int> u=make_pair(a[x[i]],a[y[i]]);
		if(u.first==u.second)continue;
		if(!ok[u.first]||!ok[u.second])continue;
		if(vis[u])continue;
		vis[u]=1;
		for(auto k:mp[u]){
			adde(id[x[k]],id[y[k]]);
		}
		if(!check())--ans;
		Clear();
	}
	printf("%lld\n",ans);
	return 0;
}