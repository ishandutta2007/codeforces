// https://www.cnblogs.com/Flying2018/p/acmicpc2874.html problem G

#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
#define ll long long
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
#define mkp make_pair
#define pb push_back
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 300005
#define inf 0x3f3f3f3f

int n,m;
int a[maxn],b[maxn],px[maxn],py[maxn],sx[maxn],sy[maxn],tx,ty;

ll xsum(int l,int r){return sx[r]-sx[l-1];}
ll sum(int x,int y,bool cut)
{
    int res=0;
    if(px[x]<y)
    {
        if(cut)
        {
            if(tx>x && ty>y) res=1;
            if(tx<=x && ty<=y && ty<=px[tx]) res=1;
        }
        int l=py[y];
        return 1ll*l*y+xsum(l+1,x)+1ll*(n-x)*(m-y)-res;
    }
    if(cut)
    {
        if(tx<=x && ty<=y) res=1;
        if(tx>x && ty>y && ty>px[tx]) res=1;
    }
    int r=py[y];
    return 1ll*x*y+(1ll*(r-x)*m-xsum(x+1,r))+1ll*(n-r)*(m-y)-res;
}
bool check(int x)
{
    px[0]=m;
    For(i,1,n)
        for(px[i]=px[i-1];px[i] && a[i]+b[px[i]]>x;px[i]--);
    For(i,1,n) sx[i]=sx[i-1]+px[i];
    py[0]=n;
    For(i,1,m)
        for(py[i]=py[i-1];py[i] && a[py[i]]+b[i]>x;py[i]--);
    ll a0=max(xsum(1,n),1ll*n*m-xsum(1,n)),a1=max(xsum(1,n)-(ty<=px[tx]),1ll*n*m-xsum(1,n)-(ty>px[tx]));
    int p=1;
    For(i,1,n){
        while(p<m && sum(i,p,0)<=sum(i,p+1,0)) p++;
        a0=max(a0,sum(i,p,0));
    }
    p=1;
    For(i,1,n){
        while(p<m && sum(i,p,1)<=sum(i,p+1,1)) p++;
        a1=max(a1,sum(i,p,1));
    }
    return a0!=a1+1;
}

signed main()
{
	n=read(),m=read();
	For(i,1,n)a[i]=read();
	For(i,1,m)b[i]=read();
    tx=a[1],ty=b[1];
    sort(a+1,a+n+1);sort(b+1,b+m+1);
    tx=lower_bound(a+1,a+n+1,tx)-a,ty=lower_bound(b+1,b+m+1,ty)-b;
    int l=a[1]+b[1],r=a[tx]+b[ty],res=a[tx]+b[ty];
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1,res=mid;
        else l=mid+1;
    }
    printf("%d\n",res); 
    return 0;
}