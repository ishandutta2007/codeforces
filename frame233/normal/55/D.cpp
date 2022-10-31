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
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
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
Finline int lcm(const int &a,const int &b)
{
	if(!a||!b) return a|b;
	return a/gcd(a,b)*b;
}
const int N=21;
const int mod=2520;
int a[N],len;
ll f[N][2525][256];
int l[256];
ll dfs(int pos,int rest,int st,bool limit)
{
	if(!pos) return !l[st]||!(rest%l[st]);
	if(!limit&&~f[pos][rest][st]) return f[pos][rest][st];
	ll x=0;
	int maxx=limit?a[pos]:9;
	for(int i=0;i<=maxx;++i)
	{
		x+=dfs(pos-1,(rest*10+i)%mod,i<=1?st:(st|(1<<(i-2))),limit&&i==maxx);
	}
	if(!limit) f[pos][rest][st]=x;
	return x;
}
ll solve(ll x)
{
	len=0;
	while(x)
	{
		a[++len]=x%10;
		x/=10;
	}
	return dfs(len,0,0,1);
}
void MAIN()
{
	ll l,r;
	read(l,r);
	printf("%lld\n",solve(r)-solve(l-1));
}
int main()
{
	memset(f,255,sizeof(f));
	for(int st=0;st<256;++st)
	{
		int tmp=0;
		for(int i=2;i<=9;++i)
		{
			if((st>>(i-2))&1)
			{
				tmp=lcm(tmp,i);
			}
		}
		l[st]=tmp;
	}
	int _;
	read(_);
	while(_--) MAIN();
    return 0;
}