// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
{
	register char ch(getchar());
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
	register char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=30005;
ll a[N],sum[N];
ll f[N][2];
ll m1[N][2],m2[N][2];
int main()
{
	int n,k;
	read(n,k);
	f[0][0]=f[0][1]=-1e18;
	memset(m1,-63,sizeof(m1));
	memset(m2,-63,sizeof(m2));
	ll maxx=0,minn=0;
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		sum[i]=sum[i-1]+a[i];
		f[i][0]=max(sum[i]-maxx,sum[i]-minn);
		f[i][1]=max(-sum[i]+maxx,-sum[i]+minn);
		chmax(maxx,sum[i]);
		chmin(minn,sum[i]);
	}
	for(int i=1;i<=n;++i)
	{
		m1[i][0]=f[i][0];
		m1[i][1]=f[i][1];
		chmax(m1[i][0],m1[i-1][0]);
		chmax(m1[i][1],m1[i-1][1]);
		m2[i][0]=m1[i][0]+sum[i]*2;
		m2[i][1]=m1[i][1]-sum[i]*2;
		chmax(m2[i][0],m2[i-1][0]);
		chmax(m2[i][1],m2[i-1][1]);
	}
	for(int T=2;T<k;++T)
	{
		for(int i=1;i<=n;++i)
		{
			f[i][0]=max(m1[i-1][0],m2[i-1][1]+sum[i]*2);
			f[i][1]=max(m1[i-1][1],m2[i-1][0]-sum[i]*2);
		}
		for(int i=1;i<=n;++i)
		{
			m1[i][0]=f[i][0];
			m1[i][1]=f[i][1];
			chmax(m1[i][0],m1[i-1][0]);
			chmax(m1[i][1],m1[i-1][1]);
			m2[i][0]=m1[i][0]+sum[i]*2;
			m2[i][1]=m1[i][1]-sum[i]*2;
			chmax(m2[i][0],m2[i-1][0]);
			chmax(m2[i][1],m2[i-1][1]);
		}
	}
	ll ans=0;
	maxx=sum[n];
	minn=sum[n];
	for(int i=n-1;i>=1;--i)
	{
		chmax(ans,m1[i][0]-(maxx-sum[i]));
		chmax(ans,m1[i][0]-(minn-sum[i]));
		chmax(ans,m1[i][1]+(maxx-sum[i]));
		chmax(ans,m1[i][1]+(minn-sum[i]));
		chmin(minn,sum[i]);
		chmax(maxx,sum[i]);
	}
	printf("%lld\n",ans);
	return 0;
}