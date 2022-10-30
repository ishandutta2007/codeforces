// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=205;
const int mod=10007;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}	
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
int m,a[N],c[N],f[N];
struct poly{
	int a[N];
	poly(){memset(a,0,sizeof(a));}
	poly operator * (const poly &o)
	{
		static ll tmp[N<<1];
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<m;++i) for(int j=0;j<m;++j) tmp[i+j]+=a[i]*o.a[j];
		for(int i=m+m-2;i>=m;--i){tmp[i]%=mod;for(int j=1;j<m;++j) tmp[i-j]+=tmp[i]*c[j];}
		poly ans;for(int i=0;i<m;++i) ans.a[i]=tmp[i]%mod;
		return ans;
	}
};
int getinv(int p)
{
	if(p<0) return 0;
	a[0]=1;for(int j=0;j<m;++j) c[j]=mod-f[j];
	for(int i=1;i<m;++i)
	{
		ll tmp=0;
		for(int j=0;j<i;++j)tmp+=a[j]*c[i-j];
		a[i]=tmp%mod;
	}
	if(p<m) return a[p];
	poly res,A;res.a[0]=1,A.a[1]=1;
	while(p)
	{
		if(p&1) res=res*A;
		A=A*A,p>>=1;
	}
	ll ans=0;for(int i=0;i<m;++i) ans+=res.a[i]*a[i];
	return ans%mod;
}
char s[N];
int dp[N][N][N],g[N],n,L;
int solve(bool type)
{
	ll ans=0;
	for(int a=0;a<=L;++a)if(g[a])
	{
		int b=(L-a+1)>>1;
		memset(f,0,sizeof(f));
		if(type) f[0]=1,f[1]=mod-26,m=2;
		else f[0]=1,m=1;
		for(int i=0;i<a;++i) for(int j=m++;j>=1;--j) sub(f[j],24*f[j-1]%mod);
		for(int i=0;i<b;++i) for(int j=m++;j>=1;--j) sub(f[j],25*f[j-1]%mod);
		ans+=1LL*g[a]*getinv((n+L+1)/2-a-b);
	}
	return ans%mod;
}
int main()
{
	L=read_str(s+1);
	read(n);
	dp[1][L][s[1]!=s[L]]=1;
	for(int len=L;len>=2;--len)
	{
		for(int l=1,r=len;r<=L;++l,++r)
		{
			if(s[l]==s[r]) for(int k=0;k<=L-len+1;++k) add(dp[l+1][r-1][k+(s[l+1]!=s[r-1])],dp[l][r][k]);
			else for(int k=0;k<=L-len+1;++k) add(dp[l+1][r][k+(s[l+1]!=s[r])],dp[l][r][k]),add(dp[l][r-1][k+(s[l]!=s[r-1])],dp[l][r][k]);
		}
	}
	for(int i=0;i<=L;++i) for(int j=1;j<=L;++j) add(g[i],dp[j][j][i]),s[j]==s[j+1]&&(add(g[i],dp[j][j+1][i]),0);
	int ans=solve(1);
	if((n+L)&1)
	{
		memset(g,0,sizeof(g));
		for(int i=0;i<=L;++i) for(int j=1;j<=L;++j) s[j]==s[j+1]&&(add(g[i],dp[j][j+1][i]),0);
		sub(ans,solve(0));
	}
	printf("%d\n",ans);
	return 0;
}