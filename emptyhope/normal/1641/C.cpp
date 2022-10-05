#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
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

#define maxn 400005
#define inf 0x3f3f3f3f

int n,m;

int mx[maxn<<2],val[maxn<<2],tag[maxn<<2],ss[maxn<<2];

void up(int p){
	mx[p]=min(mx[p<<1],mx[p<<1|1]);
	val[p]=val[p<<1]+val[p<<1|1];
}
void build(int p,int l,int r){
	if(l==r)return val[p]=1,mx[p]=n+1,void();
	int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r),up(p);
}

int resmx,ressum;
void dw(int p){
	if(tag[p]) 
		val[p<<1]=val[p<<1|1]=0,tag[p<<1]=tag[p<<1|1]=1,tag[p]=0;
}
void mdf(int p,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr)return val[p]=0,tag[p]=1,void();
	int mid=l+r>>1;dw(p);
	if(ql<=mid)mdf(p<<1,l,mid,ql,qr);
	if(qr>mid)mdf(p<<1|1,mid+1,r,ql,qr); up(p);
}
void mdfmx(int p,int l,int r,int x,int y){
	if(l==r)return mx[p]=min(mx[p],y),void();
	int mid=l+r>>1; dw(p);
	if(x<=mid)mdfmx(p<<1,l,mid,x,y);
	else mdfmx(p<<1|1,mid+1,r,x,y); up(p);
}
void ask(int p,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr)return resmx=min(resmx,mx[p]),ressum+=val[p],void();
	int mid=l+r>>1; dw(p);
	if(ql<=mid)ask(p<<1,l,mid,ql,qr);
	if(qr>mid)ask(p<<1|1,mid+1,r,ql,qr);
}

int boundL(int p,int l,int r,int x){
	if(x<=0)return 0;
	if(!val[p])return 0;
	if(l==r)return l;
	int mid=l+r>>1; dw(p);
	int res=0;
	if(x>mid && val[p<<1|1]) res=boundL(p<<1|1,mid+1,r,x);
	if(res)return res;
	return boundL(p<<1,l,mid,x);
}

signed main()
{
	n=read(),m=read();
	build(1,1,n);
	For(i,1,m){
		int op=read();
		if(op==0){
			int l=read(),r=read(),x=read();
			if(!x)mdf(1,1,n,l,r);
			else mdfmx(1,1,n,l,r);
		}else{
			int x=read();
			resmx=ressum=0,ask(1,1,n,x,x);
			if(!ressum){
				puts("NO");
				continue;
			}
			int pos=boundL(1,1,n,x-1)+1;
			resmx=n+1,ressum=0,ask(1,1,n,pos,x);
			if(resmx==n+1){
				puts("N/A");
				continue;
			}
			int R=resmx;
			resmx=ressum=0,ask(1,1,n,x,R);
			if(ressum>1) puts("N/A");
			else puts("YES");
		}
	}
	return 0;
}