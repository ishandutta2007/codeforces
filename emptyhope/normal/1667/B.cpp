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
#define mkp make_pair
#define pb push_back
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 500005
#define inf 0x3f3f3f3f

int n,a[maxn],sum[maxn],t[maxn],pos[maxn];

int val[maxn<<2],val2[maxn<<2],val3[maxn<<2],f[maxn];
void mdf(int p,int l,int r,int x,int y,int y2,int y3){
	val[p]=max(val[p],y),val2[p]=max(val2[p],y2),val3[p]=max(val3[p],y3);
	if(l==r)return void();
	int mid=l+r>>1;
	if(x<=mid)mdf(p<<1,l,mid,x,y,y2,y3);
	else mdf(p<<1|1,mid+1,r,x,y,y2,y3);
}
int res1,res2,res3;
void ask(int p,int l,int r,int ql,int qr)
{
	if(ql>qr)return;
	if(l>=ql&&r<=qr)return res1=max(res1,val[p]),res2=max(res2,val2[p]),res3=max(res3,val3[p]),void();
	int mid=l+r>>1;
	if(ql<=mid)(ask(p<<1,l,mid,ql,qr));
	if(qr>mid)(ask(p<<1|1,mid+1,r,ql,qr));
}

void work()
{
	n=read();
	For(i,1,n)a[i]=read(),sum[i]=sum[i-1]+a[i],t[i]=sum[i];
	t[n+1]=0;
	sort(t+1,t+n+2);
	int len=unique(t+1,t+n+2)-t-1;
	For(i,1,n*4)val[i]=val2[i]=val3[i]=-inf;
	pos[0]=lower_bound(t+1,t+len+1,0)-t;
//	cout<<"pos0 "<<pos[0]<<endl;
	mdf(1,1,len,pos[0],0,0,0);
	For(i,1,n){
		pos[i]=lower_bound(t+1,t+len+1,sum[i])-t;
	//	cout<<"pos "<<pos[i]<<endl;
		res1=-inf;
		ask(1,1,len,pos[i]+1,len);
		f[i]=res1-i; 
		res2=-inf;
		ask(1,1,len,pos[i],pos[i]);
		f[i]=max(f[i],res2);
		res3=-inf;
		ask(1,1,len,1,pos[i]-1);
		f[i]=max(f[i],res3+i);
	//	cout<<res1<<" "<<res2<<" "<<res3<<endl;
		mdf(1,1,len,pos[i],f[i]+i,f[i],f[i]-i);
	//	cout<<"f[i] "<<f[i]<<endl;
	}
	cout<<f[n]<<endl;
}

signed main()
{
	int T=read();
	while(T--)work();
    return 0;
}