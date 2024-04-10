/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define size(x) ((int)x.size())
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define travel(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&-(x))
#define lson root<<1
#define rson root<<1|1
#define Mid (l+r>>1)
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
const int MAXN = 1.5e5 + 10;
const int Mod = 998244353;
vector<int> G[MAXN];
int n,m,dfs_time,tag[MAXN],dep[MAXN],fa[MAXN],id[MAXN],size[MAXN],top[MAXN],son[MAXN];
int opt,u,v,k;
inl char read(){
	static const int IO_LEN=1024*1024;
	static char buf[IO_LEN],*ioh,*iot;
	if(ioh==iot){
		iot=(ioh=buf)+fread(buf,1,IO_LEN,stdin);
		if(ioh==iot) return -1;
	}
	return *ioh++;
}
template<class T>inl void read(T &x){
	static int iosig;static char ioc;
	for(iosig=0,ioc=read();!isdigit(ioc);ioc=read()) if(ioc=='-') iosig=1;
	for(x=0;isdigit(ioc);ioc=read())x=(x<<1)+(x<<3)+(ioc^'0');
	if(iosig) x=-x;
}
template<class T>inl void add(T &a,T b) {a=(a+b)>=Mod?a+b-Mod:a+b;}
inl ll Pow(ll a,ll b,ll ans=1){for(;b;b>>=1,a=a*a%Mod)if(b&1)ans=ans*a%Mod;return ans;}
inl void dfs1(int u,int father,int deep){
	size[u]=1,dep[u]=deep,fa[u]=father;
	for(auto v:G[u]){
		if(v==father) continue;
		dfs1(v,u,deep+1);
		if(size[son[u]]<size[v]) son[u]=v;
		size[u]+=size[v];
	}
}
inl void dfs2(int u,int topfa){
	top[u]=topfa;id[u]=++dfs_time;
	if(son[u]) dfs2(son[u],topfa);
	for(auto v:G[u]) if(v!=son[u] && v!=fa[u]) dfs2(v,v);
}
namespace Bit{
	int c[MAXN];
	inl void update(int x,int k){
		for(;x<=n;x+=lb(x)) add(c[x],k);
	}
	inl int query(int x,int res=0){
		for(;x;x-=lb(x)) add(res,c[x]);
		return res%Mod;
	}
	inl void update(int l,int r,int k){update(l,k),update(r+1,(Mod-k));}
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(m);const int invn = Pow(n,Mod-2);
	rep(i,2,n) read(u),read(v),G[u].pb(v),G[v].pb(u);
	dfs1(1,1,1),dfs2(1,1);
	rep(i,1,m){
		read(opt);
		if(opt==1){
			read(u),read(k);k=1ll*k*invn%Mod,add(tag[u],k);
			if(son[u]) Bit::update(id[son[u]],id[son[u]]+size[son[u]]-1,1ll*(n-size[son[u]])*k%Mod);
			if(u^1) Bit::update(1,id[u]-1,1ll*size[u]*k%Mod),Bit::update(id[u]+size[u],n,1ll*size[u]*k%Mod);
		}else{
			read(u);ll ans=1ll*n*tag[u]%Mod+Bit::query(id[u]);;
			while(u^1) {add(ans,1ll*(tag[fa[top[u]]])*(n-size[top[u]])%Mod);u=fa[top[u]];}
			printf("%d\n",(ans+Mod)%Mod);
		}
	}
	return 0;
}