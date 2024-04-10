// luogu-judger-enable-o2
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
int cost[21][21],ct[21][21];
int a[21][10005];
int f[17][1<<16];
int state[17][1<<16];
int pos[17];
int main()
{
	int n,m;
	read(n,m);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			read(a[i][j]);
		}
	}
	if(n==1)
	{
		int ans=inf;
		for(int i=1;i<m;++i)
		{
			chmin(ans,abs(a[1][i]-a[1][i+1]));
		}
		printf("%d\n",ans);
		return 0;
	}
	for(int i=0;i<(1<<n);++i)
	{
		int tmp=__builtin_popcount(i);
		state[tmp][++pos[tmp]]=i;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			cost[i][j]=inf;
			for(int k=1;k<=m;++k)
			{
				chmin(cost[i][j],abs(a[i][k]-a[j][k]));
			}
			cost[j][i]=cost[i][j];
			
			ct[i][j]=inf;
			for(int k=1;k<m;++k)
			{
				chmin(ct[i][j],abs(a[i][k]-a[j][k+1]));
			}
		}
		for(int j=1;j<i;++j)
		{
			ct[i][j]=inf;
			for(int k=1;k<m;++k)
			{
				chmin(ct[i][j],abs(a[i][k]-a[j][k+1]));
			}
		}
	}
	int ans=0;
	for(int r=1;r<=n;++r)
	{
		memset(f,-63,sizeof(f));
		f[r][1<<(r-1)]=inf;
		for(int i=2;i<n;++i)
		{
			for(int id=1;id<=pos[i];++id)
			{
				int st=state[i][id];
				for(int j=1;j<=n;++j)
				{
					if((st>>(j-1))&1)
					{
						for(int k=1;k<=n;++k)
						{
							if(k!=j&&((st>>(k-1))&1))
							{
								chmax(f[j][st],min(f[k][st^(1<<(j-1))],cost[k][j]));
							}
						}
					}
				}
			}
		}
		int st=(1<<n)-1;
		for(int j=1;j<=n;++j)
		{
			for(int k=1;k<=n;++k)
			{
				if(k!=j)
				{
					chmax(f[j][st],min(f[k][st^(1<<(j-1))],min(cost[k][j],ct[j][r])));
				}
			}
		}
		for(int i=1;i<=n;++i)
		{
			chmax(ans,f[i][(1<<n)-1]);
		}
	}
	printf("%d\n",ans);
    return 0;
}