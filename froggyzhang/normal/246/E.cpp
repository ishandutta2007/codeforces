#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<string>
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
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
map<string,int> mp;
vector<int> G[N];
vector<pair<int,int> > q[N];
int n,m,c[N],k,ans[N],dep[N],son[N],siz[N],vis[N];
map<int,int> cnt[N];
void dfs1(int u){
	siz[u]=1;
	for(auto v:G[u]){
		dep[v]=dep[u]+1;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}
} 
void calc(int u,int val){
	cnt[dep[u]][c[u]]+=val;
	if(!cnt[dep[u]][c[u]])cnt[dep[u]].erase(c[u]);
	for(auto v:G[u]){
		if(vis[v])continue;
		calc(v,val);
	}
}
void dfs2(int u,bool keep){
	for(auto v:G[u]){
		if(v==son[u])continue;
		dfs2(v,false);
	}
	if(son[u])dfs2(son[u],true),vis[son[u]]=1;
	calc(u,1);vis[son[u]]=0;
	for(auto qwq:q[u]){
		int x=qwq.first,id=qwq.second;
		ans[id]=(x+dep[u]>n)?0:cnt[x+dep[u]].size();
	}
	if(!keep)calc(u,-1);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		string s;
		cin>>s;
		if(mp.count(s))c[i]=mp[s];
		else c[i]=mp[s]=++k;
		int fa=read();
		G[fa].push_back(i);
	}
	m=read();
	for(int i=1;i<=m;++i){
		int u=read(),dep=read();
		q[u].emplace_back(dep,i);
	}
	dfs1(0);
	dfs2(0,false);
	for(int i=1;i<=m;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}