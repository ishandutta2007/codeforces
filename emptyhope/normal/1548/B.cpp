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

#define mod 1000000007
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
 
#define maxn 200005
#define inf 0x3f3f3f3f

int n;
int a[maxn],b[maxn],res;
int g[maxn];
inline int gcd(int x,int y){
	if(!y)return x;
	return gcd(y,x%y); 
}
void solve(int l,int r)
{
	if(l==r){
		if(b[l]!=1) res=max(res,1ll);
		return;
	}
	int mid=l+r>>1;
	solve(l,mid),solve(mid+1,r);
	g[mid]=b[mid],g[mid+1]=b[mid+1];
	Rep(i,mid-1,l) g[i]=gcd(g[i+1],b[i]);
	For(i,mid+2,r) g[i]=gcd(g[i-1],b[i]);
	int p=mid,now=0;
	For(i,l,mid){
		if(g[i]==1)continue;
		while(p<r && gcd(gcd(now,g[i]),g[p+1])!=1) ++p,now=gcd(now,g[p]);
	//	cout<<i<<" "<<p<<endl;
		res=max(res,p-i+1);
	}
}

signed main()
{
	int T=read();
	while(T--){
		n=read();
		For(i,0,n+1) a[i]=b[i]=g[i]=0;
		For(i,1,n)a[i]=read();
		For(i,1,n-1)b[i]=(a[i]>a[i+1]?a[i]-a[i+1]:a[i+1]-a[i]);
		if(n>1)res=0,solve(1,n-1);
		else res=0;
		cout<<res+1<<endl;
	}
	return 0;
}