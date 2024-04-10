#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
	char c=getchar();int x=0;bool f=0;
	for(;!isdigit(c);c=getchar())f^=!(c^45);
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	if(f)x=-x;return x;
}
// modint
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
	bool operator <(const modint&b)const{return x<b.x;}
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

#define maxn 200005
#define inf 0x3f3f3f3f

int n;
bool vis[maxn];
int cnt[maxn],mx[maxn],mn[maxn];
vector<pair<int,pii> >e[maxn];

vi dv[maxn];

void dfs(int u,int pa)
{
	for(auto it:e[u]){
		int v=it.fi;
		if(v==pa)continue;
		int xu=it.se.fi,xv=it.se.se;
		for(auto x:dv[xu])++cnt[x],mx[x]=max(mx[x],cnt[x]);
		for(auto x:dv[xv])--cnt[x],mx[x]=max(mx[x],cnt[x]);
		dfs(v,u);
		for(auto x:dv[xu])--cnt[x],mx[x]=max(mx[x],cnt[x]);
		for(auto x:dv[xv])++cnt[x],mx[x]=max(mx[x],cnt[x]);
	}
}

modint res=0;

void dfs2(int u,int pa,modint nw)
{
	res+=nw;
	for(auto it:e[u]){
		int v=it.fi;
		if(v==pa)continue;
		int xu=it.se.fi,xv=it.se.se;
		modint nx=nw/xu*xv;
		dfs2(v,u,nx);
	}
}

void work()
{
	n=read();res=0;
	For(i,1,n)e[i].clear();
	For(i,2,n){
		int u=read(),v=read(),x=read(),y=read(); 
		int g=__gcd(x,y); x/=g,y/=g;
		e[u].pb(mkp(v,mkp(x,y)));
		e[v].pb(mkp(u,mkp(y,x)));
	}
	For(i,1,n)cnt[i]=mn[i]=mx[i]=0;
	dfs(1,0);
	modint mul=1;
	For(i,1,n)
		if(mx[i]){
			For(j,1,mx[i]) mul*=i;
		}
	dfs2(1,0,mul);
	cout<<res.x<<endl;
}

signed main()
{
	For(i,2,200000)
		if(!vis[i]){
			for(int j=i;j<=200000;j+=i){
				vis[j]=1;
				int u=j;
				while(u%i==0)u/=i,dv[j].pb(i);
			}
		}
	int T=read();
	while(T--)work(); 
	return 0;
}