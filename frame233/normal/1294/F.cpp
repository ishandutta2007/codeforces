// Author -- Frame

#pragma GCC optimize(2)

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

const int N=200005;
std::vector<int> v[N];
int f[N][4],t[4];
std::vector<std::pair<int,int> > opt[N][4],qwq[4];
int dfs(int x,int fa)
{
	f[x][0]=f[x][1]=0;
	opt[x][1].push_back(std::make_pair(x,1));
	int siz=1,tmp;
	for(auto to:v[x])
	{
		if(to!=fa)
		{
			memcpy(t,f[x],sizeof(t));
			for(int i=0;i<4;++i) qwq[i]=opt[x][i];
			tmp=dfs(to,x);
			for(int j=0;j<4&&j<=siz;++j)
			{
				for(int k=0;k<4-j&&k<=tmp;++k)
				{
					if(f[to][k]+f[x][j]>t[k+j])
					{
						chmax(t[k+j],f[to][k]+f[x][j]);
						qwq[k+j]=opt[x][j];
						if(k)
						{
							qwq[k+j].push_back(std::make_pair(to,k));
						}
					}
				}
			}
			siz+=tmp;
			memcpy(f[x],t,sizeof(t));
			for(int i=0;i<4;++i) opt[x][i]=qwq[i];
		}
	}
	++f[x][1];
	++f[x][2];
	return siz;
}
std::vector<int> ans;
void print(int x,int rest)
{
	if(!rest) return;
	for(auto it:opt[x][rest])
	{
		if(it.first==x)
		{
			ans.push_back(x);
		}
		else
		{
			print(it.first,it.second);
		}
	}
}
int Fa[N];
void Dfs(int x,int fa)
{
	Fa[x]=fa;
	for(auto it:v[x])
	{
		if(it!=fa)
		{
			Dfs(it,x);
		}
	}
}
bool mark[N];
int main()
{
	memset(f,-63,sizeof(f));
	int n;
	read(n);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	printf("%d\n",f[1][3]);
	int res=f[1][3];
	print(1,3);
	Dfs(ans[0],0);
	int cur=ans[1];
	while(cur!=ans[0])
	{
		mark[cur]=1;
		cur=Fa[cur];
	}
	cur=ans[2];
	while(cur!=ans[0])
	{
		mark[cur]=1;
		cur=Fa[cur];
	}
	int tmp=0;
	for(int i=1;i<=n;++i)
	{
		if(mark[i]) ++tmp;
	}
	if(tmp!=res) exit(233);
	for(auto it:ans) printf("%d ",it);
	printf("\n");
    return 0;
}