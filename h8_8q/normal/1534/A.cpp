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

const int N=55;
int t,n,m;
char s[N][N];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

void dfs(int x,int y)
{
	for(int i=0;i<4;++i)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(s[xx][yy]=='.')
		{
			if(s[x][y]=='R')
				s[xx][yy]='W';
			else s[xx][yy]='R';
			dfs(xx,yy);
		}
	}
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		for(int i=1;i<=n;++i)
			scanf("%s",s[i]+1);
		int f1=0,f2=0,f3=0,f4=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(s[i][j]=='R')
				{
					if((i+j)%2==1)
						f1=1;
					else f2=1;
				}
				else if(s[i][j]=='W')
				{
					if((i+j)%2==1)
						f3=1;
					else f4=1;
				}
		if((f1&&f2)||(f3&&f4))
			printf("NO\n");
		else if((f1&&f3)||(f2&&f4))
			printf("NO\n");
		else
		{
			printf("YES\n");
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					if(s[i][j]!='.')
						dfs(i,j);
			if(s[1][1]=='.')
				s[1][1]='R',dfs(1,1);
			for(int i=1;i<=n;++i)
				puts(s[i]+1);
		}
	}
	return 0;
}