#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
//#define int long long
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
	friend modint operator +(modint a,modint b){return a+=b;}
	friend modint operator -(modint a,modint b){return a-=b;}
	friend modint operator *(modint a,modint b){return a*=b;}
	friend modint operator /(modint a,modint b){return a/=b;}
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
#define mkp make_pair
#define pb push_back
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 300005
#define inf 0x3f3f3f3f

int n,m,eu[maxn],ev[maxn],ew[maxn],fa[maxn];
int getf(int x){
	while(x^fa[x])x=fa[x]=fa[fa[x]];
	return x;
}
vector<pii> e[maxn];
void add(int u,int v,int w){
	e[u].pb(mkp(v,w));
	e[v].pb(mkp(u,w));
}

int c[maxn];
bool vis[maxn];
void dfs(int u,int pa){
	for(auto t:e[u]){
		if(t.fi!=pa){
			dfs(t.fi,u);
			c[u]^=c[t.fi];
			vis[t.se]=c[t.fi];
		}
	}
}
void work()
{
	n=read(),m=read();
	For(i,1,n)fa[i]=i,e[i].clear();
	vi o;
	For(i,1,m){
		eu[i]=read(),ev[i]=read();
		if(getf(eu[i])!=getf(ev[i])){
			fa[getf(eu[i])]=getf(ev[i]); 
			add(eu[i],ev[i],i);
			ew[i]=0;
		}else{
			ew[i]=1;
			o.pb(i);
		}
	}
	if(o.size()==3){
		For(i,1,n)fa[i]=i;
		bool bo=0;
		for(auto i:o){
			if(getf(eu[i])==getf(ev[i])){
				bo=1;
			}
			fa[getf(eu[i])]=getf(ev[i]);
		}
		if(bo){
			For(i,1,n)c[i]=0;
			int t=o[2];
			c[eu[t]]^=1,c[ev[t]]^=1;
			dfs(1,0);
			int u=eu[t];
			for(auto it:e[u])
				if(vis[it.se]){
					ew[t]=0;
					ew[it.se]=1;
					break;
				}
		}
	}
	For(i,1,m)cout<<ew[i];puts(""); 
}

signed main()
{
	int T=read();
	while(T--)work();
	return 0;
}

/*

*/