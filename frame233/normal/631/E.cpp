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
const ll INF=0x7ffffffffffffff;
const double eps=1e-8;

uint seed=19260817;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
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
    while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}

const int N=200005;
ll a[N],sum[N];
int _q[N],_l,_r;
Finline ll X(const int &pos)
{
	return pos;
}
Finline ll Y1(const int &pos)
{
	return sum[pos];
}
Finline ll Y2(const int &pos)
{
	return sum[pos-1];
}
Finline double Slope1(const int &a,const int &b)
{
	return (double)(Y1(b)-Y1(a))/(X(b)-X(a));
}
Finline double Slope2(const int &a,const int &b)
{
	return (double)(Y2(b)-Y2(a))/(X(b)-X(a));
}
int find1(double k)
{
	int l=_l,r=_r;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(Slope1(_q[mid],_q[mid+1])>=k) l=mid+1;
		else r=mid;
	}
	return _q[l];
}
int find2(double k)
{
	int l=_l,r=_r;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(Slope2(_q[mid],_q[mid+1])<=k) l=mid+1;
		else r=mid;
	}
	return _q[l];
}
int main()
{
	int n;
	read(n);
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		sum[i]=sum[i-1]+a[i];
		ans+=a[i]*i;
	}
	ll res=ans;
	_l=1,_r=0;
	for(int i=n;i>=1;--i)
	{
		while(_l<_r&&Slope1(_q[_r-1],_q[_r])<=Slope1(_q[_r],i)) --_r;
		_q[++_r]=i;
		int pos=find1(a[i]);
		chmax(res,ans-a[i]*i+sum[i]+a[i]*pos-sum[pos]);
	}
	_l=1,_r=0;
	for(int i=1;i<=n;++i)
	{
		while(_l<_r&&Slope2(_q[_r-1],_q[_r])>=Slope2(_q[_r],i)) --_r;
		_q[++_r]=i;
		int pos=find2(a[i]);
		chmax(res,ans-a[i]*i+sum[i-1]+a[i]*pos-sum[pos-1]);
	}
	printf("%lld\n",res);
    return 0;
}
/*
4 1 2 3

i -> j
-a[i]*i+sum[i]+a[i]*j-sum[j]


i -> j
-a[i]*i+sum[i-1]+a[i]*j-sum[j-1]
*/