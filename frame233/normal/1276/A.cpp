// Author -- Frame
 
#pragma GCC optimize(2)
 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<bitset>
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
 
const int N=150005;
int f[N][3][3];
bool opt[N][3][3];
struct Pair{
	int a,b;
}pre[N][3][3];
char s[N];
const char one[]={'o','n','e'};
const char two[]={'t','w','o'};
void print(int cur,int a,int b)
{
	if(cur)
	{
		print(cur-1,pre[cur][a][b].a,pre[cur][a][b].b);
		if(opt[cur][a][b])
		{
			printf("%d ",cur);
		}
	}
}
void MAIN()
{
	int n=read_str(s+1);
	for(int i=0;i<=n+1;++i)
	{
		memset(f[i],63,sizeof(f[i]));
	}
	f[0][0][0]=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<3;++j)
		{
			for(int k=0;k<3;++k)
			{
				if(f[i+1][j][k]>f[i][j][k]+1)
				{
					f[i+1][j][k]=f[i][j][k]+1;
					pre[i+1][j][k]=(Pair){j,k};
					opt[i+1][j][k]=1;
				}
				int p1=j,p2=k;
				if(s[i+1]==one[j])
				{
					++p1;
				}
				else
				{
					if(s[i+1]==one[0]) p1=1;
					else p1=0;
				}
				if(s[i+1]==two[k])
				{
					++p2;
				}
				else
				{
					if(s[i+1]==two[0]) p2=1;
					else p2=0;
				}
				if(p1!=3&&p2!=3)
				{
					if(f[i+1][p1][p2]>f[i][j][k])
					{
						f[i+1][p1][p2]=f[i][j][k];
						pre[i+1][p1][p2]=(Pair){j,k};
						opt[i+1][p1][p2]=0;
					}
				}
			}
		}
	}
	int ans=inf;
	int p1=0,p2=0;
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j)
		{
			if(ans>f[n][i][j])
			{
				ans=f[n][i][j];
				p1=i,p2=j;
			}
		}
	}
	printf("%d\n",ans);
	print(n,p1,p2);
	printf("\n");
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
    return 0;
}