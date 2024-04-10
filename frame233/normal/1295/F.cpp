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
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
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

const int N=55;
const int mod=998244353;
int a[N],b[N];
int t[N<<1],pos;
int f[N][N<<1],sum[N][N<<1];
int inv[N];
template <typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
ll ksm(ll a,int b=mod-2)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
int main()
{
	int n;
	read(n);
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;++i) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	ll mul=1;
	for(int i=1;i<=n;++i)
	{
		read(a[i],b[i]);
		++b[i];
		t[++pos]=a[i];
		t[++pos]=b[i];
		mul=mul*(b[i]-a[i])%mod;
	}
	std::sort(t+1,t+pos+1);
	int len=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<=n;++i)
	{
		a[i]=std::lower_bound(t+1,t+len+1,a[i])-t;
		b[i]=std::lower_bound(t+1,t+len+1,b[i])-t;
	}
	for(int i=1;i<=len;++i) sum[0][i]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<len;++j)
		{
			if(a[i]<=j&&j<b[i])
			{
				int cnt=1;
				int val=t[j+1]-t[j]-1;
				ll C=val+1;
				for(int p=i-1;p>=0;--p)
				{
					add(f[i][j],C*sum[p][j+1]%mod);
					if(a[p]<=j&&j<b[p])
					{
						++cnt;
						C=C*(val+cnt)%mod*inv[cnt]%mod;
					}
					else break;
				}
			}
		}
		for(int j=len-1;j>=1;--j)
		{
			sum[i][j]=(sum[i][j+1]+f[i][j])%mod;
		}
	}
	fprintf(stderr,"%d\n",sum[n][1]);
	printf("%lld\n",sum[n][1]*ksm(mul)%mod);
	return 0;
}