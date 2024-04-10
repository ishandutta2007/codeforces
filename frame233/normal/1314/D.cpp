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

const int N=85;
int val[N][N];
struct node{
	int nd,val;
	Finline bool operator < (const node &o)const
	{
		return val<o.val;
	}
};
std::vector<node> v[N][N];
int n,k;
int ans;
int a[N];
bool used[N];
int calc()
{
	for(int i=0;i<(k>>1);++i) used[a[i]]=1;
	int qwq=0;
	for(int i=0;i<(k>>1);++i)
	{
		int res=inf;
		for(auto it:v[a[i]][a[i+1]])
		{
			if(!used[it.nd])
			{
				res=it.val;
				break;
			}
		}
		qwq+=res;
	}
	for(int i=0;i<(k>>1);++i) used[a[i]]=0;
	return qwq;
}
void dfs(int dep)
{
	if(dep==k>>1)
	{
		chmin(ans,calc());
		return;
	}
	for(int i=1;i<=n;++i)
	{
		a[dep]=i;
		dfs(dep+1);
	}
}
int main()
{
	read(n,k);
	a[k>>1]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			read(val[i][j]);
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			for(int k=1;k<=n;++k)
			{
				if(i!=k&&j!=k)
				{
					v[i][j].push_back({k,val[i][k]+val[k][j]});
				}
			}
			std::sort(v[i][j].begin(),v[i][j].end());
		}
	}
	a[0]=1;
	ans=inf;
	dfs(1);
	printf("%d\n",ans);
	return 0;
}