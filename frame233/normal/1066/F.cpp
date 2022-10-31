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
struct node{
	int x,y,level;
	Finline bool operator < (const node &o)const
	{
		return level==o.level?x==o.x?y>o.y:x<o.x:level<o.level;
	}
}a[N];
std::pair<int,int> A[N],B[N];
ll f[N][2];
Finline int dis(const std::pair<int,int> &a,const std::pair<int,int> &b)
{
	return abs(a.first-b.first)+abs(a.second-b.second);
}
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i].x,a[i].y);
		a[i].level=max(a[i].x,a[i].y);
	}
	std::sort(a+1,a+n+1);
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		int cur=i;
		while(cur<n&&a[cur+1].level==a[i].level) ++cur;
		A[++cnt]=std::make_pair(a[i].x,a[i].y);
		B[cnt]=std::make_pair(a[cur].x,a[cur].y);
		i=cur;
	}
	for(int i=1;i<=cnt;++i)
	{
		f[i][0]=min(f[i-1][0]+dis(A[i-1],B[i]),f[i-1][1]+dis(B[i-1],B[i]))+dis(A[i],B[i]);
		f[i][1]=min(f[i-1][0]+dis(A[i-1],A[i]),f[i-1][1]+dis(B[i-1],A[i]))+dis(A[i],B[i]);
	}
	printf("%lld\n",min(f[cnt][0],f[cnt][1]));
    return 0;
}
//