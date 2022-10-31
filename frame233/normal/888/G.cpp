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
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&((a=b),0);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&((a=b),0);}
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
int a[N];
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);};
struct Trie{
	int ch[N<<5][2];
	int bel[N<<5];
	int node_cnt;
	Finline void clear()
	{
		for(int i=0;i<=node_cnt;++i)
		{
			ch[i][0]=ch[i][1]=0;
			bel[i]=0;
		}
		node_cnt=0;
	}
	void insert(int x,int id)
	{
		int cur=0,tmp;
		for(int i=29;i>=0;--i)
		{
			tmp=(x>>i)&1;
			if(!ch[cur][tmp]) ch[cur][tmp]=++node_cnt;
			cur=ch[cur][tmp];
		}
		bel[cur]=id;
	}
	std::pair<int,int> Query(int x)
	{
		int cur=0,tmp;
		int ans=0;
		for(int i=29;i>=0;--i)
		{
			tmp=(x>>i)&1;
			if(ch[cur][tmp])
			{
				cur=ch[cur][tmp];
			}
			else
			{
				ans|=1<<i;
				cur=ch[cur][!tmp];
			}
		}
		return std::make_pair(ans,bel[cur]);
	}
}tr;
std::vector<int> v[N];
std::pair<int,int> minn[N];
bool root[N];
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]),fa[i]=i;
	ll ans=0;
	int cnt=n;
	while(cnt>1)
	{
		tr.clear();
		for(int i=1;i<=n;++i)
		{
			v[i].clear();
			minn[i]=std::make_pair(inf,inf);
		}
		for(int i=1;i<=n;++i)
		{
			v[find(i)].push_back(i);
			root[i]=find(i)==i;
		}
		std::pair<int,int> qwq;
		for(int i=1;i<=n;++i)
		{
			for(auto it:v[i])
			{
				chmin(minn[i],tr.Query(a[it]));
			}
			for(auto it:v[i])
			{
				tr.insert(a[it],i);
			}
		}
		tr.clear();
		for(int i=n;i>=1;--i)
		{
			for(auto it:v[i])
			{
				chmin(minn[i],tr.Query(a[it]));
			}
			for(auto it:v[i])
			{
				tr.insert(a[it],i);
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(root[i]&&find(i)!=find(minn[i].second))
			{
				ans+=minn[i].first;
				--cnt;
				fa[find(i)]=find(minn[i].second);
			}
		}
	}
	printf("%lld\n",ans);
    return 0;
}