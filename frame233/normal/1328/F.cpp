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

const int N=200005;
ll a[N];
std::map<int,int> mp;
int n,k;
ll sum[N];
int last[N],end[N];
ll calc(int x,bool flag1,bool flag2)
{
	ll qwq=k-mp[a[x]];
	if(qwq<=0) return 0;
	if(flag1)
	{
		qwq+=(a[x]-1)*(last[x]-1)-sum[last[x]-1];
	}
	if(flag2)
	{
		qwq+=sum[n]-sum[end[x]]-(a[x]+1)*(n-end[x]);
	}
	int cnt=0;
	if(flag1)
	{
		cnt+=last[x]-1;
	}
	if(flag2)
	{
		cnt+=n-end[x];
	}
	if(cnt<k-mp[a[x]]) return 1e18;
	return qwq;
}
int main()
{
	read(n,k);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		++mp[a[i]];
	}
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;++i)
	{
		if(a[i]==a[i-1]) last[i]=last[i-1];
		else last[i]=i;
	}
	for(int i=n;i>=1;--i)
	{
		if(a[i]==a[i+1]) end[i]=end[i+1];
		else end[i]=i;
	}
	ll ans=1e18;
	for(int i=1;i<=n;++i)
	{
		if(a[i]==a[i-1]&&a[i]==a[i+1]) continue;
		chmin(ans,calc(i,0,0));
		if(a[i]!=a[n]) chmin(ans,calc(i,0,1));
		if(a[i]!=a[1]) chmin(ans,calc(i,1,0));
		if(a[i]!=a[1]&&a[i]!=a[n]) chmin(ans,calc(i,1,1));
	}
	printf("%lld\n",ans);
	return 0;
}