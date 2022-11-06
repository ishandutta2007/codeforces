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

const int N=2005;
int n,m;
char s[N][N];
int dx[8]={1,-1,0,0,1,1,-1,-1},dy[8]={0,0,1,-1,1,-1,1,-1};

struct Node
{
	int x,y;
};

inline bool check(int x,int y);
inline void bfs();

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	bfs();
	for(int i=1;i<=n;++i)
		puts(s[i]+1);
	return 0;
}

inline bool check(int x,int y)
{
	if(s[x-1][y]=='.'&&s[x-1][y-1]=='.'&&s[x][y-1]=='.') return 1;
	if(s[x-1][y]=='.'&&s[x-1][y+1]=='.'&&s[x][y+1]=='.') return 1;
	if(s[x+1][y]=='.'&&s[x+1][y-1]=='.'&&s[x][y-1]=='.') return 1;
	if(s[x+1][y]=='.'&&s[x+1][y+1]=='.'&&s[x][y+1]=='.') return 1;
	return 0;
}

inline void bfs()
{
	queue<Node> qu;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(s[i][j]=='.')
				qu.push((Node){i,j});
	while(!qu.empty())
	{
		int x=qu.front().x;
		int y=qu.front().y;
		qu.pop();
		for(int i=0;i<8;++i)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(s[xx][yy]=='*'&&check(xx,yy))
				s[xx][yy]='.',qu.push((Node){xx,yy});
		}
	}
}