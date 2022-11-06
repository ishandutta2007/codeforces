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

const int N=1005;
int n,a[N],a1[N],a2[N];

void dfs(int u);

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read(); 
	a[n+1]=n+1;
	dfs(1);
	return 0;
}

void dfs(int u)
{
	int fl=1;
	for(int i=1;i<=n;++i)
		if(a[i]!=i) fl=0;
	if(fl)
	{
		printf("%d\n",u-1);
		for(int i=u-1;i>=1;--i)
			printf("%d %d\n",a1[i],a2[i]);
		exit(0);
	}
	if(u==4) return;
	int m=0,b[55];
	for(int i=1;i<=n;++i)
		if(abs(a[i]-a[i-1])>1||abs(a[i]-a[i+1])>1)
			b[++m]=i;
	for(int i=1;i<=m;++i)
		for(int j=i+1;j<=m;++j)
		{
			reverse(a+b[i],a+b[j]+1);
			a1[u]=b[i];a2[u]=b[j];
			dfs(u+1);
			reverse(a+b[i],a+b[j]+1);
		}
}