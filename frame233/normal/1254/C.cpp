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

const int N=1005;
struct node{
	ll S;
	int id;
	Finline bool operator < (const node &o)const
	{
		return S<o.S;
	}
};
int main()
{
	int n;
	read(n);
	int nd=2;
	ll x;
	for(int i=3;i<=n;++i)
	{
		printf("2 %d %d %d\n",1,nd,i);
		fflush(stdout);
		read(x);
		if(x==-1)
		{
			nd=i;
		}
	}
	std::vector<node> v;
	for(int i=2;i<=n;++i)
	{
		if(nd!=i)
		{
			printf("1 %d %d %d\n",1,nd,i);
			fflush(stdout);
			read(x);
			v.push_back({x,i});
		}
	}
	std::sort(v.begin(),v.end());
	std::vector<int> v1,v2;
	node tmp=v.back();
	v.pop_back();
	for(auto it:v)
	{
		printf("2 %d %d %d\n",1,tmp.id,it.id);
		fflush(stdout);
		read(x);
		if(x==1)
		{
			v1.push_back(it.id);
		}
		else
		{
			v2.push_back(it.id);
		}
	}
	std::reverse(v1.begin(),v1.end());
	std::vector<int> ans;
	ans.push_back(1);
	ans.push_back(nd);
	for(auto it:v2) ans.push_back(it);
	ans.push_back(tmp.id);
	for(auto it:v1) ans.push_back(it);
	printf("0 ");
	for(auto it:ans)
	{
		printf("%d ",it);
	}
	printf("\n");
	fflush(stdout);
	return 0;
}