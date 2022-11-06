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

const int N=1e5+5;
int t,n,m,a[N],fa[N],vis[N];

struct Node
{
	int l,r;
};

queue<Node> qu;

vector<int> ans;

inline int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=0;
		for(int i=1;i<=n;++i)
			a[i]=read(),fa[i]=i,vis[i]=0;
		while(!qu.empty()) qu.pop();
		ans.clear();
		for(int i=1;i<=n-1;++i)
			qu.push((Node){i,i+1});
		qu.push((Node){n,1});
		while(!qu.empty()&&m!=n)
		{
			int l=qu.front().l;
			int r=qu.front().r;
			qu.pop();
			if(vis[l]) continue;
			r=find(r);
			if(__gcd(a[l],a[r])==1)
			{
				ans.push_back(r);
				vis[r]=1;m++;
				if(r==n) fa[r]=find(1);
				else fa[r]=find(r+1);
				if(r+1==n+1) qu.push((Node){l,1});
				else qu.push((Node){l,r+1});
			}
		}
		printf("%lld ",ans.size());
		for(int i=0;i<ans.size();++i)
			printf("%lld ",ans[i]);
		printf("\n");
	}
	return 0;
}