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

const int N=2e5+5;
int t,n,l,r,a[N];

struct Node1
{
	int x,y;
	bool operator < (const Node1 &p)const
	{
		return x>p.x;
	}
};

priority_queue<Node1> qu1;

struct Node2
{
	int x,y;
	bool operator < (const Node2 &p)const
	{
		return x<p.x;
	}
};

priority_queue<Node2> qu2;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();l=read();r=read();
		for(int i=1;i<=l;++i) a[read()]++;
		for(int i=1;i<=r;++i) a[read()]--;
		int all=0;
		for(int i=1;i<=n;++i)
			all+=a[i]; 
		int sum=0,ans=max(l,r)-n/2;
		int hav=ans;
		if(all<=0)
		{
			for(int i=1;i<=n;++i)
				qu1.push((Node1){a[i],i});
			for(int i=1;i<=ans;++i)
			{
				Node1 tmp=qu1.top();qu1.pop();
				qu1.push((Node1){tmp.x+2,tmp.y});
			}
			while(!qu1.empty())
			{
				Node1 tmp=qu1.top();qu1.pop();
				a[tmp.y]=tmp.x;
			}
		}
		else
		{
			for(int i=1;i<=n;++i)
				qu2.push((Node2){a[i],i});
			for(int i=1;i<=ans;++i)
			{
				Node2 tmp=qu2.top();qu2.pop();
				qu2.push((Node2){tmp.x-2,tmp.y});
			}
			while(!qu2.empty())
			{
				Node2 tmp=qu2.top();qu2.pop();
				a[tmp.y]=tmp.x;
			}
		}
		for(int i=1;i<=n;++i)
			sum+=abs(a[i]);
		ans+=sum/2;
		printf("%lld\n",ans);
		for(int i=1;i<=n;++i)
			a[i]=0;
	}
	return 0;
}