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
 
const int N=100005;
int d[N],a[N];
struct node{
	int id,day;
	Finline bool operator < (const node &o)const{return day<o.day;}
}t[N];
int n,m;
bool used[N];
bool check(int x)
{
	memset(used,0,sizeof(used));
	memset(t,0,sizeof(t));
	for(int i=1;i<=x;++i)
	{
		if(d[i])
		{
			t[d[i]].day=i;
			t[d[i]].id=d[i];
		}
	}
	std::sort(t+1,t+m+1);
	for(int i=1;i<=m;++i)
	{
		if(!t[i].day)
		{
			return 0;
		}
		used[t[i].day]=1;
	}
	int pos=0;
	for(int i=1;i<=m;++i)
	{
		int tmp=0;
		while(tmp<a[t[i].id]&&pos<=n)
		{
			++pos;
			tmp+=!used[pos];
		}
		if(pos>t[i].day) return 0;
	}
	return pos<=n;
}
int main()
{
	read(n,m);
	for(int i=1;i<=n;++i)
	{
		read(d[i]);
	}
	for(int i=1;i<=m;++i)
	{
		read(a[i]);
	}
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	if(!check(l)) printf("-1\n");
	else printf("%d\n",l);
    return 0;
}