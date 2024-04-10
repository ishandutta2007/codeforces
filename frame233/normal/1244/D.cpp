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
 
const int N=100005;
int c[3][N];
int dg[N];
struct edge{
	int v,nxt;
}e[N<<1];
int front[N],cnt;
ll dp[N][3][3];
int opt[N][3][3];
Finline void add(const int &u,const int &v)
{
	e[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
bool vis[N];
int a[N];
int col[N];
void print(int n,int i,int j)
{
	if(n)
	{
		print(n-1,j,opt[n][i][j]);
		col[a[n]]=i+1;
	}
}
int main()
{
	int n;
	read(n);
	for(int t=0;t<3;++t)
	{
		for(int i=1;i<=n;++i)
		{
			read(c[t][i]);
		}
	}
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
		++dg[x],++dg[y];
	}
	int cnt=0,last;
	for(int i=1;i<=n;++i)
	{
		if(dg[i]==1)
		{
			++cnt;
			last=i;
		}
		else
		{
			if(dg[i]!=2)
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	if(cnt!=2)
	{
		printf("-1\n");
		return 0;
	}
	memset(dp,63,sizeof(dp));
	int cur=last;
	dp[1][0][0]=c[0][cur];
	dp[1][1][0]=c[1][cur];
	dp[1][2][0]=c[2][cur];
	vis[cur]=true;
	a[1]=cur;
	cur=e[front[cur]].v;
	dp[2][0][1]=dp[1][1][0]+c[0][cur];
	dp[2][0][2]=dp[1][2][0]+c[0][cur];
	dp[2][1][0]=dp[1][0][0]+c[1][cur];
	dp[2][1][2]=dp[1][2][0]+c[1][cur];
	dp[2][2][0]=dp[1][0][0]+c[2][cur];
	dp[2][2][1]=dp[1][1][0]+c[2][cur];
	vis[cur]=true;
	a[2]=cur;
	for(int i=front[cur];i;i=e[i].nxt)
	{
		if(!vis[e[i].v])
		{
			cur=e[i].v;
			break;
		}
	}
	for(int i=3;i<=n;++i)
	{
		a[i]=cur;
		vis[cur]=true;
		for(int j=0;j<3;++j)
		{
			for(int k=0;k<3;++k)
			{
				if(j!=k)
				{
					int t=3-j-k;
					if(dp[i-1][j][k]+c[t][cur]<dp[i][t][j])
					{
						dp[i][t][j]=dp[i-1][j][k]+c[t][cur];
						opt[i][t][j]=k;
					}
				}
			}
		}
		for(int _=front[cur];_;_=e[_].nxt)
		{
			if(!vis[e[_].v])
			{
				cur=e[_].v;
				break;
			}
		}
	}
	ll ans=INF;
	int res1=0,res2=0;
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j)
		{
			if(ans>dp[n][i][j])
			{
				ans=dp[n][i][j];
				res1=i,res2=j;
			}
		}
	}
	printf("%lld\n",ans);
	print(n,res1,res2);
	for(int i=1;i<=n;++i)
	{
		printf("%d ",col[i]);
	}
	printf("\n");
    return 0;
}