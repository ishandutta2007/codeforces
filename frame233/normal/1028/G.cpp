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

const int N=10005;
ll dp[6][N];
ll dfs(int x,int L)
{
	if(~dp[x][L]) return dp[x][L];
	ll ans=0;
	for(int i=0;i<=L;++i)
	{
		ll tmp=ans+(i!=L)+dfs(x-1,min(10000LL,ans+L));
		ans=tmp;
	}
	return dp[x][L]=ans;
}
int main()
{
	memset(dp,255,sizeof(dp));
	memset(dp[0],0,sizeof(dp[0]));
	std::iota(dp[1],dp[1]+N,0);
	dfs(5,1);
	ll L=1;
	for(int i=5;i>=1;--i)
	{
		std::vector<ll> v;
		ll cur=L;
		int limit=min(L,10000LL);
		for(int j=0;j<=limit;++j)
		{
			ll tmp=cur+dp[i-1][min(10000LL,cur)];
			cur=tmp;
			if(j<limit) v.pb(cur++);
		}
		printf("%d ",SZ(v));for(auto it:v) printf("%lld ",it);
		printf("\n"),fflush(stdout);
		int x;read(x);
		if(x==-1) return 0;
		if(x) L=v[x-1]+1;
	}
	return 0;
}