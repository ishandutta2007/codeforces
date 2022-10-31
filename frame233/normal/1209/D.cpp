// Author -- Frame
 
#pragma GCC optimize(2)
 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
 
#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-8;
 
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
struct edge{
	int v,nxt,id;
}c[N<<1];
int front[N],cnt;
int a[N],b[N];
std::queue<int> q;
bool used[N];
bool vis[N];
int _q[N],_l,_r;
Finline void add(const int &u,const int &v,const int &id)
{
	c[++cnt]=(edge){v,front[u],id},front[u]=cnt;
}
int main()
{
	
	int n,k,x,y;
	read(n,k);
	for(int i=1;i<=k;++i)
	{
		read(x,y);
		add(x,y,i),add(y,x,i);
		a[i]=x,b[i]=y;
		q.push(i);
	}
	int ans=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		while(used[x]&&!q.empty()) x=q.front(),q.pop();
		if(used[x]) continue;
		if(vis[a[x]]&&vis[b[x]]) continue;
		++ans;
		_l=1,_r=0;
		if(!vis[a[x]])
		{
			vis[a[x]]=1;
			_q[++_r]=a[x];
		}
		if(!vis[b[x]])
		{
			vis[b[x]]=1;
			_q[++_r]=b[x];
		}
		while(_l!=_r+1)
		{
			int _=_q[_l++];
			for(int i=front[_];i;i=c[i].nxt)
			{
				if(!used[c[i].id])
				{
					if(!vis[c[i].v])
					{
						used[c[i].id]=1;
						++ans;
						vis[c[i].v]=1;
						_q[++_r]=c[i].v;
					}
				}
			}
		}
	}
	printf("%d\n",k-ans);
    return 0;
}