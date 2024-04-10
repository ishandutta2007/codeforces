#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define x first
#define y second

using namespace std;

const int maxn=1005;

int dis[maxn],cost[maxn][maxn],par[maxn][maxn],m,n,team[maxn],x,y,k,i,j,nor[maxn],K;
vector<int> E[maxn],P[maxn];
pair<int,int> a[maxn];

struct cerc
{
	int r,x,y;
}c[maxn];

void build_dis(int x)
{
    for(vector<int>::iterator it=E[x].begin();it!=E[x].end();++it)
		dis[*it]=dis[x]+1,build_dis(*it);
}

void go(int x)
{
    //fprintf(stderr,"Pentru %d->\n",x);
	for(int i=0;i<=m;++i)
	{
		if(par[i][x]==1)
			--dis[i];
		else
			++dis[i];
	    //fprintf(stderr,"%d->%d\n",i,dis[i]);
	}
	for(vector<int>::iterator it=E[x].begin();it!=E[x].end();++it)
		go(*it);
	for(vector<int>::iterator it=P[x].begin();it!=P[x].end();++it)
		for(int j=1;j<=n;++j)
        	cost[*it][j]=dis[team[j]];
	for(int i=0;i<=m;++i)
		if(par[i][x]==1)
			++dis[i];
		else
			--dis[i];
}

bool is_in(int x,int y)
{
	if(c[x].r>=c[y].r)
		return false;
	return 1LL*(c[x].x-c[y].x)*(c[x].x-c[y].x)+1LL*(c[x].y-c[y].y)*(c[x].y-c[y].y)<1LL*(c[x].r-c[y].r)*(c[x].r-c[y].r);
}

bool am_in(int x,int y)
{
	return 1LL*(a[x].x-c[y].x)*(a[x].x-c[y].x)+1LL*(a[x].y-c[y].y)*(a[x].y-c[y].y)<1LL*c[y].r*c[y].r;
}

int main()
{
	scanf("%d%d%d",&n,&m,&K);
	for(i=1;i<=n;++i)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(i=1;i<=m;++i)
		scanf("%d%d%d",&c[i].r,&c[i].x,&c[i].y);
	for(i=1;i<=m;++i)
	{
		k=0;
		for(j=1;j<=m;++j)
			if(j!=i)
				if(is_in(i,j))
				{
					par[i][j]=1;
					if(k==0||is_in(j,k))
						k=j;
				}
		E[k].push_back(i);
		nor[i]=1;
	}
    for(i=1;i<=m;++i)
	{
		if(nor[i]==0)
			E[0].push_back(i);
		par[i][0]=par[i][i]=1;
	}
	
	for(i=1;i<=n;++i)
	{
		k=0;
		for(j=1;j<=m;++j)
			if(am_in(i,j))
				if(k==0||is_in(j,k))
					k=j;
		P[k].push_back(i);
		team[i]=k;
    }
	dis[0]=1;
	par[0][0]=1;
	build_dis(0);
	go(0);
	for(i=1;i<=K;++i)
		scanf("%d%d",&x,&y),printf("%d\n",cost[x][y]);
}