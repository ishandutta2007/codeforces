// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define pb push_back

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
const ll inv2=(mod+1)>>1;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll d[37];
void insert(ll x)
{
	for(int i=35;i>=0;--i)
	{
		if((x>>i)&1)
		{
			if(d[i]) x^=d[i];
			else
			{
				d[i]=x;
				break;
			}
		}
	}
}
void FWT_xor(int *a,int limit)
{
	for(int len=2;len<=limit;len<<=1)
	{
		for(int pos=0;pos<limit;pos+=len)
		{
			for(int i=pos;i<pos+(len>>1);++i)
			{
				int tmp=a[i];
				add(a[i],a[i+(len>>1)]);
				a[i+(len>>1)]=(tmp-a[i+(len>>1)]+mod)%mod;	
			}
		}
	}
}
void IFWT_xor(int *a,int limit)
{
	for(int len=2;len<=limit;len<<=1)
	{
		for(int pos=0;pos<limit;pos+=len)
		{
			for(int i=pos;i<pos+(len>>1);++i)
			{
				int tmp=a[i];
				a[i]=inv2*(a[i]+a[i+(len>>1)])%mod;
				a[i+(len>>1)]=inv2*(tmp-a[i+(len>>1)]+mod)%mod;
			}
		}
	}
}
int a[N],b[19][N],c[N];
int ans[37];
int main()
{
	int n,m;
	read(n,m);
	ll x;
	for(int i=1;i<=n;++i)
	{
		read(x);
		insert(x);
	}
	int cnt=0;
	std::vector<ll> v1,v2;
	int hf=(m+1)>>1;
	for(int i=0;i<m;++i)
	{
		if(d[i])
		{
			++cnt;
			if(i<hf) v1.pb(d[i]);
			else v2.pb(d[i]);
		}
	}
	for(int i=0;i<1<<SZ(v1);++i)
	{
		ll s=0;
		for(int j=0;j<SZ(v1);++j)
		{
			if((i>>j)&1)
			{
				s^=v1[j];
			}
		}
		++a[s];
	}
	for(int i=0;i<1<<SZ(v2);++i)
	{
		ll s=0;
		for(int j=0;j<SZ(v2);++j)
		{
			if((i>>j)&1)
			{
				s^=v2[j];
			}
		}
		++b[__builtin_popcount(s>>hf)][s&((1<<hf)-1)];
	}
	int limit=1<<hf;
	FWT_xor(a,limit);
	for(int i=0;i<=m-hf;++i)
	{
		FWT_xor(b[i],limit);
		for(int j=0;j<limit;++j)
		{
			c[j]=1ll*a[j]*b[i][j]%mod;
		}
		IFWT_xor(c,limit);
		for(int j=0;j<limit;++j)
		{
			if(c[j])
			{
				add(ans[__builtin_popcount(j)+i],c[j]);
			}
		}
	}
	ll qwq=1;
	cnt=n-cnt;
	while(cnt--) add(qwq,qwq);
	for(int i=0;i<=m;++i) printf("%lld ",qwq*ans[i]%mod);
	printf("\n");
	return 0;
}