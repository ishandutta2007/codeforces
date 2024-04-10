#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int mo=1e9+7;
const int inf=1e9;
const int N=1e5+10;
int n,cnt,sz[N],h[N],f[N],ms[N],id[N],ff[N],lz[N*4];
ll g[N];vector<int>p[N],st[N],ed[N];
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
void dfs(int x){sz[x]=1;
	for(auto&i:p[x])if(i!=f[x]){
		f[i]=x;h[i]=h[x]+1;
		dfs(i);sz[x]+=sz[i];
		if(!ms[x]||sz[ms[x]]<sz[i])ms[x]=i;
	}
}
void ddfs(int x){id[x]=++cnt;
	if(ms[x]){
		ff[ms[x]]=ff[x];ddfs(ms[x]);
		for(auto&i:p[x])if(i!=f[x]&&i!=ms[x]){
			ff[i]=i;ddfs(i);
		}
	}
}
struct pr{
	ll s0,s1,s2;
	friend pr operator+(const pr&a,const pr&b){
		return{(a.s0+b.s0)%mo,(a.s1+b.s1)%mo,(a.s2+b.s2)%mo};
	}
	friend pr operator+(const pr&a,ll x){
		return{a.s0,(a.s1+x*a.s0)%mo,(a.s2+x*a.s1*2+x*x%mo*a.s0)%mo};
	}
}a[N*4];
void init(int x,int l,int r){
	a[x]={r-l+1,0,0};
	if(l==r)return;
	int m=(l+r)>>1;
	init(x<<1,l,m);init(x<<1|1,m+1,r);
}
void fix(int x,int l,int r,ll y,int L,int R){
	if(l<=L&&r>=R){
		a[x]=a[x]+y;lz[x]=(lz[x]+y)%mo;return;
	}
	int m=(L+R)>>1;
	if(l<=m)fix(x<<1,l,r,y,L,m);
	if(r>m)fix(x<<1|1,l,r,y,m+1,R);
	a[x]=a[x<<1]+a[x<<1|1]+lz[x];
}
int main(){
	scanf("%d",&n);
	ll mul=1;
	rep(i,1,n){int l,r;
		scanf("%d%d",&l,&r);
		(mul*=(g[i]=r-l+1))%=mo;
		g[i]=qk(g[i],mo-2);
		st[l].pb(i);ed[r].pb(i);
	}
	rep(i,2,n){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}
	ff[1]=1;h[1]=1;dfs(1);ddfs(1);init(1,1,n);
	ll totg=0,totgh=0,ans=0;
	rep(i,1,100000){
		for(auto&j:st[i]){
			(totg+=g[j])%=mo;
			(totgh+=g[j]*h[j])%=mo;
			for(int x=j;x;x=f[ff[x]])fix(1,id[ff[x]],id[x],g[j],1,n);
		}
		(ans+=mul*(mo+totg*totgh%mo-a[1].s2))%=mo;
		for(auto&j:ed[i]){
			(totg+=mo-g[j])%=mo;
			(totgh+=mo-g[j]*h[j]%mo)%=mo;
			for(int x=j;x;x=f[ff[x]])fix(1,id[ff[x]],id[x],mo-g[j],1,n);
		}
	}
	printf("%lld\n",ans);
}