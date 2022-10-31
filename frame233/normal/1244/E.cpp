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
 
const int N=100005;
struct node{
	int val,cnt;
	Finline bool operator < (const node &o)const
	{
		return val<o.val;
	}
}a[N];
int t[N];
int main()
{
	int n;
	ll k;
	read(n,k);
	for(int i=1;i<=n;++i)
	{
		read(t[i]);
	}
	std::sort(t+1,t+n+1);
	int pos=0;
	for(int i=1;i<=n;)
	{
		int k=1;
		while(i+k<=n&&t[i+k]==t[i]) ++k;
		a[++pos]=(node){t[i],k};
		i+=k;
	}
	int l=1,r=pos;
	while(l<r)
	{
		if(a[l].cnt<=a[r].cnt)
		{
			if(k>=1ll*(a[l+1].val-a[l].val)*a[l].cnt)
			{
				k-=1ll*(a[l+1].val-a[l].val)*a[l].cnt;
				a[l+1].cnt+=a[l].cnt;
				++l;
			}
			else
			{
				a[l].val+=k/a[l].cnt;
				printf("%d\n",a[r].val-a[l].val);
				return 0;
			}
		}
		else
		{
			if(k>=1ll*(a[r].val-a[r-1].val)*a[r].cnt)
			{
				k-=1ll*(a[r].val-a[r-1].val)*a[r].cnt;
				a[r-1].cnt+=a[r].cnt;
				--r;
			}
			else
			{
				a[r].val-=k/a[r].cnt;
				printf("%d\n",a[r].val-a[l].val);
				return 0;
			}
		}
	}
	fprintf(stderr,"Passed %lld\n",k);
	printf("%d\n",a[r].val-a[l].val);
    return 0;
}