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
 
const int N=1000005,mod=1000000007;
std::vector<int> v[N][10];
struct node{
	int x,ans;
};
std::vector<node> _q[N];
int _l,_r;
bool vis[N];
int node_cnt,ans[N];
Finline void add(const int &u,const int &_,int x)
{
	int last=_;
	while(x>=10)
	{
		v[++node_cnt][x%10].emplace_back(last);
		last=node_cnt,x/=10;
	}
	v[u][x].emplace_back(last);
}
int main()
{
	int n,m,_,y;
	read(n,m);
	node_cnt=n;
	for(int i=1;i<=m;++i)
	{
		read(_,y);
		add(_,y,i),add(y,_,i);
	}
	_q[_l=_r=1]={(node){1,0}};
	vis[1]=1;
	std::vector<node> x,tmp;
	while(_l!=_r+1)
	{
		x=_q[_l++];
		for(auto _x:x)
		{
			if(_x.x<=n)
			{
				ans[_x.x]=_x.ans;
			}
		}
		for(int i=0;i<10;++i)
		{
			tmp.clear();
			for(auto _x:x)
			{
				for(auto it:v[_x.x][i])
				{
					if(!vis[it])
					{
						vis[it]=1;
						tmp.emplace_back((node){it,(int)((_x.ans*10ll+i)%mod)});
					}
				}
			}
			if(!tmp.empty()) _q[++_r]=tmp;
		}
	}
	for(int i=2;i<=n;++i)
	{
		printf("%d\n",ans[i]);
	}
    return 0;
}