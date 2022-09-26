//qwq
#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int mod=1e9+7;
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
int n,a[N],b[N],w[N],inv[N],g[N];
bool ntp[N];
int p[N],mu[N],phi[N],pn,ans;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n){
	ntp[1]=phi[1]=mu[1]=1;
	for(int i=2;i<=n;++i){
		if(!ntp[i])p[++pn]=i,phi[i]=i-1,mu[i]=-1;
		for(int j=1;j<=pn&&p[j]*i<=n;++j){
			ntp[p[j]*i]=true;
			if(i%p[j]==0){
				phi[p[j]*i]=phi[i]*p[j];
				break;
			}
			phi[p[j]*i]=phi[i]*(p[j]-1);
			mu[p[j]*i]=-mu[i];
		}
	}
	inv[1]=1;
	for(int i=2;i<=n;++i){
		inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;i*j<=n;++j){
			g[i*j]=(g[i*j]+1LL*mu[i]*j*inv[phi[j]])%mod;		
		}
		g[i]=(g[i]+mod)%mod;
	}
}
int f[N],dep[N],siz[N],son[N],top[N];
int dfn[N],num;
vector<int> G[N],H[N];
void dfs1(int u){
	dep[u]=dep[f[u]]+1;
	siz[u]=1;
	for(auto v:G[u]){
		if(v==f[u])continue;
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
int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
inline void adde(int u,int v){
	H[u].push_back(v);
}
int tmp,c[N];
void dfs3(int u){
	tmp=(tmp+2LL*c[u]*c[u]%mod*(mod-dep[u]))%mod;
	for(auto v:H[u]){
		dfs3(v);
		tmp=(tmp+4LL*c[u]*c[v]%mod*(mod-dep[u]))%mod;
		c[u]=(c[u]+c[v])%mod;
	}	
}
int Solve(int tot){
	static int st[N],top;
	static vector<int> bin;
	bin.clear();
	bin.push_back(1);
	st[top=1]=1;
	sort(a+1,a+tot+1,[&](int i,int j){return dfn[i]<dfn[j];});
	for(int i=1;i<=tot;++i){
		int u=a[i];
		c[u]=(c[u]+phi[w[u]])%mod;
		if(u==1)continue;
		bin.push_back(u);
		int lca=LCA(st[top],u);
		while(top>1&&dfn[st[top-1]]>=dfn[lca]){
			adde(st[top-1],st[top]),--top;
		}
		if(lca^st[top]){
			bin.push_back(lca);
			adde(lca,st[top]);
			st[top]=lca;
		}
		st[++top]=u;
	}
	while(top>1)adde(st[top-1],st[top]),--top;
	tmp=0;
	int all=0;
	for(int i=1;i<=tot;++i){
		all=(all+phi[w[a[i]]])%mod;	
	}
	for(int i=1;i<=tot;++i){
		tmp=(tmp+2LL*all*phi[w[a[i]]]%mod*dep[a[i]])%mod;
	}
	dfs3(1);
	for(auto u:bin){
		c[u]=0,H[u].clear();
	}
	return tmp;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		w[i]=read();
		b[w[i]]=i;
	}
	init(n);
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1);
	dfs2(1,1);
	for(int i=1;i<=n;++i){
		int tot=0;
		for(int j=i;j<=n;j+=i){
			a[++tot]=b[j];
		}
		ans=(ans+1LL*g[i]*Solve(tot))%mod;
	}
	ans=1LL*ans*qpow(1LL*n*(n-1)%mod,mod-2)%mod;
	printf("%d\n",ans);
	return 0;
}