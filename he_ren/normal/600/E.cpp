#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
#define fir first
#define sec second
#define mp make_pair
const int MAXN = 1e5 + 5;

struct Edge
{
	int next,to;
}e[MAXN*2];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u]=etot;
}

int c[MAXN];

map<int,int> t[MAXN];
int mx[MAXN];
ll ans[MAXN];
int p[MAXN];

void dfs(int u,int fa)
{
	p[u]=u;
	t[u][c[u]]=1;
	mx[u]=1;
	ans[u]=c[u];
		
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
		if(t[p[u]].size() < t[p[v]].size())
		{
			swap(p[u],p[v]);
			mx[u]=mx[v];
			ans[u]=ans[v];
		}
		
		map<int,int> &mpu=t[p[u]], &mpv=t[p[v]];
		for(map<int,int>::iterator it=mpv.begin(); it!=mpv.end(); ++it)
		{
			int clr=it->fir, tot=it->sec;
			mpu[clr] += tot;
			
			if(mpu[clr]>mx[u])
				mx[u]=mpu[clr], ans[u]=0;
			if(mpu[clr]==mx[u])
				ans[u]+=clr;
		}
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&c[i]);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	dfs(1,0);
	for(int i=1; i<=n; ++i) cout<<ans[i]<<' ';
	return 0;
}