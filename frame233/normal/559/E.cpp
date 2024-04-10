// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

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

const int N=105;
struct node{
	int a,l;
	Finline bool operator < (const node &o)const
	{
		return a<o.a;
	}
}a[N];
int dp[N][N][2];
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i].a,a[i].l);
	}
	std::sort(a+1,a+n+1);
	a[0].a=-inf;
	memset(dp,-63,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<=i;++j)
		{
			for(int d=0;d<2;++d)
			{
				if(dp[i][j][d]<0) continue;
				int max_pos=a[j].a;
				if(d) max_pos+=a[j].l;
				if(a[i+1].a+a[i+1].l>=max_pos) chmax(dp[i+1][i+1][1],dp[i][j][d]+min(a[i+1].l,a[i+1].a+a[i+1].l-max_pos));
				if(max_pos>=a[i+1].a+a[i+1].l) chmax(dp[i+1][j][d],dp[i][j][d]);
				int maxx=-inf,pos=0;
				for(int k=i+1;k<=n;++k)
				{
					if(a[k].a>=maxx)
					{
						if(a[k].a>=max_pos)
						{
							chmax(dp[k][k][0],dp[i][j][d]+min(a[k].l,a[k].a-max_pos));
						}
						if(max_pos>=a[k].a)
						{
							chmax(dp[k][j][d],dp[i][j][d]);
						}
					}
					if(a[k].a<=maxx)
					{
						if(maxx>=max_pos)
						{
							chmax(dp[k][pos][1],dp[i][j][d]+max(0,min(a[k].l,a[k].a-max_pos))+maxx-max(a[k].a,max_pos));
						}
						if(maxx<=max_pos)
						{
							chmax(dp[k][j][d],dp[i][j][d]);
						}
					}
					if(a[k].a+a[k].l>maxx)
					{
						maxx=a[k].a+a[k].l;
						pos=k;
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<2;++j)
		{
			chmax(ans,dp[n][i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}