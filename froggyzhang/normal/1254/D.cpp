#include<bits/stdc++.h>
using namespace std;
#define N 150010
typedef long long ll;
const int mod=998244353;
int n,Q,jb[N];
vector<int> G[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int dfn[N],siz[N],num,invn,top[N],son[N],dep[N],f[N];
class BIT{
	int b[N];
	inline int lowbit(int x){
		return x&(-x);
	}
public:
	inline void Add(int x,int d){
		while(x<=n){
			b[x]=(b[x]+d)%mod;
			x+=lowbit(x);
		}
	}
	inline int Ask(int x){
		int ans=0;
		while(x){
			ans=(ans+b[x])%mod;
			x-=lowbit(x);
		}
		return ans;
	}
}B,D;
void dfs1(int u){
	siz[u]=1;
	for(auto v:G[u]){
		if(v==f[u])continue;
		dep[v]=dep[u]+1;
		f[v]=u;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	dfn[u]=++num;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto v:G[u]){
		if(v==f[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
int Query(int u){
	int ans=0;
	while(u){
		if(u^top[u])ans=(ans+D.Ask(dfn[f[u]])-D.Ask(dfn[top[u]]-1))%mod;
		u=top[u];
		if(u^1){
			ans=(ans+1LL*jb[f[u]]*(n-siz[u]))%mod;	
		}
		u=f[u];
	}	
	return (ans+mod)%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	invn=qpow(n,mod-2);
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1);
	dfs2(1,1);
	int tot=0;
	while(Q--){
		int opt,u,d;
		cin>>opt>>u;
		if(opt==1){
			cin>>d;
			d=1LL*d*invn%mod;
			int td=1LL*d*siz[u]%mod;
			B.Add(dfn[u],td);
			B.Add(dfn[u]+siz[u],mod-td);
			tot=(tot+td)%mod;
			jb[u]=(jb[u]+d)%mod;
			if(son[u]){
				D.Add(dfn[u],1LL*d*(n-siz[son[u]])%mod);	
			}
		}
		else{
			int ans=1LL*jb[u]*n%mod;
			ans=((ans+tot-B.Ask(dfn[u]))%mod+mod)%mod;
			ans=(ans+Query(u))%mod;
			cout<<ans<<'\n';
		}
	}
	return 0;
}