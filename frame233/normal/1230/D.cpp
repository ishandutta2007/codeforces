// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>

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

const int N=7005;
struct node{
	ll a,b;
	bool db;
}a[N];
std::map<ll,ll> mp;
std::map<ll,int> cnt;
ll dp[N];
ll x[N],y[N];
int main()
{
	int n;
	read(n);
	int pos=0;
	for(int i=1;i<=n;++i)
	{
		read(x[i]);
	}
	for(int i=1;i<=n;++i)
	{
		read(y[i]);
		mp[x[i]]+=y[i];
		++cnt[x[i]];
	}
	for(std::map<ll,ll>::iterator it=mp.begin();it!=mp.end();++it)
	{
		a[++pos]={it->first,it->second,cnt[it->first]>=2};
	}
	std::reverse(a+1,a+pos+1);
	ll ans=0;
	std::vector<ll> st;
	for(int i=1;i<=pos;++i)
	{
		if(a[i].db)
		{
			ans+=a[i].b;
			st.emplace_back(a[i].a);
		}
		else
		{
			for(auto it:st)
			{
				if((a[i].a&it)==a[i].a)
				{
					ans+=a[i].b;
					st.emplace_back(a[i].a);
					break;
				}
			}
		}
	}
	printf("%lld\n",ans);
    return 0;
}