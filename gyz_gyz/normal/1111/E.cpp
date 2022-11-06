#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 100010
#define mo 1000000007
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,m,tot;vector<int>p[N];ll nt[301];
int a[N],s[N],f[N],ff[N],h[N],mp[N],t[N],w[N],dfn[N],sz[N],c[301][301];
void dfs(int x){sz[x]=1;
	for(auto i:p[x])if(i!=f[x]){
		f[i]=x;h[i]=h[x]+1;dfs(i);sz[x]+=sz[i];
		if(sz[i]>sz[mp[x]])mp[x]=i;
	}
}
void bd(int x){dfn[x]=++tot;
	if(mp[x]){
		ff[mp[x]]=ff[x];bd(mp[x]);
		for(auto i:p[x])if(i!=f[x]&&i!=mp[x]){
			ff[i]=i;bd(i);
		}
	}
}
void cg(int x,int y){
	for(;x<=n;x+=x&(-x))a[x]+=y;
}
int q(int x){int r=0;
	for(;x;x-=x&(-x))r+=a[x];return r;
}
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
int main(){
	c[0][0]=1;nt[0]=1;
	rep(i,1,300){
		c[i][0]=1;nt[i]=nt[i-1]*qk(i,mo-2)%mo;
		rep(j,1,i)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mo;
	}
	scanf("%d%d",&n,&m);
	rep(i,1,n-1){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}
	f[1]=ff[1]=1;dfs(1);bd(1);
	rep(i,1,m){int k,r,m;ll ans=0; 
		scanf("%d%d%d",&k,&m,&r);
		rep(j,1,k){
			scanf("%d",&t[j]);cg(dfn[t[j]],1);
		}
		rep(j,1,k){
			int x=t[j],y=r;w[j]=-1;
			while(ff[x]!=ff[y]){
				if(h[ff[x]]<h[ff[y]])swap(x,y);
				w[j]+=q(dfn[x])-q(dfn[ff[x]]-1);
				x=f[ff[x]];
			}
			if(h[x]<h[y])swap(x,y);
			w[j]+=q(dfn[x])-q(dfn[y]-1);
		}
		rep(j,1,k)cg(dfn[t[j]],-1);
		rep(i0,0,m){s[i0]=1;
			rep(j,1,k)s[i0]=1ll*s[i0]*max(i0-w[j],0)%mo;
			rep(j,0,i0-1)s[i0]=(s[i0]+mo-1ll*c[i0][j]*s[j]%mo)%mo;
			ans=(ans+s[i0]*nt[i0])%mo;
		}
		printf("%lld\n",ans);
	}
}