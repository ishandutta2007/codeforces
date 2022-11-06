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
int t,n,m,x,b[N],c[N];

pair<int,int> a[N];

struct Node
{
	int x,y;
	bool operator < (const Node &p)const
	{
		return x>p.x;
	}
};

priority_queue<Node> qu;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();x=read();
		for(int i=1;i<=n;++i)
			a[i]=mp(read(),i);
		while(!qu.empty()) qu.pop();
		for(int i=1;i<=m;++i)
			b[i]=0,qu.push((Node){0,i});
		sort(a+1,a+1+n);
		for(int i=1;i<=n;++i)
		{
			Node tmp=qu.top();
			qu.pop();
			b[tmp.y]+=a[i].first;
			c[a[i].second]=tmp.y;
			qu.push((Node){b[tmp.y],tmp.y});
		}
		int mx=-1e9,mn=1e9;
		for(int i=1;i<=m;++i)
		{
			mx=max(mx,b[i]);
			mn=min(mn,b[i]);
		}
		if(mx-mn>x) printf("NO\n");
		else
		{
			printf("YES\n");
			for(int i=1;i<=n;++i)
				printf("%lld ",c[i]);
			printf("\n");
		}
	}
	return 0;
}