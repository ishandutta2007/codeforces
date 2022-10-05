#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
//#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
 
#define mod 998244353
struct modint{
    int x;
    modint(int o=0){x=o;}
    modint &operator = (int o){return x=o,*this;}
    modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
    modint &operator ^=(int b){
        modint a=*this,c=1;
        for(;b;b>>=1,a*=a)if(b&1)c*=a;
        return x=c.x,*this;
    }
    modint &operator /=(modint o){return *this *=o^=mod-2;}
    modint &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint &operator *=(int o){return x=1ll*x*o%mod,*this;}
    modint &operator /=(int o){return *this *= ((modint(o))^=mod-2);}
    template<class I>friend modint operator +(modint a,I b){return a+=b;}
    template<class I>friend modint operator -(modint a,I b){return a-=b;}
    template<class I>friend modint operator *(modint a,I b){return a*=b;}
    template<class I>friend modint operator /(modint a,I b){return a/=b;}
    friend modint operator ^(modint a,int b){return a^=b;}
    friend bool operator ==(modint a,int b){return a.x==b;}
    friend bool operator !=(modint a,int b){return a.x!=b;}
    bool operator ! () {return !x;}
    modint operator - () {return x?mod-x:0;}
};
inline modint qpow(modint x,int y){return x^y;}

vector<modint> fac,ifac,iv;
inline void initC(int n)
{
    if(iv.empty())fac=ifac=iv=vector<modint>(2,1);
    int m=iv.size(); ++n;
    if(m>=n)return;
    iv.resize(n),fac.resize(n),ifac.resize(n);
    For(i,m,n-1){
        iv[i]=iv[mod%i]*(mod-mod/i);
        fac[i]=fac[i-1]*i,ifac[i]=ifac[i-1]*iv[i];
    }
}
inline modint C(int n,int m){
    if(m<0||n<m)return 0;
    return initC(n),fac[n]*ifac[m]*ifac[n-m];
}
inline modint sign(int n){return (n&1)?(mod-1):(1);}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 1000005
#define inf 0x3f3f3f3f

int n,m,q,fa[maxn],dep[maxn];
vi G[maxn],e[maxn];

bool vis[maxn];

void dfs(int u){
	for(auto v:G[u]){
		if(v==fa[u])continue;
		if(!dep[v]){
			dep[v]=dep[u]+1,fa[v]=u,e[u].pb(v);
			dfs(v);
		}
	}
}

int x[maxn],y[maxn],l[maxn];
inline int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	while(dep[u]>dep[v])u=fa[u];
	while(u!=v)u=fa[u],v=fa[v];
	return u; 
}

int ans=0;
int sz[maxn];
void getans(int u){
	for(auto v:e[u]){
		getans(v);
		sz[u]+=sz[v];
		if((sz[v]&1)^vis[v]) sz[u]++,ans++;
	}
}

signed main()
{
	n=read(),m=read();
	For(i,1,m){
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dep[1]=1,dfs(1);
	q=read();
	For(i,1,q){
		x[i]=read(),y[i]=read(),l[i]=lca(x[i],y[i]);
		int u=x[i];
		while(u!=l[i])vis[u]^=1,u=fa[u];
		u=y[i];
		while(u!=l[i])vis[u]^=1,u=fa[u];
	}
	For(i,1,n)
		if(vis[i]){
			puts("NO");
			getans(1);
			cout<<(ans+1)/2<<endl;
			exit(0);
		}
	puts("YES");
	For(i,1,q){
		int u=x[i],v=y[i];
		cout<<dep[u]+dep[v]-2*dep[l[i]]+1<<endl;
		vi o,o2;
		while(u!=l[i]) o.pb(u),u=fa[u];
		o.pb(l[i]);
		while(v!=l[i]) o2.pb(v),v=fa[v];
		for(auto t:o)cout<<t<<" ";
		reverse(o2.begin(),o2.end());
		for(auto t:o2)cout<<t<<" ";
		puts("");
	}
	return 0;
}