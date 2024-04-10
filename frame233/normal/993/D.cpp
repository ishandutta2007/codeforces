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

const int N=55;
ll dp[N][N][5005];
struct node{
	int a,b;
	Finline bool operator < (const node &o)const
	{
		return a==o.a?b>o.b:a>o.a;
	}
}a[N];
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i].a);
	}
	for(int i=1;i<=n;++i)
	{
		read(a[i].b);
	}
	std::sort(a+1,a+n+1);
	memset(dp,63,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=0;i<n;++i)
	{
		int j=i+1;
		while(j<n&&a[j+1].a==a[i+1].a) ++j;
		ll sum=0;
		int tot=0;
		for(int k=0;k<=j-i;++k)
		{
			if(k) sum+=a[i+k].a,tot+=a[i+k].b;
			for(int t=0;t<=i;++t)
			{
				for(int p=0;p<=100*i;++p)
				{
					if(t>=j-i-k)
					{
						chmin(dp[j][t-(j-i-k)+k][p+tot],dp[i][t][p]+sum);
					}
				}
			}
		}
		i=j-1;
	}
	ll ans=1e18;
	for(int j=0;j<=n;++j)
	{
		for(int i=1;i<=n*100;++i)
		{
			if(dp[n][j][i]<1e15)
			{
				ll tmp=1000ll*dp[n][j][i];
				chmin(ans,tmp/i+(!!(tmp%i)));
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}