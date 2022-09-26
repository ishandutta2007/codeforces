#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
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
int n,c[N],f[N];
vector<int> G[N];
int siz[N],son[N],mx,cnt[N],vis[N];
ll sum,ans[N];
void dfs1(int u,int fa){
	siz[u]=1;
	f[u]=fa;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}
} 
void Change(int u,int val){
	cnt[c[u]]+=val;
	if(cnt[c[u]]>mx)mx=cnt[c[u]],sum=c[u];
	else if(cnt[c[u]]==mx)sum+=c[u];
	for(auto v:G[u]){
		if(v==f[u]||vis[v])continue;
		Change(v,val);
	}
}
void dfs2(int u,bool keep){
	for(auto v:G[u]){
		if(v==f[u]||v==son[u])continue;
		dfs2(v,false);
	}
	if(son[u])dfs2(son[u],true),vis[son[u]]=1;
	Change(u,1);vis[son[u]]=0;
	ans[u]=sum;
	if(!keep)Change(u,-1),sum=mx=0;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		c[i]=read();
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v),G[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;++i){
		printf("%I64d ",ans[i]);
	}
	return 0;
}