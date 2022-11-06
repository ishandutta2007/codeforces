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
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=2005;
int n,a[N][N],vis[N*N];

struct Edge
{
	int u,v;
}e[N*N*2];
int tot;

map<pair<int,int>,int> ok;

void query(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	for(int i=1;i<=n;++i)
		a[x][i]=read();
}

void print()
{
	printf("!\n");
	fflush(stdout);
	for(int i=1;i<=tot;++i)
	{
		if(!ok[mp(e[i].u,e[i].v)])
		{
			printf("%d %d\n",e[i].u,e[i].v);
			fflush(stdout);
			ok[mp(e[i].u,e[i].v)]=1;
			ok[mp(e[i].v,e[i].u)]=1;
		}
	}
}

void dfs(int u);

signed main()
{
	n=read();
	vis[1]=1;
	query(1);
	int sum=0;
	for(int i=1;i<=n;++i)
		if(a[1][i]%2==0) sum++;
	for(int i=1;i<=n;++i)
		if(a[1][i]==1)
			e[++tot]=(Edge){1,i};
	if(sum<=(n+1)/2)
	{
		for(int i=1;i<=n;++i)
			if(a[1][i]==2&&!vis[i]) dfs(i);
	}
	else
	{
		for(int i=1;i<=n;++i)
			if(a[1][i]==1&&!vis[i]) dfs(i);
	}
	print();
	return 0;
}

void dfs(int u)
{
	vis[u]=1;
	query(u);
	for(int i=1;i<=n;++i)
		if(a[u][i]==1)
			e[++tot]=(Edge){u,i};
	for(int i=1;i<=n;++i)
		if(a[u][i]==2&&!vis[i])
			dfs(i);
}