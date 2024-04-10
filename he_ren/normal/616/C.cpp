#include<cstdio>
#include<cstring>
const int MAXN = 1e3 + 5;
const int MAXP = MAXN*MAXN;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

int n,m;
char a[MAXN][MAXN];

inline int id(int x,int y){ return (x-1)*m + y;}

int fa[MAXP],sz[MAXP];
int find(int u){ return fa[u]? fa[u]=find(fa[u]): u;}
inline void connect(int u,int v)
{
	int fu=find(u), fv=find(v);
	if(fu==fv) return;
	fa[fu]=fv;
	sz[fv]+=sz[fu];
}

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%s",a[i]+1);
	
	for(int i=1; i<=n*m; ++i) sz[i]=1;
	for(int x=1; x<=n; ++x)
	{
		for(int y=1; y<=m; ++y) if(a[x][y]=='.')
		{
			int u=id(x,y);
			for(int k=0; k<4; ++k)
			{
				int i=x+dx[k], j=y+dy[k];
				if(i<1 || i>n || j<1 || j>m || a[i][j]!='.') continue;
				connect(u,id(i,j));
			}
		}
	}
	
	for(int x=1; x<=n; ++x)
	{
		for(int y=1; y<=m; ++y)
		{
			if(a[x][y]=='.')
			{
				putchar('.');
				continue;
			}
			
			int ans=0;
			for(int k1=0; k1<4; ++k1)
			{
				int i=x+dx[k1], j=y+dy[k1];
				if(i<1 || i>n || j<1 || j>m || a[i][j]!='.') continue;
				int u=id(i,j);
				
				bool flag=1;
				for(int k2=0; k2<k1; ++k2)
				{
					i=x+dx[k2]; j=y+dy[k2];
					if(i<1 || i>n || j<1 || j>m || a[i][j]!='.') continue;
					if(find(u)==find(id(i,j)))
					{
						flag=0;
						break;
					}
				}
				if(flag) ans+=sz[find(u)];
			}
			printf("%d",(ans+1)%10);
		}
		putchar('\n');
	}
	return 0;
}