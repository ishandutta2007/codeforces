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

#define maxn 200005
#define inf 0x3f3f3f3f
int n,m;
bool a[maxn],b[maxn];
int res[maxn];
inline int ceil(int x){
	return x/100000+(x%100000>0);
}
signed main()
{
	memset(res,-1,sizeof res);
	n=read(),m=read();
	res[0]=0,a[0]=1;
	For(i,1,n)
	{
		int o=read(),x=read(),y=read();
		if(o==1){
			x=x/100000+(x%100000>0);
			For(j,0,m)
				if(a[j]){
					int t=j+x,cnt=y;
					while(t<=m && !a[t] && cnt)
						b[t]=1,res[t]=i,t+=x,--cnt;
				}
		}else{
			For(j,0,m)
				if(a[j]){
					int t=ceil(j*x),cnt=y;
					while(t<=m && !a[t] && cnt)
						b[t]=1,res[t]=i,t=ceil(t*x),--cnt;
				}
		}For(j,1,m)a[j]|=b[j];
	}
	For(i,1,m)printf("%lld ",res[i]);
	return 0;
}