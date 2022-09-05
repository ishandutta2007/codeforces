//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
#define input1(x) x=getval()
#define input2(x,y) x=getval(),y=getval()
#define input3(x,y,z) x=getval(),y=getval(),z=getval()
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
inline int getval()
{
	int __res=0;bool __neg=0;
	char __c;__c=getchar();
	while(__c==' '||__c=='\n')__c=getchar();
	while(__c!=' '&&__c!='\n')
	{
		if(__c=='-')__neg=1;
		else __res=__res*10+__c-'0';
		__c=getchar();
	}
	if(__neg)__res=-__res;
	return __res;
}
int n,m,id[1011][1011],idn,c[500011];
char g[1011][1011];
bool vis[1011][1011];
vector<int>con[500011];
vector<pair<int,int> > dfs(int x,int y)
{
//	cout<<x<<","<<y<<endl;
	vector<pair<int,int> >v,t;
	vis[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<1||nx>n||ny<1||ny>m||g[nx][ny]=='#'||vis[nx][ny])continue;
		t=dfs(nx,ny);
		for(int i=0;i<t.size();i++)v.PB(t[i]);
	}
	v.PB(MP(x,y));
	if(v.size()>1)
	{
		idn++;
		for(int i=0;i<v.size();i++)id[v[i].FF][v[i].SS]=idn;
		v.clear();
	}
	return v;
}
bool f[10];
void color(int x)
{
	memset(f,0,sizeof(f));
	for(int i=0;i<con[x].size();i++)
	{
		if(c[con[x][i]]!=-1)f[c[con[x][i]]]=1;
	}
	for(int i=0;i<10;i++)if(!f[i]){c[x]=i;break;}
	for(int i=0;i<con[x].size();i++)
	{
		if(c[con[x][i]]==-1)color(con[x][i]);
	}
}
int main()
{
	input2(n,m);
	for(int i=1;i<=n;i++)scanf("%s",g[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(g[i][j]=='.'&&!vis[i][j])
			{
				vector<pair<int,int> > v=dfs(i,j);
				if(v.size()==1)
				{
					bool ok=0;
					for(int k=0;k<4;k++)
					{
						int nx=v[0].FF+dx[k],ny=v[0].SS+dy[k];
						if(nx>0&&ny>0&&nx<=n&&ny<=m&&id[nx][ny]>0)
						{
							ok=1;
							id[v[0].FF][v[0].SS]=id[nx][ny];
							break;
						}
					}
					if(!ok)
					{
						puts("-1");
						return 0;
					}
				}
			}
		}
	}
	memset(c,-1,sizeof(c));
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		if(g[i][j]=='#')continue;
		for(int k=0;k<4;k++)
		{
			int nx=i+dx[k],ny=j+dy[k];
			if(nx>0&&nx<=n&&ny>0&&ny<=m&&id[nx][ny]!=id[i][j])
			{
				con[id[nx][ny]].PB(id[i][j]);
				con[id[i][j]].PB(id[nx][ny]);
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		if(g[i][j]=='.'&&c[id[i][j]]==-1)color(id[i][j]);
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<id[i][j]<<" ";
		}
		puts("");
	}
	*/
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(g[i][j]=='.')
			{
				printf("%d",c[id[i][j]]);
			}
			else putchar('#');
		}
		puts("");
	}
	return 0;
}
/*
5 5
....#
.#...
...#.
.#...
.....
*/