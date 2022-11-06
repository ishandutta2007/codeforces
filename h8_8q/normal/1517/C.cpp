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

const int N=1e3+5;
int n,sum,p[N],a[N][N];

void dfs(int x,int y,int col);

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		p[i]=read();
	for(int i=n;i>=1;--i)
		sum=0,dfs(i,i,p[i]);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=i;++j)
			printf("%lld ",a[i][j]);
		printf("\n");
	}
		
	return 0;
}

void dfs(int x,int y,int col)
{
	a[x][y]=col;sum++;
	if(sum==col) return;
	if(sum!=col&&y+1<=x&&!a[x][y+1]) dfs(x,y+1,col);
	if(sum!=col&&x+1<=n&&!a[x+1][y]) dfs(x+1,y,col);
	if(sum!=col&&y-1>=1&&!a[x][y-1]) dfs(x,y-1,col);
}