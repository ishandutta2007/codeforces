// what is matter? never mind. 
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define int long long
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
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 250005 
#define inf 0x3f3f3f3f3f3f3f3f

int n,m;
int w[maxn],U[maxn],V[maxn];

vi e[maxn];
int d[505][505];
void bfs(int u,int*d){
	For(i,0,n+1)d[i]=-1;
	d[u]=0;queue<int>q;q.push(u);
	while(q.size()){
		int x=q.front();q.pop();
		for(auto v:e[x]){
			if(d[v]==-1){
				d[v]=d[x]+1;
				q.push(v);
			}
		}
	}
}

void work()
{
	n=read(),m=read();
	For(i,0,n)e[i].clear();
	For(i,1,m){
		int u=read(),v=read();
		w[i]=read();U[i]=u,V[i]=v;
		e[u].pb(v),e[v].pb(u);
	}
	For(i,1,n)bfs(i,d[i]);
	int res=inf;
	For(i,1,m){
		int u=U[i],v=V[i];
		int c=min(d[1][u]+d[n][v],d[n][u]+d[1][v]);
		For(x,1,n) c=min(c,min(d[u][x]+1+d[x][1]+d[x][n],d[v][x]+1+d[x][1]+d[x][n]));
		res=min(res,(c+1)*w[i]);
	}
	cout<<res<<"\n";
}

signed main()
{
//	For(i,1,100){
//		int j=floor(sqrt(i));
//		if(i%j==0)cout<<i<<"\n";
//	}
//	For(i,1,100)if(calc(i)!=calc(i-1))cout<<i<<'\n';
	int T=read();
	while(T--)work(); 
	return 0;
}