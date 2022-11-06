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
#define lowbit(x) (x&(-x))
#define mp(x,y) make_pair(x,y)
#define lc (x<<1)
#define rc (x<<1|1)
#define fi first
#define se second
#define mid ((l+r)>>1)
#define fan(x) (((x-1)^1)+1)
#define max Max
#define min Min
#define abs Abs

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
int n,m,q,len[N][N],dis[N][N],in[N][N],ok[N][N],num[N],ans;

signed main()
{
	memset(len,0x3f,sizeof(len));
	memset(in,0x3f,sizeof(in));
	n=read();m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),w=read();
		len[u][v]=len[v][u]=w;
		in[u][v]=in[v][u]=w;
	}
	for(int i=1;i<=n;++i)
		len[i][i]=0;
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				len[i][j]=min(len[i][j],len[i][k]+len[k][j]);
	q=read();
	for(int i=1;i<=q;++i)
	{
		int l=read(),r=read(),x=read();
		dis[l][r]=dis[r][l]=max(dis[l][r],x);
	}
	for(int i=1;i<=n;++i)
	{
		memset(num,0x3f,sizeof(num));
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				num[j]=min(num[j],len[j][k]-dis[i][k]);
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				if(len[i][j]+in[j][k]+num[k]<=0)
					ok[j][k]=ok[k][j]=1;
	}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(ok[i][j]) ans++;
	printf("%lld\n",ans);
	return 0;
}