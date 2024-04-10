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

const int N=200005;
struct node{
	int r,id;
	Finline bool operator < (const node &o)const
	{
		return r==o.r?id<o.id:r>o.r;
	}
};
std::set<node> S;
struct Node{
	int x,id,opt;
};
struct BIT{
	int c[N];
	Finline void add(int x,const int &C){for(;x<=200000;x+=lowbit(x))c[x]+=C;}
	Finline int sum(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
}tr;
Finline void Upd(const int &l,const int &r,const int &C)
{
	tr.add(l,C);
	tr.add(r+1,-C);
}
std::vector<Node> v[N];
int main()
{
	int n,k;
	read(n,k);
	int x,y;
	for(int i=1;i<=n;++i)
	{
		read(x,y);
		v[x].push_back((Node){y,i,1});
		v[y+1].push_back((Node){y,i,-1});
		Upd(x,y,1);
	}
	std::set<node>::iterator _it;
	std::vector<int> ans;
	for(int i=1;i<=200000;++i)
	{
		for(auto it:v[i])
		{
			if(it.opt>0)
			{
				S.insert((node){it.x,it.id});
			}
			else
			{
				if((_it=S.find((node){it.x,it.id}))!=S.end())
				{
					S.erase(_it);
				}
			}
		}
		x=tr.sum(i);
		while(x>k)
		{
			_it=S.begin();
			Upd(i,_it->r,-1);
			ans.push_back(_it->id);
			x=tr.sum(i);
			S.erase(_it);
		}
	}
	printf("%d\n",(int)ans.size());
	std::sort(ans.begin(),ans.end());
	for(auto it:ans)
	{
		printf("%d ",it);
	}
	printf("\n");
    return 0;
}