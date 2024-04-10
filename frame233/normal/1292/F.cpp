// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
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
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd(){static uint seed=416;return seed+=0x71dad4bfu,seed^=seed>>5,seed+=0xc6f74d88u,seed^=seed<<17,seed+=0x25e6561u,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=65;
const int mod=1000000007;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int n,a[N],fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int dp[1<<15][N],sum[1<<15];
pi solve(int ___)
{
	std::vector<int> nd;
	for(int i=1;i<=n;++i) if(find(i)==___) nd.pb(a[i]);
	std::vector<int> A,B;
	for(auto a:nd)
	{
		int cnt=0;
		for(auto b:nd) if(a!=b&&!(a%b)) ++cnt;
		if(!cnt) A.pb(a);
		else B.pb(a);
	}
	if(SZ(B)<=1) return mkpr(0,1);
	memset(dp,0,sizeof(dp));
	memset(sum,0,sizeof(sum));
	for(auto &&it:B)
	{
		int qwq=0;
		for(int i=0;i<SZ(A);++i) if(!(it%A[i])) qwq|=1<<i;
		it=qwq,++sum[it];
		++dp[it][1];
	}
	for(int i=0;i<SZ(A);++i) for(int st=0;st<1<<SZ(A);++st) if((st>>i)&1) sum[st]+=sum[st^(1<<i)];
	for(int st=0;st<1<<SZ(A);++st)
	{
		for(int j=1;j<=SZ(B);++j)
		{
			if(!dp[st][j]) continue;
			add(dp[st][j+1],1ll*dp[st][j]*(sum[st]-j)%mod);
			for(auto it:B) if((it&st)&&(st&it)!=it)	add(dp[st|it][j+1],dp[st][j]);
		}
	}
	return mkpr(SZ(B)-1,dp[(1<<SZ(A))-1][SZ(B)]);
}
int C[N][N];
int main()
{
	for(int i=0;i<N;++i) for(int j=C[i][0]=1;j<=i;++j) C[i][j]=C[i-1][j-1],add(C[i][j],C[i-1][j]);
	read(n);
	for(int i=1;i<=n;++i) read(a[i]),fa[i]=i;
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)	if(!(a[i]%a[j])) fa[find(i)]=find(j);
	ll ans=1,res=0;
	for(int i=1;i<=n;++i)
	{
		if(fa[i]==i)
		{
			pi tmp=solve(i);
			res+=tmp.first;
			ans=ans*C[res][tmp.first]%mod*tmp.second%mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}