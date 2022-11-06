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
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=4e5+5;
int t,n,m,a[N],dep[N],p1,p2,fl,all;

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v);
void dfs(int u);

signed main()
{
	t=read();
	memset(dep,-1,sizeof(dep));
	while(t--)
	{
		n=read();m=read();
		all=0;
		for(int i=1;i<=n;++i)
			dep[i]=-1,head[i]=0;
		tot=0;
		for(int i=1;i<=n;++i)
			a[i]=read();
		for(int i=1;i<=n;++i)
			a[i]=read()-a[i],all+=a[i];
		for(int i=1;i<=m;++i)
		{
			int u=read(),v=read();
			add(u,v);add(v,u);
		}
		if(all%2!=0)
		{
			printf("NO\n");
			continue;
		}
		p1=0;p2=0;fl=1;
		dep[1]=0;dfs(1);
		if(fl&&p1!=p2)
			printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

void dfs(int u)
{
	if(dep[u]) p1+=a[u];
	else p2+=a[u];
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(dep[v]==-1)
		{
			dep[v]=dep[u]^1;
			dfs(v);
		}
		else if(dep[u]==dep[v])
			fl=0;
	}
}