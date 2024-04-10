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

const int N=105;
int dp[2][N][N*N];
int main()
{
	int n;read(n);
	int a,b;
	memset(dp,-63,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=1;i<=n;++i)
	{
		memset(dp[i&1],-63,sizeof(dp[i&1]));
		read(a,b);
		for(int j=0;j<i;++j)for(int k=0;k<=100*(i-1);++k)
		{
			chmax(dp[i&1][j+1][k+a],dp[!(i&1)][j][k]+b*2);
			chmax(dp[i&1][j][k],dp[!(i&1)][j][k]+b);
		}
	}
	for(int i=1;i<=n;++i)
	{
		int ans=0;
		for(int j=0;j<=10000;++j) chmax(ans,min(j*2,dp[n&1][i][j]));
		if(ans&1) printf("%d.5 ",ans/2);
		else printf("%d ",ans/2);
	}
	return 0;
}