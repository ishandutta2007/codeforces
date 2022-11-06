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

const int N=2e5+5;
int n,m,k,a[N],b[N],sum[N],vis[N],a1,a2;
char s[N];

inline void work(int x)
{
	int p=0,c[20];
	for(int i=0;i<m;++i)
		if((a[x]>>i)&1)
			c[++p]=i;
	for(int i=1;i<=n;++i)
	{
		b[i]=0;
		for(int j=0;j<p;++j)
			if((a[i]>>c[j+1])&1)
				b[i]|=(1ll<<j);
	}
	for(int i=0;i<(1<<p);++i)
		sum[i]=0;
	for(int i=1;i<=n;++i)
		sum[b[i]]++;
	for(int j=0;j<p;++j)
		for(int i=(1<<p)-1;i>=0;--i)
			if(((i>>j)&1)==0)
				sum[i]+=sum[i^(1ll<<j)];
	for(int i=0;i<(1<<p);++i)
		if(sum[i]>=(n+1)/2)
		{
			int tmp=0;
			for(int j=0;j<p;++j)
				if((i>>j)&1) tmp++;
			if(tmp>a1)
			{
				a1=tmp;a2=0;
				for(int j=0;j<p;++j)
					if((i>>j)&1)
						a2|=(1ll<<c[j+1]);
			}
		}
}

signed main()
{
	n=read();m=read();k=read();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=0;j<m;++j)
			a[i]|=((s[j+1]-'0'+0ll)<<j);
	}
	srand(114514);
	for(int i=1;i<=30&&i<=n;++i)
	{
		int x=rand()*1ll*rand()%n+1;
		while(vis[x]) x=rand()%n+1;
		work(x);vis[x]=1;
	}
	for(int j=0;j<m;++j)
		printf("%lld",(a2>>j)&1);
	return 0;
}