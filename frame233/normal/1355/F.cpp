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

const int MAXN=683;
bool pr[MAXN];
int p[MAXN],pos;
void sieve()
{
	for(int i=2;i<MAXN;++i)
	{
		if(!pr[i])
		{
			p[++pos]=i;
		}
		for(int j=1;j<=pos&&i*p[j]<MAXN;++j)
		{
			pr[i*p[j]]=true;
			if(!(i%p[j]))
			{
				break;
			}
		}
	}
}
int qwq[205];
void divide(ll x)
{
	for(int i=1;i<=pos;++i)
	{
		int cnt=0;
		while(!(x%p[i]))
		{
			x/=p[i];
			++cnt;
		}
		if(cnt)
		{
			qwq[i]=cnt;
		}
	}
}
int tot;
void print(ll mul)
{
	++tot;
	if(tot==23) exit(233);
	printf("? %lld\n",mul);
	fflush(stdout);
	ll x;
	read(x);
	divide(x);
}
void MAIN()
{
	memset(qwq,0,sizeof(qwq));
	tot=0;
	__int128 mul=1;
	int cnt=1;
	for(int i=1;i<=pos;++i)
	{
		if(mul*p[i]>1000000000000000000LL)
		{
			print((ll)mul);
			mul=1;
			++cnt;
		}
		mul*=p[i];
	}
	print(mul);
	std::vector<int> v;
	for(int i=1;i<=pos;++i)
	{
		if(qwq[i])
		{
			v.pb(p[i]);
		}
	}
	for(int i=0;i+1<SZ(v);i+=2)
	{
		ll a=v[i],b=v[i+1];
		ll qwq=1;
		while(qwq*a<=1000000000LL) qwq*=a;
		ll tmp=qwq;
		qwq=1;
		while(qwq*b<=1000000000LL) qwq*=b;
		tmp*=qwq;
		print(tmp);
	}
	if(SZ(v)&1)
	{
		ll qwq=1;
		ll a=v.back();
		while(qwq*a<=1000000000LL) qwq*=a;
		print(qwq);
	}
	ll ans=1;
	for(int i=1;i<=pos;++i)
	{
		ans*=(qwq[i]+1);
	}
	ans*=2;
	chmax(ans,8LL);
	printf("! %lld\n",ans);
	fflush(stdout);
}
int main()
{
	sieve();
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}