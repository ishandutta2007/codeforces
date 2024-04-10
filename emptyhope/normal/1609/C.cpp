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

#define maxn 1000005
#define inf 0x3f3f3f3f

int pri[maxn],tot;
int mu[maxn],smu[maxn];
bool vis[maxn];
void prework(int n)
{
	vis[1]=1,mu[1]=1;
	For(i,2,n)
	{
		if(!vis[i])pri[++tot]=i,mu[i]=-1;
		For(j,1,tot)
		{
			if(i*pri[j]>n)break;
			vis[i*pri[j]]=1;
			if(i%pri[j])mu[i*pri[j]]=-mu[i];
			else break;
		}
	}
	For(i,1,n)smu[i]=smu[i-1]+mu[i];
}

int n,k,res,a[maxn];
int b[maxn],m;
int solve(int o)
{
	m=0;
	for(int u=o;u<=n;u+=k) b[++m]=a[u];
	For(i,1,m){
		if(b[i]==1) b[i]=0;
		else if(!vis[b[i]]) b[i]=1;
		else b[i]=2;
	}
	int res=0;
//	For(i,1,m) cout<<b[i]<<" ";puts("");
	For(i,1,m)
		if(b[i]==1){
			int l=i,r=i;
			while(l>1 && b[l-1]==0)--l;
			while(r<m && b[r+1]==0)++r;
			res+=(i-l+1)*(r-i+1)-1;
		}
	return res;
}
void work()
{
	n=read(),k=read(),res=0;
	For(i,1,n)a[i]=read();
	For(i,1,k)res+=solve(i);
	cout<<res<<endl;
}

signed main()
{
	prework(1e6);
	int T=read();
	while(T--)work();
	return 0;
}