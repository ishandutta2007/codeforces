#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
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

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 200005
#define inf 0x3f3f3f3f

int n,l,r,res,c[maxn],d[maxn];
void work()
{
	n=read(),l=read(),r=read();
	For(i,1,n)c[i]=d[i]=0;
	For(i,1,l){
		int x=read();
		c[x]++;
	}
	For(i,1,r){
		int x=read();
		d[x]++;
	}
	For(i,1,n){
		int t=min(c[i],d[i]);
		c[i]-=t,d[i]-=t,l-=t,r-=t;
	}
	if(l>r){
		swap(l,r);
		For(i,1,n)swap(c[i],d[i]);
	}
	//l<r
	int now=r-l,res=0;
	For(i,1,n)
		if(d[i]>=2 && now){
			int t=min(now,d[i]/2*2);
			d[i]-=t,now-=t,res+=t/2;
		}
	res+=now;
	For(i,1,n)res+=c[i];
	cout<<res<<endl; 
}

signed main()
{
	int T=read();
	while(T--)work();
	return 0;
}