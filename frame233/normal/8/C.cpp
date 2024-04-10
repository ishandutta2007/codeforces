// Author -- Frame

#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

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

const int N=25;
int x[N],y[N];
int dp[1<<24];
std::pair<int,int> opt[1<<24];
int cost[N][N];
int t[N];
void print(int st)
{
	if(!st) return;
	if(opt[st].first==opt[st].second)
	{
		print(st^(1<<opt[st].first));
		printf("%d %d ",opt[st].first+1,0);
	}
	else
	{
		print(st^(1<<opt[st].first)^(1<<opt[st].second));
		printf("%d %d %d ",opt[st].first+1,opt[st].second+1,0);
	}
}
int main()
{
	int n;
	int a,b;
	read(a,b);
	read(n);
	for(int i=0;i<n;++i)
	{
		read(x[i],y[i]);
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(i!=j)
			{
				cost[i][j]=(a-x[i])*(a-x[i])+(b-y[i])*(b-y[i])+(a-x[j])*(a-x[j])+(b-y[j])*(b-y[j])+(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			}
			else
			{
				cost[i][i]=((a-x[i])*(a-x[i])+(b-y[i])*(b-y[i]))*2;
			}
		}
	}
	memset(dp,63,sizeof(dp));
	dp[0]=0;
	for(register int st=1;st<1<<n;++st)
	{
		int pos=0;
		for(int i=0;i<n;++i)
		{
			if((st>>i)&1)
			{
				t[++pos]=i;
			}
		}
		for(register int i=1;i<=pos;++i)
		{
			if(dp[st^(1<<t[i])]+cost[t[i]][t[i]]<dp[st])
			{
				dp[st]=dp[st^(1<<t[i])]+cost[t[i]][t[i]];
				opt[st]=std::make_pair(t[i],t[i]);
			}
			for(register int j=i+1;j<=pos;++j)
			{
				if(dp[st^(1<<t[i])^(1<<t[j])]+cost[t[i]][t[j]]<dp[st])
				{
					dp[st]=dp[st^(1<<t[i])^(1<<t[j])]+cost[t[i]][t[j]];
					opt[st]=std::make_pair(t[i],t[j]);
				}
			}
		}
	}
	printf("%d\n",dp[(1<<n)-1]);
	printf("0 ");
	print((1<<n)-1);
	printf("\n");
    return 0;
}