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

const int N=505;
int n,k,len[N],pre[N],sum1[N],sum2[N],vis[N];

struct Node
{
	int u,s;
};

set<int> in,out;

inline void bfs();
int print(int x);

signed main()
{
	n=read();k=read();
	bfs();
	if(vis[n]==0)
	{
		printf("-1\n");
		return 0;
	}
	printf("! %lld\n",print(n));
	fflush(stdout);
	return 0;
}

inline void bfs()
{
	queue<Node> qu;
	qu.push((Node){0,0});
	len[0]=0;vis[0]=1;pre[0]=-1;
	while(!qu.empty())
	{
		int u=qu.front().u;
		int s=qu.front().s;
		qu.pop();
		for(int i=0;i+i<k;++i)
			if(u>=i&&n-u>=i)
			{
				if(n-u>=k-i&&!vis[u+k-i-i])
				{
					int v=u+k-i-i;
					vis[v]=1;pre[v]=u;
					sum1[v]=i;sum2[v]=k-i;
					qu.push((Node){v,s+1});
				}
				if(u>=k-i&&!vis[u-k+i+i])
				{
					int v=u-k+i+i;
					vis[v]=1;pre[v]=u;
					sum2[v]=i;sum1[v]=k-i;
					qu.push((Node){v,s+1});
				}
			}
	}
}

int print(int x)
{
	if(pre[x]==-1)
	{
		for(int i=1;i<=n;++i)
			out.insert(i);
		return 0;
	}
	int res=print(pre[x]);
	int sm1=sum1[x];
	int sm2=sum2[x];
	vector<int> p1,p2;
	printf("? ");
	auto it=in.begin();
	for(int i=0;i<sm1;++i,++it)
		p1.push_back(*it),printf("%lld ",*it);
	it=out.begin();
	for(int i=0;i<sm2;++i,++it)
		p2.push_back(*it),printf("%lld ",*it);
	printf("\n");fflush(stdout);
	res^=read();
	for(int i=0;i<p1.size();++i)
	{
		in.erase(in.find(p1[i]));
		out.insert(p1[i]);
	}
	for(int i=0;i<p2.size();++i)
	{
		out.erase(out.find(p2[i]));
		in.insert(p2[i]);
	}
	return res;
}