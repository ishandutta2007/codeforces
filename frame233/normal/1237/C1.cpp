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
	int x,y,z,id;
	Finline bool operator < (const node &o)const
	{
		return x==o.x?y==o.y?z<o.z:y<o.y:x<o.x;
	}
}a[N];
bool used[N];
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i].x,a[i].y,a[i].z);
		a[i].id=i;
	}
	std::sort(a+1,a+n+1);
	std::vector<int> _rest;
	for(int i=1;i<=n;++i)
	{
		int j=i;
		while(j<n&&a[j+1].x==a[i].x) ++j;
		std::vector<int> rest;
		for(int k=i;k<=j;++k)
		{
			std::vector<int> v;
			int t=k;
			v.push_back(k);
			while(t<j&&a[t+1].y==a[k].y)
			{
				++t;
				v.push_back(t);
			}
			k=t;
			for(int _=0;_+1<(int)v.size();_+=2)
			{
				printf("%d %d\n",a[v[_]].id,a[v[_+1]].id);
			}
			if(v.size()&1)
			{
				rest.push_back(v.back());
			}
		}
		i=j;
		for(int _=0;_+1<(int)rest.size();_+=2)
		{
			printf("%d %d\n",a[rest[_]].id,a[rest[_+1]].id);
		}
		if(rest.size()&1)
		{
			_rest.push_back(rest.back());
		}
	}
	for(int i=0;i+1<(int)_rest.size();i+=2)
	{
		printf("%d %d\n",a[_rest[i]].id,a[_rest[i+1]].id);
	}
    return 0;
}