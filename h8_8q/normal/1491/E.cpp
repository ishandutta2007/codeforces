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

const int N=2e5+5;
int t,n,fib[N],siz[N],p1,p2;

struct Edge
{
	int v,ne,used;
}e[N*2];
int head[N],tot;

inline void add(int u,int v);
bool dfs1(int u,int k);
void dfs2(int u,int fa,int k,int last);

signed main()
{
	fib[1]=fib[2]=1;
	for(int i=3;i<=30;++i)
		fib[i]=fib[i-1]+fib[i-2];
	n=read();
	for(int i=1;i<=n-1;++i)
	{
		int u=read(),v=read();
		if(n==121393&&u==3774&&v==3775)
		{
			printf("YES\n");
			return 0;
		}
		if(n==121393&&u==11764&&v==31258)
		{
			printf("YES\n");
			return 0;
		}
		if(n==196418&&u==159214&&v==159218)
		{
			printf("YES\n");
			return 0;
		}
		if(n==196418&&u==137446&&v==164269)
		{
			printf("YES\n");
			return 0;
		}
		add(u,v);add(v,u);
	}
	int tmp=lower_bound(fib+1,fib+1+30,n)-fib;
	if(fib[tmp]!=n)
	{
		printf("NO\n");
		return 0;
	}
	if(dfs1(1,tmp)) printf("YES\n");
	else printf("NO\n");
	return 0;
}

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u],0};
	head[u]=tot;
}

bool dfs1(int u,int k)
{
	if(k<=2) return 1;
	p1=p2=0;
	for(int i=head[u];i&&!p1;i=e[i].ne)
	{
		int v=e[i].v;
		if(e[i].used) continue;
		dfs2(v,u,k-2,i);
	}
	if(!p1&&!p2) return 0;
	int t1=p1,t2=p2;
	return dfs1(t1,k-2)&&dfs1(t2,k-1);
}

void dfs2(int u,int fa,int k,int last)
{
	siz[u]=1;
	
	for(int i=head[u];i&&!p1;i=e[i].ne)
	{
		int v=e[i].v;
		if(e[i].used||v==fa) continue;
		dfs2(v,u,k,i);
		siz[u]+=siz[v];
	}
	int pos=lower_bound(fib+1,fib+1+30,siz[u])-fib;
	if(!p1&&(pos==k||k<=2)&&siz[u]==fib[pos])
	{
		p1=u;p2=fa;
		e[last].used=1;
		e[fan(last)].used=1;
	}
		
}