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

const int N=3e5+5;
int t,n,m,a[N],b[N],c[N],fa[N],vis[N];

struct BIT
{
	int c[N];
	void add(int x,int v)
	{
		for(;x<=n;x+=lowbit(x))
			c[x]+=v;
	}
	void update(int l,int r,int v)
	{
		if(l>r) return;
		add(l,v);add(r+1,-v);
	}
	int query(int x)
	{
		int res=0;
		for(;x;x-=lowbit(x))
			res+=c[x];
		return res;
	}
}sum;

int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

inline bool check(int x)
{
	for(int i=1;i<=n;++i)
		fa[i]=i,b[i]=(i-1-x+n)%n+1,vis[i]=0;
	for(int i=1;i<=n;++i)
		fa[find(c[i])]=find(b[i]);
	int res=n;
	for(int i=1;i<=n;++i)
		if(!vis[find(i)])
			res--,vis[find(i)]=1;
	return res<=m;
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		for(int i=1;i<=n;++i)
		{
			c[i]=read();
			a[c[i]]=i,sum.c[i]=0;
		}
		for(int i=1;i<=n;++i)
		{
			int ps=-1;
			if(a[i]>=i)
				ps=a[i]-i+1;
			else ps=a[i]+n-i+1;
			sum.update(1,ps-1,1);
			sum.update(ps+1,n,1);
		}
		vector<int> ans;
		for(int i=1;i<=n;++i)
			if(sum.query(i)<=m*2&&check(i-1))
				ans.push_back(i-1);
		printf("%lld ",ans.size());
		for(int i=0;i<ans.size();++i)
			printf("%lld ",ans[i]);
		printf("\n");
	}
	return 0;
}