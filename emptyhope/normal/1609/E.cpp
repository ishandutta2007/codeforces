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

int n,m;
char s[maxn];

struct mat{
	int a[3][3];
	void init(){memset(a,63,sizeof a);}
	mat(){init();}
	mat operator *(const mat&b)const{
		mat c;
		For(i,0,2)For(j,0,2)For(k,0,2)
			c.a[i][j]=min(c.a[i][j],a[i][k]+b.a[k][j]);
		return c;
	}
};

mat getmat(int c){
	mat res;
	For(i,0,2) res.a[i][i]=(i==c);
	if(c==0) res.a[0][1]=0;
	if(c==1) res.a[1][2]=0;
	return res;
}

mat val[maxn<<2];
inline void up(int p){
	val[p]=val[p<<1]*val[p<<1|1];
}
void build(int p,int l,int r){
	if(l==r) return val[p]=getmat(s[l]-'a'),void();
	int mid=l+r>>1; build(p<<1,l,mid),build(p<<1|1,mid+1,r),up(p);
}
void mdf(int p,int l,int r,int x){
	if(l==r) return val[p]=getmat(s[l]-'a'),void();
	int mid=l+r>>1; x<=mid?mdf(p<<1,l,mid,x):mdf(p<<1|1,mid+1,r,x); up(p);
}

signed main()
{
	n=read(),m=read(),cin>>s+1;
	build(1,1,n);
	For(i,1,m){
		int x=read(); cin>>s[x];
		mdf(1,1,n,x);
		int res=inf;
		For(c,0,2) res=min(res,val[1].a[0][c]);
		cout<<res<<endl;
	}
	return 0;
}