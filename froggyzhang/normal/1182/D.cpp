#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
#define N 100010
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
vector<int> G[N];
int n,siz[N],d[N],root,root1,maxp[N],h[N],cnt[N],maxdep[N],vis[N];
void get_root(int u,int fa,int total){
	siz[u]=1;
	for(auto v:G[u]){
		if(v==fa)continue;
		get_root(v,u,total);
		siz[u]+=siz[v];
		maxp[u]=max(maxp[u],siz[v]);
	}
	maxp[u]=max(maxp[u],total-siz[u]);
	if(!root||maxp[u]<maxp[root]){
		root1=0,root=u;
	}
	else if(maxp[u]==maxp[root]){
		root1=u;
	}
}
void dfs1(int u,int fa,int dep,int from){
	if(vis[dep]^from){
		vis[dep]=from;
		if(!cnt[dep])h[dep]=G[u].size(),cnt[dep]=1;
		else if(h[dep]==G[u].size())++cnt[dep];
		else --cnt[dep];
	}
	maxdep[u]=dep;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs1(v,u,dep+1,from);
		maxdep[u]=max(maxdep[u],maxdep[v]);
	}
}
bool dfs(int u,int fa,int dep){
	if(h[dep]^((int)G[u].size()))return false;
	for(auto v:G[u]){
		if(v==fa)continue;
		if(!dfs(v,u,dep+1))return false;
	}
	return true;
}
int get_that(int u,int fa){
	if(G[u].size()==1)return u;
	map<int,int> mp;
	for(auto v:G[u]){
		if(v==fa)continue;
		++mp[maxdep[v]];
	}
	for(auto v:G[u]){
		if(v==fa)continue;
		if(mp[maxdep[v]]==1){
			return get_that(v,u);
		}
	}
	for(auto v:G[u]){
		if(v==fa)continue;
		return get_that(v,u);
	}
}
bool check(int u){
	memset(h,0,sizeof(h));
	memset(cnt,0,sizeof(cnt));
	memset(vis,0,sizeof(vis));
	for(auto v:G[u]){
		dfs1(v,u,1,v);
	}
	for(auto v:G[u]){
		if(!dfs(v,u,1))return false;
	}
	return true;
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bool ok=true;
	int d0=1;
	for(int i=1;i<=n;++i){
		if(G[i].size()==1){
			d0=i;
		}
		else if(G[i].size()>2){
			ok=false;
		}
	}
	if(ok){
		printf("%d\n",d0);
		return 0;
	}
	root=root1=0;
	get_root(1,0,n);
	int qwq=-1,gu=0;
	for(auto v:G[root]){
		dfs1(v,root,1,v);
	}
	for(auto v:G[root]){
		if(!dfs(v,root,1)){
			++gu,qwq=v;
		}
	}
	if(!gu){
		printf("%d\n",root);
		return 0;
	}
	else if(gu>1){
		printf("%d\n",-1);
		return 0;
	}
	int s=get_that(qwq,root);
	if(check(s)){
		printf("%d\n",s);
		return 0;
	}
	if(G[root].size()<=2){
		for(auto v:G[root]){
			if(v==qwq)continue;
			s=get_that(v,root);
			if(check(s)){
				printf("%d\n",s);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}