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
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

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

#define maxn 500005
#define inf 0x3f3f3f3f
#define ull unsigned long long
struct P{
	int x,y;
	inline P&operator -=(P o){return x-=o.x,y-=o.y,*this;}
	inline friend P operator -(P a,P b){return a-=b;}
	inline friend int operator %(P a,P b){return a.x*b.y-a.y*b.x;}
};
struct modP{
	modint x,y;
	inline modP&operator +=(P b){return x+=(b.x%mod+mod)%mod,y+=(b.y%mod+mod)%mod,*this;}
	inline modP&operator -=(modP b){return x-=b.x,y-=b.y,*this;}
	inline friend modint operator %(modP a,P b){return a.x*((b.y%mod+mod)%mod)-a.y*((b.x%mod+mod)%mod);}
};
inline modP mul(modint a,P b){return (modP){a*((b.x%mod+mod)%mod),a*((b.y%mod+mod)%mod)};}

int n,cnt;
P a[maxn];
ull sum,now;
modint res,orz;
modP p;
signed main()
{
	n=read();
	For(i,0,n-1)a[i].x=read(),a[i].y=read();
	For(i,2,n-1)sum+=((a[i]-a[0])%(a[i-1]-a[0]));
	now=0; int j=0;
	cnt=1ll*n*(n-3);
	
	For(i,0,n-1)
	{
		while(1)
		{
			int k=(j+1)%n;
			ull qwq=(a[k]-a[i])%(a[j]-a[i]);
			if(2*(qwq+now)>=sum){
				if(2*(qwq+now)==sum) cnt--;
				break;
			}
			now+=qwq;
			orz+=(now%mod);
			p+=(a[k]-a[i]);
			j=k;
		}
		res-=orz*2;
		if(i!=n-1)
		{
			now-=(a[j]-a[i])%(a[i+1]-a[i]);
			orz-=p%(a[i+1]-a[i]);
			p-=mul(modint((j-i+n)%n) , a[i+1]-a[i]);
		}
	}
	cnt/=2;
	res+=(cnt%mod*(sum%mod)%mod);
	cout<<res.x;
	return 0;
}