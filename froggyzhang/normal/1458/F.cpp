#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
typedef unsigned long long ull;
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
int n;
vector<int> G[N];
inline void adde(int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}
namespace TCS{
	int dep[N],son[N],siz[N],top[N],f[N],dfn[N],num,id[N];
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
		id[num]=u;
		if(!son[u])return;
		dfs2(son[u],topf);
		for(auto v:G[u]){
			if(v==son[u]||v==f[u])continue;
			dfs2(v,v);
		}
	}
	inline int LCA(int x,int y){
		while(top[x]^top[y]){
			if(dep[top[x]]<dep[top[y]])swap(x,y);
			x=f[top[x]];
		}
		if(dep[x]>dep[y])swap(x,y);
		return x;	
	}
	inline int Dis(int x,int y){
		return dep[x]+dep[y]-2*dep[LCA(x,y)];
	}
	inline int Jump(int x,int d){
		while(true){
			if(d<=dep[x]-dep[top[x]])return id[dfn[x]-d];
			d-=dep[x]-dep[f[top[x]]];
			x=f[top[x]];
		}
	}
	inline int Go(int x,int y,int d){
		int lca=LCA(x,y);
		if(d<=dep[x]-dep[lca])return Jump(x,d);
		return Jump(y,dep[x]+dep[y]-2*dep[lca]-d);	
	}
	void init(){
		dfs1(1);
		dfs2(1,1);	
	}	
}
namespace DFS{
	int rt,f[N],siz[N],maxp[N],vis[N];
	void get_root(int u,int fa,int total){
		maxp[u]=0;
		siz[u]=1;
		for(auto v:G[u]){
			if(v==fa||vis[v])continue;
			get_root(v,u,total);
			siz[u]+=siz[v];
			maxp[u]=max(maxp[u],siz[v]);	
		}
		maxp[u]=max(maxp[u],total-siz[u]);
		if(!rt||maxp[u]<maxp[rt]){
			rt=u;	
		}
	}
	void solve(int u){
		vis[u]=1;
		for(auto v:G[u]){
			if(vis[v])continue;
			rt=0;
			get_root(v,u,siz[v]);
			f[rt]=u;
			solve(rt);
		}
	}
	ll a[N],b[N];
	int t[N];
	void Change(int x,int w){
		for(int u=x;u;u=f[u]){
			a[u]+=w*TCS::Dis(x,u);
			t[u]+=w;
			if(f[u])b[u]+=w*TCS::Dis(x,f[u]);
		}
	}
	ll Query(int x){
		ll ans=0;
		for(int u=x;u;u=f[u]){
			ans+=a[u]+1LL*t[u]*TCS::Dis(u,x);
			if(f[u])ans-=b[u]+1LL*t[u]*TCS::Dis(f[u],x);
		}
		return ans;
	}
	void init(){
		get_root(1,0,n+n-1);
		solve(rt);
	}
}

struct Cir{
	int v,r;
	Cir(int _v=0,int _r=0){v=_v,r=_r;}
	friend Cir operator + (const Cir &a,const Cir &b){
		int d=TCS::Dis(a.v,b.v);
		if(d+a.r<=b.r)return b;
		if(d+b.r<=a.r)return a;
		return Cir(TCS::Go(a.v,b.v,(d-a.r+b.r)/2),(a.r+b.r+d)/2);
	}
	friend bool operator == (const Cir &a,const Cir &b){
		return a.v==b.v&&a.r==b.r;
	}
	friend bool operator != (const Cir &a,const Cir &b){
		return a.v!=b.v&&a.r!=b.r;
	}
	friend int operator ^ (const Cir &a,const Cir &b){
		int d=TCS::Dis(a.v,b.v);
		if(d+a.r<=b.r)return -1;
		if(d+b.r<=a.r)return 1;
		return 0;	
	}
};
ll ans;
void Solve(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	Solve(l,mid),Solve(mid+1,r);
	static Cir L[N],R[N];
	static ll s[N];
	R[mid+1]=Cir(mid+1,0);
	L[mid]=Cir(mid,0);
	for(int i=mid+2;i<=r;++i)R[i]=R[i-1]+Cir(i,0);
	for(int i=mid-1;i>=l;--i)L[i]=L[i+1]+Cir(i,0);
	s[mid]=0;
	for(int i=mid+1;i<=r;++i)s[i]=s[i-1]+R[i].r;
	int j=mid+1,k=mid+1;
	for(int i=mid;i>=l;--i){
		while(j<=r&&(L[i]^R[j])==1){
			DFS::Change(R[j].v,-1);
			++j;
		}
		while(k<=r&&(L[i]^R[k])!=-1){
			DFS::Change(R[k].v,1);
			++k;
		}
		ans+=1LL*(j-1-mid)*L[i].r+s[r]-s[k-1];
		ans+=(DFS::Query(L[i].v)+1LL*(k-j)*L[i].r+s[k-1]-s[j-1])/2;
	}
	for(int i=j;i<k;++i){
		DFS::Change(R[i].v,-1);
	}
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		adde(u,n+i),adde(v,n+i);
	}
	DFS::init();
	TCS::init();
	Solve(1,n);
	printf("%lld\n",ans);
	return 0;
}