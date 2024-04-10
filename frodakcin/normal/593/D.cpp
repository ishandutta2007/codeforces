#include <cstdio>
#include <vector>
#include <algorithm>

const int MN = 2e5+10, MM=2e5+10;
using ll = long long;
struct edge
{
public:
	int n; ll w; int i;
};
std::vector<edge> a[MN];

int dp[MN], p[MN][20], d[MN], map[MN], N, M;
ll w[MN];
int find(int n){return dp[n]?dp[n]=find(dp[n]):n;}
void dfs(int n=1)
{
	if(w[n]==1)
		dp[n]=find(p[n][0]);
	for(int i=0;p[n][i]&&p[p[n][i]][i];++i)
		p[n][i+1]=p[p[n][i]][i];
	for(auto x:a[n])
		if(p[n][0]!=x.n)
			map[x.i]=x.n, p[x.n][0]=n, d[x.n]=d[n]+1,w[x.n]=x.w, dfs(x.n);
}
int mu(int a, int x)
{
	for(int i=0;x;x>>=1, ++i)
		if(x&1) a=p[a][i];
	return a;
}
int lca(int a, int b)
{
	if(d[a]>d[b]) std::swap(a,b);
	b=mu(b, d[b]-d[a]);
	if(a==b) return a;
	for(int i=17;i>=0;--i)
		if(p[a][i]!=p[b][i])
			a=p[a][i],b=p[b][i];
	return p[a][0];
}
std::vector<ll> q, r;
int main(void)
{
	scanf("%d%d", &N, &M);
	for(int i=0,x,y;i+1<N;++i)
	{
		ll c;
		scanf("%d%d%lld", &x, &y, &c), a[x].push_back({y, c, i+1}), a[y].push_back({x, c, i+1});
	}
	dfs();
	for(int i=0,t,a,b;i<M;++i)
	{
		ll c;
		scanf("%d%d", &t, &a);
		if(t==1)
		{
			scanf("%d%lld", &b, &c);
			int x=lca(a,b), ctr=0;;
			a=find(a), b=find(b), x=find(x);
			for(;ctr<60&&a!=x;a=find(p[a][0]), ++ctr) q.push_back(w[a]);
			for(;ctr<60&&b!=x;b=find(p[b][0]), ++ctr) r.push_back(w[b]);

			if(ctr==60)
				printf("0\n");
			else
			{
				std::reverse(r.begin(), r.end());
				for(auto y:q) c/=y;
				for(auto y:r) c/=y;
				printf("%lld\n", c);
			}
			q.clear(), r.clear();
		}
		else
		{
			a=map[a];
			scanf("%lld", &c);
			if(c==1) dp[a]=find(p[a][0]);
			w[a]=c;
		}
	}
}