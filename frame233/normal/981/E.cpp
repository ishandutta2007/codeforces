// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<bitset>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

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

const int N=10005;
typedef std::bitset<N> BIT;
BIT dp,ans;
struct seg_tr{
	struct Node{
		int ls,rs;
		std::vector<int> v;
	}f[N<<1];
	int node_cnt;
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r) return cur;
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return cur;
	}
	void Update(int L,int R,int l,int r,int cur,int val)
	{
		if(L<=l&&r<=R)
		{
			f[cur].v.push_back(val);
			return;
		}
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,l,mid,f[cur].ls,val);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs,val);
	}
	void Query(int l,int r,int cur)
	{
		BIT tmp=dp;
		for(auto it:f[cur].v)
		{
			dp|=dp<<it;
		}
		if(l==r)
		{
			ans|=dp;
			return;
		}
		int mid=(l+r)>>1;
		Query(l,mid,f[cur].ls);
		Query(mid+1,r,f[cur].rs);
		dp=tmp;
	}
}tr;
int main()
{
	int n,m;
	read(n,m);
	tr.build(1,n);
	int x,y,z;
	for(int i=1;i<=m;++i)
	{
		read(x,y,z);
		tr.Update(x,y,1,n,1,z);
	}
	dp.set(0);
	tr.Query(1,n,1);
	std::vector<int> v;
	for(int i=1;i<=n;++i)
	{
		if(ans.test(i))
		{
			v.push_back(i);
		}
	}
	printf("%d\n",(int)v.size());
	for(auto it:v) printf("%d ",it);
	printf("\n");
	return 0;
}