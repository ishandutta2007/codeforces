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
typedef vector<int>vi;

#define maxn 405
#define inf 0x3f3f3f3f

int n,m;
char s[405][405];
int a[405][405],ra[405][405];

inline int S(int x,int y,int xx,int yy){
	return a[xx][yy]-a[x-1][yy]-a[xx][y-1]+a[x-1][y-1];
} 

void work()
{
	n=read(),m=read();
	For(i,1,n){
		cin>>s[i]+1;
		For(j,1,m) ra[i][j]=a[i][j]=s[i][j]-'0';
	}
	For(i,1,n)For(j,1,m)a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	int res=inf;
	For(i,1,n)For(j,i+4,n)
	{
		int now=(j-i-1)-S(i+1,1,j-1,1)+S(i+1,2,j-1,3);
		For(p,2,3) now+=(!ra[i][p])+(!ra[j][p]);
		res=min(res,now+j-i-1-S(i+1,4,j-1,4));
		For(k,5,m)
		{
			now+=(!ra[i][k-1])+(!ra[j][k-1]);
			now+=S(i+1,k-1,j-1,k-1);
			int t=(j-i-1)-S(i+1,k-3,j-1,k-3);
			t+=S(i+1,k-2,j-1,k-1);
			For(p,k-2,k-1) t+=(!ra[i][p])+(!ra[j][p]);
			now=min(now,t);
			res=min(res,now+j-i-1-S(i+1,k,j-1,k));
		}
	}
	printf("%d\n",res);
}

signed main()
{
	int T=read();
	while(T--)work();
	return 0;
}