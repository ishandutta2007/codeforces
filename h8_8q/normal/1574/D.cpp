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
#define INF 0x3f3f3f3f3f3f3f3f

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

const int N=15,M=2e5+5;
int n,m,c[N],a[N][M],ban[M][N],b[N],ans,Ans[N];

struct Node
{
	int x,y;
	bool operator < (const Node &p)const
	{
		return x<p.x;
	}
};

struct Trie
{
	set<Node> ch[1000005];
	int cnt=0;
	void insert(int x)
	{
		int u=0;
		for(int i=1;i<=n;++i)
		{
			auto it=ch[u].find((Node){ban[x][i],0});
			auto qwq=ch[0].find((Node){3,0});
			if(it==ch[u].end()) ch[u].insert((Node){ban[x][i],++cnt}),u=cnt;
			else u=(*it).y;
		}
	}
	bool query()
	{
		int u=0;
		for(int i=1;i<=n;++i)
		{
			auto it=ch[u].find((Node){b[i],0});
			if(it==ch[u].end()) return 1;
			else u=(*it).y;
		}
		return 0;
	}
}trie;

inline int cmp()
{
	int sum=0;
	for(int i=1;i<=n;++i)
		sum+=a[i][b[i]];
	return sum>ans?sum:0;
}

signed main()
{
	//freopen("yangli.in","r",stdin);
	//freopen("std.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
	{
		c[i]=read();b[i]=c[i];
		for(int j=1;j<=c[i];++j)
			a[i][j]=read();
	}
	m=read();
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
			ban[i][j]=read();
		trie.insert(i);
	}
	if(trie.query())
	{
		for(int i=1;i<=n;++i)
			printf("%lld ",c[i]);
		return 0;
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
			b[j]=ban[i][j];
		for(int j=1;j<=n;++j)
		{
			b[j]--;
			if(trie.query()&&b[j])
			{
				int tmp=cmp();
				if(tmp)
				{
					ans=tmp;
					for(int k=1;k<=n;++k)
						Ans[k]=b[k];
				}
			}
			b[j]++;
		}
	}
	for(int i=1;i<=n;++i)
		printf("%lld ",Ans[i]);
	return 0;
}