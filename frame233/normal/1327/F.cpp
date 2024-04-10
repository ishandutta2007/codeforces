// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
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

const int N=500005;
const int mod=998244353;
int d[N],pos[N];
int L[N],R[N],V[N];
int dp[N];
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int main()
{
	int n,k,m;
	read(n,k,m);
	for(int i=1;i<=m;++i) read(L[i],R[i],V[i]);
	ll ans=1;
	for(int i=0;i<k;++i)
	{
		for(int j=0;j<=n+1;++j) d[j]=0,pos[j]=0,dp[j]=0;
		for(int j=1;j<=m;++j)
		{
			if((V[j]>>i)&1)
			{
				++d[L[j]];
				--d[R[j]+1];
			}
			else
			{
				chmax(pos[R[j]],L[j]);
			}
		}
		ll sum=1;
		dp[0]=1;
		int cur=-1;
		for(int j=1;j<=n;++j)
		{
			d[j]+=d[j-1];
			chmax(pos[j],pos[j-1]);
			if(!d[j])
			{
				dp[j]=sum;
				add(sum,sum);
			}
			while(cur+1<pos[j])
			{
				++cur;
				sub(sum,dp[cur]);
				dp[cur]=0;
			}
		}
		ans=ans*sum%mod;
	}
	printf("%lld\n",ans);
	return 0;
}