// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>

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

const int N=500005;
struct node{
	int l,r,id;
	Finline bool operator < (const node &o)const
	{
		return l<o.l;
	}
}a[N];
struct node1{
	int l,r,id;
	Finline bool operator < (const node1 &o)const
	{
		return r<o.r;
	}
	Finline bool operator < (const int &o)const
	{
		return r<o;
	}
};
std::set<node1> S;
int id[N<<1];
int type[N<<1];
std::vector<int> v[N];
int cnt;
bool vis[N];
void dfs(int x,int fa)
{
	if(vis[x])
	{
		printf("NO\n");
		exit(0);
	}
	vis[x]=true;
	++cnt;
	for(auto it:v[x])
	{
		if(it!=fa)
		{
			dfs(it,x);
		}
	}
}
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i].l,a[i].r);
		id[a[i].l]=i;
		id[a[i].r]=i;
		type[a[i].l]=0;
		type[a[i].r]=1;
	}
	int sum=0;
	for(int i=1;i<=n<<1;++i)
	{
		if(!type[i])
		{
			S.insert((node1){a[id[i]].l,a[id[i]].r,id[i]});
			std::set<node1>::iterator it=S.lower_bound((node1){0,a[id[i]].r,0});
			for(std::set<node1>::iterator itt=S.begin();itt!=it;++itt)
			{
				++sum;
				if(sum==n)
				{
					printf("NO\n");
					return 0;
				}
				v[id[i]].push_back(itt->id);
				v[itt->id].push_back(id[i]);
			}
		}
		else
		{
			S.erase(S.find((node1){a[id[i]].l,a[id[i]].r,id[i]}));
		}
	}
	dfs(1,0);
	if(cnt==n) printf("YES\n");
	else printf("NO\n");
    return 0;
}