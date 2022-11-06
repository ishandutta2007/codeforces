#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define ll long long
#define N 1000010
#define M 2010
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt;
ll d[N<<1];
ll disa[N],disb[N];
bool vis[N];
void add(int u,int v,ll w)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	d[cnt]=w;
	head[u]=cnt;
}
struct cmp{
	int u;
	ll dis;
	bool operator <(const cmp a)const{return dis>a.dis;}
};
priority_queue<cmp>q;
void dij(int s,ll dis[])
{
	memset(vis,0,sizeof(vis));
	memset(dis,30,sizeof(disa));
	dis[s]=0;
	q.push((cmp){s,0});
	while(!q.empty())
	{
		int u=q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=head[u];i;i=nxt[i])
		{
			int v=to[i];
			if(dis[v]>dis[u]+d[i])
			{
				dis[v]=dis[u]+d[i];
				q.push((cmp){v,dis[v]});
			}
		}
	}
}
ll num[M][M],val[M][M];
ll numx[M][M],numy[M][M],valx[M][M],valy[M][M];
ll c[N];
ll f[M][M][2];
vector<ll>p1,p2;
ll getnumx(int x,int l,int r){return numx[x][r]-numx[x][l-1];}
ll getnumy(int y,int l,int r){return numy[r][y]-numy[l-1][y];}
ll getvalx(int x,int l,int r){return valx[x][r]-valx[x][l-1];}
ll getvaly(int y,int l,int r){return valy[r][y]-valy[l-1][y];}
int main()
{
	int n,m,s,t;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
	dij(s,disa);
	dij(t,disb);
	for(int i=1;i<=n;i++) p1.push_back(disa[i]),p2.push_back(disb[i]);
	sort(p1.begin(),p1.end());
	sort(p2.begin(),p2.end());
	int ln=unique(p1.begin(),p1.end())-p1.begin();
	int lm=unique(p2.begin(),p2.end())-p2.begin();
	p1.resize(ln);
	p2.resize(lm);
	for(int i=1;i<=n;i++)
	{
		int x=lower_bound(p1.begin(),p1.end(),disa[i])-p1.begin()+1;
		int y=lower_bound(p2.begin(),p2.end(),disb[i])-p2.begin()+1;
		num[x][y]++;
		val[x][y]+=c[i];
	}
	for(int i=1;i<=ln+1;i++)
		for(int j=1;j<=lm+1;j++)
		{
			numx[i][j]=numx[i][j-1]+num[i][j];
			valx[i][j]=valx[i][j-1]+val[i][j];
		}
	for(int j=1;j<=lm+1;j++)
		for(int i=1;i<=ln+1;i++)
		{
			numy[i][j]=numy[i-1][j]+num[i][j];
			valy[i][j]=valy[i-1][j]+val[i][j];
		}
	for(int i=ln;i>=0;i--)
    	for(int j=lm;j>=0;j--)
	    {
			if(i!=ln)
			{
				ll u=getnumx(i+1,j+1,lm);
				ll v=getvalx(i+1,j+1,lm);
				if(!u) f[i][j][0]=f[i+1][j][0];
				else f[i][j][0]=max(f[i+1][j][0],f[i+1][j][1])+v;
			}
			if(j!=lm)
			{
				ll u=getnumy(j+1,i+1,ln);
				ll v=getvaly(j+1,i+1,ln);
				if(!u) f[i][j][1]=f[i][j+1][1];
				else f[i][j][1]=min(f[i][j+1][0],f[i][j+1][1])-v;
			}
		}
	printf("%s\n",f[0][0][0]>0?"Break a heart":(f[0][0][0]<0?"Cry":"Flowers"));
	return 0;
}