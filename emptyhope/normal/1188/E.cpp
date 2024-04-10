#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
//#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

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

#define maxn 1100005
modint fac[maxn],ifac[maxn];
inline void prework(int n){
	fac[0]=1;
	For(i,1,n)fac[i]=fac[i-1]*i;
	ifac[n]=1/fac[n];
	Rep(i,n-1,0)ifac[i]=ifac[i+1]*(i+1);
}
inline modint C(int n,int m){
	if(n<0||m<0||n<m)return 0;
	return fac[n]*ifac[m]*ifac[n-m];
}

int n,mx,a[maxn],cnt[maxn];
int nd[maxn];
bool vis[maxn];
signed main()
{
	n=read();mx=n;
	For(i,1,n)a[i]=read(),mx=max(mx,a[i]),++cnt[a[i]];
	prework(n+mx);
	sort(a+1,a+n+1);
	For(i,0,mx)
		if(cnt[i]){
			for(int j=i+1;j<=mx;j+=n)
				nd[j]+=cnt[i];
		}
	For(i,1,mx) nd[i]+=nd[i-1];
	For(i,1,n) vis[i]=(a[i]>=i-1);
	bool ok=1;
	int j=0;
	modint res=0;
	For(i,1,mx){
		while(j<n&&a[j+1]<i) j++,ok&=vis[j];
		if(!ok)break;
		res+=C(i-nd[i]+n-1,n-1)-C(i-nd[i]+n-1-(n-j),n-1);
	}
	res+=1;
	cout<<res.x;
	return 0;
}