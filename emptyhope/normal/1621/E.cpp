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

struct frac{
	int x,y;
	frac(){}
	frac(int xx,int yy=1ll):x(xx),y(yy){
		int g=__gcd(abs(x),abs(y));
		if(y<0)g=-g;
		x/=g,y/=g;
	}
	friend frac operator +(frac a,frac b){return frac(a.x*b.y+a.y*b.x,a.y*b.y);}
	friend frac operator -(frac a,frac b){return frac(a.x*b.y-a.y*b.x,a.y*b.y);}
	friend frac operator *(frac a,frac b){return frac(a.x*b.x,a.y*b.y);}
	friend frac operator /(frac a,frac b){return a*frac(b.y,b.x);}
	friend bool operator <(frac a,frac b){return a.x*b.y<b.x*a.y;}
	friend bool operator >(frac a,frac b){return a.x*b.y>b.x*a.y;}
	friend bool operator <=(frac a,frac b){return !(a>b);}
	friend bool operator >=(frac a,frac b){return !(a<b);}
	friend bool operator ==(frac a,frac b){return a.x*b.y==b.x*a.y;}
	friend bool operator !=(frac a,frac b){return !(a==b);}
	frac operator - () {return frac(0)-x;}
};

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 400005
#define inf 0x3f3f3f3f3f3f3f3f

int n,m,k;

int val[maxn<<2],tag[maxn<<2];
inline void up(int p){val[p]=min(val[p<<1],val[p<<1|1]);}
inline void pt(int p,int v){tag[p]+=v,val[p]+=v;}
inline void pd(int p){if(tag[p]) pt(p<<1,tag[p]),pt(p<<1|1,tag[p]),tag[p]=0;}
void build(int p,int l,int r){
	tag[p]=0;
	if(l==r)return val[p]=n-l+1,void();
	int mid=l+r>>1; build(p<<1,l,mid),build(p<<1|1,mid+1,r),up(p);
}
void mdf(int p,int l,int r,int nl,int nr,int v){
	if(l>=nl&&r<=nr)return pt(p,v);
	int mid=l+r>>1; pd(p);
	if(nl<=mid)mdf(p<<1,l,mid,nl,nr,v);
	if(nr>mid)mdf(p<<1|1,mid+1,r,nl,nr,v);
	up(p);
}

frac b[maxn];
int no;
vector<int> a[maxn];

void addin(frac t){
	if(b[n]<t){
		++no;
		return;
	}
	int p=lower_bound(b+1,b+n+1,t)-b;
	mdf(1,1,n,1,p,-1);
}
void out(frac t){
	if(b[n]<t){
		--no;
		return;
	}
	int p=lower_bound(b+1,b+n+1,t)-b;
	mdf(1,1,n,1,p,1);
}
bool OK(){
	return !no && val[1]>=0;
}

void work()
{
	n=read(),m=read();k=0;no=0;
	For(i,1,n)b[i]=frac(read());
	sort(b+1,b+n+1);
	build(1,1,n);
	For(i,1,m){
		int ki=read(),sum=0;
		a[i].resize(ki);
		For(j,0,ki-1)a[i][j]=read(),sum+=a[i][j];
		addin(frac(sum,ki));
	}
	For(i,1,m){
		int ki=a[i].size(),sum=0;
		For(j,0,ki-1)sum+=a[i][j];
		out(frac(sum,ki));
		For(j,0,ki-1){
			addin(frac(sum-a[i][j],ki-1));
			cout<<OK();
			out(frac(sum-a[i][j],ki-1));
		}
		addin(frac(sum,ki));
	}puts("");
}
/*
      
1 2 3 4 .. n
-1-1-1-1-1-1
  
max <= 0 
 
*/
signed main()
{
	int T=read();
	while(T--)work();
	return 0;
}