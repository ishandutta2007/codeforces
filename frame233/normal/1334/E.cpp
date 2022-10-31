// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>

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

const int N=100005;
const int mod=998244353;
ll ksm(ll a,ll b=mod-2)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
ll D;
struct node{
	ll val;
	int cnt;
};
std::vector<node> v;
ll fac[N];
ll inv[N];
std::map<ll,ll> mp;
void dfs(int dep,int sum,ll qwq,ll val)
{
	if(dep==(int)v.size())
	{
		mp[val]=qwq*fac[sum]%mod;
		return;
	}
	for(int i=0;i<=v[dep].cnt;++i)
	{
		dfs(dep+1,sum+i,qwq*inv[i]%mod,val);
		val*=v[dep].val;
	}
}
void init()
{
	fac[0]=1;
	inv[0]=1;
	for(int i=1;i<=60;++i)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=ksm(fac[i]);
	}
	ll D=::D;
	for(int i=2;1ll*i*i<=D;++i)
	{
		if(!(D%i))
		{
			int cnt=1;
			D/=i;
			while(!(D%i))
			{
				D/=i;
				++cnt;
			}
			v.push_back((node){(ll)i,cnt});
		}
	}
	if(D>1) v.push_back((node){D,1});
	dfs(0,0,1,1);
}
int main()
{
	read(D);
	init();
	int _;
	read(_);
	while(_--)
	{
		ll x,y;
		read(x,y);
		ll g=gcd(x,y);
		printf("%lld\n",mp[x/g]*mp[y/g]%mod);
	}
	return 0;
}