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

const int N=605;
int n,m,k,len[N][N],dis[N],vis[N];

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			len[i][j]=1e18;
	for(int i=1;i<=m;++i)
	{
		int u=read()+1,v=read()+1,w=read();
		len[u][v]=min(len[u][v],w);
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			dis[j]=1e18,vis[j]=0;
		for(int j=1;j<=n;++j)
			dis[j]=min(dis[j],len[i][j]);
		while(1)
		{
			int u=0;
			for(int j=1;j<=n;++j)
				if(!vis[j]&&(u==0||dis[u]>dis[j]))
					u=j;
			if(u==0) break;
			vis[u]=1;
			dis[u%n+1]=min(dis[u%n+1],dis[u]+1);
			for(int i=1;i<=n;++i)
				dis[(i+dis[u]-1)%n+1]=min(dis[(i+dis[u]-1)%n+1],dis[u]+len[u][i]);
		}
		for(int j=1;j<=n;++j)
			if(j==i) printf("0 ");
			else printf("%lld ",dis[j]);
		printf("\n");
	}
	return 0;
}