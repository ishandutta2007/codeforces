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

const int N=3e5+5,mod=998244353;
int n,m,sum[N],vis[N],l1[N],l2[N],num,ans;
char s[N];

//int a[N][N],l[N][N],r[N][N],u[N][N],d[N][N];

vector<int> a[N],id1[N],id2[N];

inline int q_pow(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1) c=a*c%mod;
		a=a*a%mod;b>>=1;
	}
	return c;
}

signed main()
{
	n=read();m=read();
	
	for(int i=0;i<=n+1;++i)
		for(int j=0;j<=m+1;++j)
		{
			a[i].push_back(0);
			id1[i].push_back(0);
			id2[i].push_back(0);
		}
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;++j)
			if(s[j]=='*') a[i][j]=0;
			else a[i][j]=1,num++;
	}
	for(int i=2;i<=n*m;++i)
		sum[i]=(sum[i-1]+2*sum[i-2]+q_pow(2,i-2))%mod;
	int now=0;
	for(int i=1;i<=n;++i)
	{
		int ls=-1;
		for(int j=1;j<=m;++j)
			if(a[i][j])
			{
				if(ls==-1)
					ls=j,++now;
				id1[i][j]=now;
				l1[now]++;
			}
			else ls=-1;
	}
	now=0;
	for(int j=1;j<=m;++j)
	{
		int ls=-1;
		for(int i=1;i<=n;++i)
			if(a[i][j])
			{
				if(ls==-1)
					ls=i,++now;
				id2[i][j]=now;
				l2[now]++;
			}
			else ls=-1;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[i][j]&&!vis[id1[i][j]])
			{
				ans=(ans+q_pow(2,num-l1[id1[i][j]])*sum[l1[id1[i][j]]]%mod)%mod;
				vis[id1[i][j]]=1;
			}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[i][j]&&!vis[id2[i][j]])
			{
				ans=(ans+q_pow(2,num-l2[id2[i][j]])*sum[l2[id2[i][j]]]%mod)%mod;
				vis[id2[i][j]]=1;
			}
	printf("%lld\n",ans);
	return 0;
}