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

const int N=100005;
int mu[N];
bool pr[N];
int p[N],_pos;
std::vector<int> v[N];
void init(int n)
{
	mu[1]=pr[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!pr[i])
		{
			p[++_pos]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=_pos&&p[j]*i<=n;++j)
		{
			pr[p[j]*i]=1;
			if(!(i%p[j]))
			{
				mu[p[j]*i]=0;
				break;
			}
			mu[p[j]*i]=-mu[i];
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;j+=i)
		{
			v[j].emplace_back(i);
		}
	}
}
bool a[N];
int cnt[N];
int t[N],pos;
int count(int x)
{
	int ans=0;
	for(auto it:v[x])
	{
		ans+=mu[it]*cnt[it];
	}
	return ans;
}
int main()
{
	init(100000);
	int n;
	read(n);
	ll ans=0;
	ll x;
	for(int i=1;i<=n;++i)
	{
		read(x);
		chmax(ans,x);
		a[x]=true;
	}
	for(int g=1;g<=100000;++g)
	{
		pos=0;
		for(int i=100000/g;i>=1;--i)
		{
			if(!a[i*g]) continue;
			while(count(i))
			{
				chmax(ans,1ll*i*g*t[pos]);
				for(auto it:v[t[pos]])
				{
					--cnt[it];
				}
				--pos;
			}
			t[++pos]=i;
			for(auto it:v[i])
			{
				++cnt[it];
			}
		}
		while(pos)
		{
			for(auto it:v[t[pos]])
			{
				--cnt[it];
			}
			--pos;
		}
	}
	printf("%lld\n",ans);
    return 0;
}