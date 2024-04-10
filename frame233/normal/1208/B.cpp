// luogu-judger-enable-o2
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
const double eps=1e-8;

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

const int N=100005;
int a[N];
int t[N];
int cnt[N];
int _cnt[N];
int n,len;
bool check(int x)
{
	memset(cnt,0,sizeof(cnt));
	memset(_cnt,0,sizeof(_cnt));
	for(int i=1;i<=n;++i)
	{
		++cnt[a[i]];
	}
	for(int i=1;i<=len;++i)
	{
		_cnt[cnt[i]]+=cnt[i];
	}
	int l=1,r=x;
	for(int i=l;i<=r;++i)
	{
		--_cnt[cnt[a[i]]];
		--cnt[a[i]];
		++_cnt[cnt[a[i]]];
	}
	while(r<=n)
	{
		if(_cnt[1]==n-x) return 1;
		--_cnt[cnt[a[l]]];
		++cnt[a[l]];
		++_cnt[cnt[a[l]]];
		++l;
		++r;
		--_cnt[cnt[a[r]]];
		--cnt[a[r]];
		++_cnt[cnt[a[r]]];
	}
	return 0;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		t[i]=a[i];
	}
	std::sort(t+1,t+n+1);
	len=std::unique(t+1,t+n+1)-t-1;
	for(int i=1;i<=n;++i)
	{
		a[i]=std::lower_bound(t+1,t+len+1,a[i])-t;
		++cnt[a[i]];
	}
	bool flag=1;
	for(int i=1;i<=len;++i)
	{
		if(cnt[i])
		{
			flag&=cnt[i]<2;
			++_cnt[cnt[i]];
		}
	}
	if(flag)
	{
		printf("0\n");
		return 0;
	}
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
    return 0;
}