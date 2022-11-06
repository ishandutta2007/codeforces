#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=105;
int t,n,m,k,a[N][N],vis[N],tg[N][N];

struct Node
{
	int x,y,v;
	bool operator < (const Node &x)const
	{
		if(v==x.v) return y<x.y;
		return v<x.v;
	}
}b[N*N];

signed main()
{
	//freopen("yangli.in","r",stdin);
	//freopen("std.out","w",stdout);
	t=read();
	//printf("%lld\n",t);
	while(t--)
	{
		n=read();m=read();k=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				a[i][j]=read();
		for(int i=1;i<=n;++i)
			sort(a[i]+1,a[i]+1+m);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				b[++k]=(Node){i,j,a[i][j]};
		sort(b+1,b+1+k);
		for(int i=1;i<=m;++i)
			tg[b[i].x][b[i].y]=1;
		for(int i=1,j=0;i<=n;++i)
		{
			int sum=0,ed=0;
			for(int p=1;tg[i][p];++p) ed=p,sum++;
			for(int p=ed;p>=1;--p)
				swap(a[i][p],a[i][p+j]);
			j+=sum;
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
				printf("%lld ",a[i][j]),tg[i][j]=0;
			printf("\n");
		}
	}
	return 0;
}