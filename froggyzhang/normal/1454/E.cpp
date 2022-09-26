#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
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
int T,n,rts[N],tot,siz[N],vis[N],ins[N];
int isrt[N];
int st[N],top;
vector<int> G[N];
void Find_cir(int u,int fa){
	if(tot)return;
	vis[u]=ins[u]=1;
	st[++top]=u;
	for(auto v:G[u]){
		if(v==fa||tot)continue;
		if(ins[v]){
			while(rts[tot]^v){
				rts[++tot]=st[top--];
				isrt[rts[tot]]=1;
			}
			break;
		}
		Find_cir(v,u);
	}
	--top,ins[u]=0;
}
void dfs(int u,int fa){
	siz[u]=1;
	for(auto v:G[u]){
		if(v==fa||isrt[v])continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
ll Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		G[i].clear();
	}
	for(int i=1;i<=n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
		ins[i]=vis[i]=isrt[i]=0;
	}
	tot=top=0;
	Find_cir(1,0);
	ll ans=0;
	for(int i=1;i<=tot;++i){
		dfs(rts[i],0);
		ans+=1LL*siz[rts[i]]*(siz[rts[i]]-1+2*(n-siz[rts[i]]));
	}
	return ans>>1;
}
int main(){
	T=read();
	while(T--){
		printf("%lld\n",Solve());
	}
	return 0;
}