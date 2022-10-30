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
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=3005;
const int S=13;
const int mod=998244353;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
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
int n,c;
int a[N];
int A[N],B[N];
namespace sub1
{
int dp[N][N/S+5];
int f[N][N],cnt[N],ans[N];
void MAIN()
{
	int maxx=n/c;
	for(int j=1;j<=n;++j)
	{
		memset(cnt,0,sizeof(cnt));
		int qwq=c-1,coef=1;
		if(!qwq) f[j][j]=1;
		for(int i=j-1;i>=1;--i)
		{
			if(a[i]!=a[j])
			{
				if(!cnt[a[i]]) --qwq;
				else coef=1ll*coef*B[cnt[a[i]]]%mod*A[cnt[a[i]]+1]%mod;
				++cnt[a[i]];
			}
			if(!qwq) f[i][j]=coef;
		}
	}
	dp[0][0]=1;
	for(int i=1;i<=n;++i) for(int j=1,LIM=i/c;j<=LIM;++j) for(int k=1;k<=i;++k) add(dp[i][j],1ll*f[k][i]*dp[k-1][j-1]%mod);
	memset(cnt,0,sizeof(cnt));
	int qwq=c,coef=1,qaq=1;
	for(int i=n;i>=0;--i)
	{
		for(int j=0;j<=maxx;++j) add(ans[j],1ll*(qaq-(qwq?0:coef)+mod)*dp[i][j]%mod);
		if(!cnt[a[i]]) --qwq;
		else coef=1ll*coef*B[cnt[a[i]]]%mod*A[cnt[a[i]]+1]%mod;
		++cnt[a[i]];
		add(qaq,qaq);
	}
	sub(ans[0],1);
	for(int j=0;j<=n;++j) printf("%d%c",ans[j]," \n"[j==n]);
}
}
namespace sub2
{
int dp[N][1<<S];
void MAIN()
{
	int maxx=n/c;
	dp[0][0]=1;
	for(int i=0;i<n;++i)
	{
		for(int j=i/c;j>=0;--j)
		{
			for(int st=(1<<c)-2;st>=0;--st)
			{
				int to=st|1<<(a[i+1]-1);
				if(to+1==(1<<c)) add(dp[j+1][0],dp[j][st]);
				else add(dp[j][to],dp[j][st]);
			}
		}
	}
	for(int i=0;i<=n;++i)
	{
		int ans=0;
		if(i<=maxx) for(int st=0;st<1<<c;++st) add(ans,dp[i][st]);
		if(!i) sub(ans,1);
		printf("%d%c",ans," \n"[i==n]);
	}
}
}
int main()
{
	for(int i=1;i<N;++i) A[i]=(A[i-1]+A[i-1]+1)%mod,B[i]=ksm(A[i]);
	read(n,c);
	for(int i=1;i<=n;++i) read(a[i]);
	if(c>S) sub1::MAIN();
	else sub2::MAIN();
	return 0;
}