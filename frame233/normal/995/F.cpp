// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd()
{
	static uint seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=3015;
const int mod=1000000007;
ll ksm(ll a,ll b=mod-2)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int dp[N][N],L;
std::vector<int> e[N];
int inv[N];
void dfs(int x)
{
	for(int i=1;i<=L;++i) dp[x][i]=1;
	for(int v:e[x])
	{
		dfs(v);
		for(int j=1;j<=L;++j) dp[x][j]=1ll*dp[x][j]*dp[v][j]%mod;
	}
	for(int j=2;j<=L;++j) add(dp[x][j],dp[x][j-1]);
}
int main()
{
	inv[0]=inv[1]=1;
	for(int i=2;i<N;++i) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	int n,D;
	read(n,D);
	L=n+5;
	int x;
	for(int i=2;i<=n;++i) read(x),e[x].pb(i);
	dfs(1);
	int ans=0;
	for(int i=1;i<=L;++i)
	{
		int mul=1;
		for(int j=1;j<=L;++j)
		{
			if(i!=j)
			{
				mul=1ll*mul*(j-D+mod)%mod*inv[abs(j-i)]%mod;
				if(i>j) mul=(mod-mul);
			}
		}
		add(ans,1ll*mul*dp[1][i]%mod);
	}
	printf("%d\n",ans);
	return 0;
}