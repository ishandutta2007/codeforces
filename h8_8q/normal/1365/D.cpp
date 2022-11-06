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

const int N=55;
int t,n,m,vis[N][N];
char a[N][N];

void dfs(int x,int y);

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		for(int i=1;i<=n;++i)
			scanf("%s",a[i]+1);
		int fl=1;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(a[i][j]=='B')
				{
					if(a[i-1][j]=='G') fl=0; 
					if(a[i+1][j]=='G') fl=0; 
					if(a[i][j-1]=='G') fl=0; 
					if(a[i][j+1]=='G') fl=0; 
					if(a[i-1][j]=='.') a[i-1][j]='#'; 
					if(a[i+1][j]=='.') a[i+1][j]='#';
					if(a[i][j-1]=='.') a[i][j-1]='#';
					if(a[i][j+1]=='.') a[i][j+1]='#';
				}
		if(!fl)
		{
			printf("NO\n");
			continue;
		}
		dfs(n,m);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				if(a[i][j]=='G'&&!vis[i][j])
					fl=0;
				vis[i][j]=0;a[i][j]='\0';
			}
		if(!fl)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
	return 0;
}

void dfs(int x,int y)
{
	if(a[x][y]=='#') return;
	if(vis[x][y]) return;
	vis[x][y]=1;
	if(x-1>=1&&a[x-1][y]!='#') dfs(x-1,y);
	if(x+1<=n&&a[x+1][y]!='#') dfs(x+1,y);
	if(y-1>=1&&a[x][y-1]!='#') dfs(x,y-1);
	if(y+1<=m&&a[x][y+1]!='#') dfs(x,y+1);
}