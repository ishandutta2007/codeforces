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

const int N=1e5+5;
int t,n;
char s[N];

struct SAM
{
	int ch[27],fa,len,siz;
}a[N*2];
int last,cnt;

struct Edge
{
	int v,ne;
}e[N*2];
int head[N*2],tot;

inline void add(int c);
inline void add_edge(int u,int v);
void dfs(int u,int fa);

signed main()
{
	t=read();
	while(t--)
	{
		last=cnt=1;tot=0;
		memset(head,0,sizeof(head));
		memset(a,0,sizeof(a));
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;++i)
			add(s[i]-'a'+1);
		for(int i=1,j=1;i<=n;++i)
		{
			j=a[j].ch[s[i]-'a'+1];
			a[j].siz=1;
		}
		for(int i=1;i<=cnt;++i)
			add_edge(a[i].fa,i);
		dfs(1,0);
		int ans=0;
		for(int i=1;i<=cnt;++i)
			ans+=a[i].siz*a[i].siz*(a[i].len-a[a[i].fa].len);
		printf("%lld\n",ans);
	}
	return 0;
}

inline void add(int c)
{
	int u=last;last=++cnt;
	a[cnt].len=a[u].len+1;
	for(;u&&!a[u].ch[c];u=a[u].fa)
		a[u].ch[c]=cnt;
	if(u==0)
		a[cnt].fa=1;
	else
	{
		int v=a[u].ch[c];
		if(a[v].len==a[u].len+1)
			a[cnt].fa=v;
		else
		{
			int p=++cnt;
			a[p]=a[v];a[p].len=a[u].len+1;
			for(;u&&a[u].ch[c]==v;u=a[u].fa)
				a[u].ch[c]=p;
			a[cnt-1].fa=a[v].fa=p;
		}
	}
}

inline void add_edge(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

void dfs(int u,int fa)
{
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		a[u].siz+=a[v].siz;
	}
}