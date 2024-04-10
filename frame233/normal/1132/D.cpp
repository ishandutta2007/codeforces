// Author -- Frame

#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t,Args&... args)
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
struct node{
	ll a,b;
	ll rest;
	Finline bool operator < (const node &o)const{return rest>o.rest;}
}a[N];
int n,k;
bool check(ll x)
{
	std::priority_queue<node> q;
	for(int i=1;i<=n;++i)
	{
		q.push((node){a[i].a,a[i].b,a[i].a/a[i].b});
	}
	for(register int i=1;i<=k;++i)
	{
		node tmp=q.top();
		q.pop();
		if(tmp.rest<i-1) return 0;
		if(tmp.rest>=k) return 1;
		tmp.a+=x;
		tmp.rest=tmp.a/tmp.b;
		if(tmp.rest<i) return 0;
		q.push(tmp);
	}
	return q.top().rest>=k;
}
int main()
{
	read(n,k);
	--k;
	ll l=0,r=2e12;
	for(int i=1;i<=n;++i)
	{
		read(a[i].a);
		l-=a[i].a;
	}
	for(int i=1;i<=n;++i)
	{
		read(a[i].b);
		l+=a[i].b*k;
	}
	if(k)
	{
		l/=k;
		chmax(l,0ll);
	}
	else
	{
		l=0;
	}
	ll mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l==2e12?-1:l);
	return 0;
}