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

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 200005
#define inf 0x3f3f3f3f

int n,m,q,a[105],b[maxn],a1b1;

int val[maxn<<2],tag[maxn<<2],sum[maxn<<2],sz[maxn<<2],mn[maxn<<2];
inline void up(int p){
	sum[p]=sum[p<<1]+sum[p<<1|1];
	val[p]=val[p<<1]+val[p<<1|1]+sum[p<<1]*sz[p<<1|1];
	mn[p]=min(mn[p<<1],mn[p<<1|1]);
}
inline void pt(int p,int v){
	int len=sz[p];
	sum[p]+=len*v;
	tag[p]+=v;
	mn[p]+=v;
	val[p]+=v*len*(len+1)/2; 
}
inline void pd(int p){
	if(tag[p])
		pt(p<<1,tag[p]),pt(p<<1|1,tag[p]),tag[p]=0;
}
void build(int p,int l,int r){
	tag[p]=0,sz[p]=r-l+1;
	if(l==r){
		val[p]=sum[p]=mn[p]=b[l];
		return;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r),up(p);
}
int qsum(int p,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr)return sum[p];
	int mid=l+r>>1,res=0; pd(p);
	if(ql<=mid)res+=qsum(p<<1,l,mid,ql,qr);
	if(qr>mid)res+=qsum(p<<1|1,mid+1,r,ql,qr);
	return res; 
}
int bound(int p,int l,int r,int v){
	// find last b[i]<=v
	if(mn[p]>v) return 0;
	if(l==r) return l-1;
	int mid=l+r>>1; pd(p);
	int res=bound(p<<1|1,mid+1,r,v);
	if(res)return res;
	res=bound(p<<1,l,mid,v);
	return res;
}
void mdf(int p,int l,int r,int nl,int nr,int v){
	if(l>=nl&&r<=nr)return pt(p,v);
	int mid=l+r>>1; pd(p);
	if(nl<=mid) mdf(p<<1,l,mid,nl,nr,v);
	if(nr>mid) mdf(p<<1|1,mid+1,r,nl,nr,v);
	up(p); 
} 

void getans()
{
	int res=0;
	res+=a1b1*(n+m-1);
	res+=val[1];// b[]
//	cout<<"val1 "<<val[1]<<endl;
	// val = sum(b[i]*(m-i+1)) 
	For(i,2,n){
		int p=bound(1,2,m,a[i]);
	//	cout<<"i: "<<i<<" "<<a[i]<<' '<<p<<endl;
	//	cout<<"addv "<<(n-i+m-p)<<endl;
		// <=p : <=a[i] ,  a[i] 
		res+=(n-i+m-p)*a[i];
		if(p){
			int tmp=qsum(1,2,m,2,p+1);
	//		cout<<"tmp: "<<tmp<<endl;
			res+=tmp;
		// +1 
		}
	}
	printf("%lld\n",res);
}

signed main()
{
	n=read(),m=read(),q=read();
	For(i,1,n)a[i]=read();
	For(i,1,m)b[i]=read();
	a1b1=a[1]+b[1];
	Rep(i,n,2) a[i]-=a[i-1];
	Rep(i,m,2) b[i]-=b[i-1];
	build(1,2,m);
//	int qwq=0;
//	For(i,1,6)qwq+=i*(7-i);
//	cout<<"qwq: "<<qwq+a1b1*(n+m-1)<<endl;
	For(i,1,q){
		int typ=read(),k=read(),d=read();
		if(typ==1){
			if(k==n)a1b1+=d,--k;
			For(j,n-k+1,n)
				a[j]+=d;
		//	cout<<"A: ";
		//	For(j,2,n)cout<<a[j]<<' ';puts("");
		}else{
			if(k==m)a1b1+=d,--k;
			// (m-k+1,m)
			mdf(1,2,m,m-k+1,m,d);
		}
		getans();
	}
	return 0;
}