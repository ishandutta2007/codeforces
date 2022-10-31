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
typedef std::pair<int,int> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

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
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=505;
ll dp[N][N];
int main()
{
	int n,k;
	read(n,k);
	memset(dp,-63,sizeof(dp));
	dp[1][0]=0;
	ll sum=0;
	int a,b;
	for(int i=1;i<=n;++i)
	{
		read(a,b);
		for(int j=0;j<k;++j)
		{
			if(dp[i][j]<0) continue;
			int t=(sum-dp[i][j]*k-j);
			chmax(dp[i+1][(j+a)%k],dp[i][j]+(j+a)/k+(t+b)/k);
			for(int p=0;p<=k;++p)
			{
				if(p<=a&&k-p<=b)
				{
					chmax(dp[i+1][(j+(a-p))%k],dp[i][j]+(j+(a-p))/k+(t+(b-(k-p)))/k+1);
				}
			}
		}
		sum+=a+b;
	}
	ll ans=0;
	for(int i=0;i<k;++i) chmax(ans,dp[n+1][i]);
	printf("%lld\n",ans);
	return 0;
}