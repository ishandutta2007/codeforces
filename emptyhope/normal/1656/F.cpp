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
#define inf 0x3f3f3f3f3f3f3f3f

int n,a[maxn],m;
pii t[maxn];

int inter(pii l1,pii l2)
{
//	cout<<"inter "<<l1.fi<<" "<<l1.se<<' '<<l2.fi<<" "<<l2.se<<endl;
	int x=(l1.se-l2.se)/(l2.fi-l1.fi);
//	cout<<x*l1.fi+l1.se<<" "<<x*l2.fi+l2.se<<endl;
	return x*l1.fi+l1.se;
}

void work()
{
	n=read(),m=0;
	For(i,1,n)a[i]=read();
	sort(a+1,a+n+1);
	int k=0,b=0;
	k+=a[1]+a[n],b+=a[1]*a[n];
	For(i,2,n-1)k+=a[1]+a[i],b+=a[1]*a[i];
	t[++m]=mkp(k,b);
	For(i,2,n-1){
		k-=a[1]+a[i],b-=a[1]*a[i];
		k+=a[n]+a[i],b+=a[n]*a[i];
		t[++m]=mkp(k,b);
	}
	sort(t+1,t+m+1);
	if(t[m].fi<0||t[1].fi>0){
		puts("INF");
		return;
	}
	int mn0=inf;
	For(i,1,m)if(t[i].fi==0)mn0=min(mn0,t[i].se);
	int p1=1,p2=m;
	while(t[p1+1].fi<0)++p1;
	while(t[p2-1].fi>0)--p2;
	if(t[p1].fi<0&&t[p2].fi>0)mn0=min(mn0,inter(t[p1],t[p2]));
	cout<<mn0<<'\n';
}

signed main()
{
	int T=read();
	while(T--)work();
	return 0;
}