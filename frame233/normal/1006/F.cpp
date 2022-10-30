// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

uint seed=19260817;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool ismax(_Tp &a,const _Tp &b){return a>b?1:a=b,0;}
template <typename _Tp>Finline bool ismin(_Tp &a,const _Tp &b){return a<b?1:a=b,0;}
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
	while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=23;
int step,hf;
int n,m;
ll a[N][N],k;
std::vector<ll> v[N];
ll ans;
void dfs1(int x,int y,ll Xor)
{
	if(x+y==hf+2)
	{
		v[x].push_back(Xor);
		return;
	}
	if(x<n)
	{
		dfs1(x+1,y,Xor^a[x+1][y]);
	}
	if(y<m)
	{
		dfs1(x,y+1,Xor^a[x][y+1]);
	}
}
void dfs2(int x,int y,ll Xor)
{
	if(x+y-2==hf)
	{
		Xor^=a[x][y];
		ans+=std::upper_bound(v[x].begin(),v[x].end(),Xor^k)-std::lower_bound(v[x].begin(),v[x].end(),Xor^k);
		return;
	}
	if(x>1)
	{
		dfs2(x-1,y,Xor^a[x-1][y]);
	}
	if(y>1)
	{
		dfs2(x,y-1,Xor^a[x][y-1]);
	}
}
int main()
{
	read(n,m,k);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			read(a[i][j]);
		}
	}
	step=(n+m-2);
	hf=step>>1;
	dfs1(1,1,a[1][1]);
	for(int i=1;i<=n;++i)
	{
		std::sort(v[i].begin(),v[i].end());
	}
	dfs2(n,m,a[n][m]);
	printf("%lld\n",ans);
	return 0;
}