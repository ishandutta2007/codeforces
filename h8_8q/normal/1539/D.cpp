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

const int N=1e5+5;
int n;

struct Node
{
	int a,b;
	bool operator < (const Node &x)const
	{
		return b<x.b;
	}
}p[N];

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		p[i].a=read(),p[i].b=read();
	sort(p+1,p+1+n);
	int now=0,ans=0,las=n;
	for(int i=1;i<=n;++i)
	{
		while(las>i&&p[i].b>now)
		{
			if(p[i].b-now<p[las].a)
			{
				p[las].a-=p[i].b-now;
				ans+=(p[i].b-now)*2;
				now=p[i].b;
				break;
			}
			now+=p[las].a;
			ans+=p[las].a*2;
			p[las].a=0;las--;
		}
		if(now+p[i].a<=p[i].b)
			now+=p[i].a,ans+=p[i].a*2;
		else
		{
			int tmp=min(now+p[i].a-p[i].b,p[i].a);
			now+=p[i].a;ans+=p[i].a*2-tmp;
		}
	}
	printf("%lld\n",ans);
	return 0;
}