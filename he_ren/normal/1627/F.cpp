#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e2 + 5;
const int MAXP = MAXN * MAXN;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
const int inf = 0x3f3f3f3f;

int n, pcnt;
bool isin(int x,int y){ return x >= 0 && x < n && y >= 0 && y < n;}
int encode(int x,int y){ return isin(x,y)? x * n + y: -1;}
int getoth(int u){ return pcnt - u - 1;}
int walk(int u,int k)
{
	return encode(u / n + dx[k], u % n + dy[k]);
}

int val[MAXP][4];

void solve(void)
{
	int m;
	scanf("%d%d",&m,&n);
	++n; pcnt = n * n;
	for(int i=0; i<pcnt; ++i)
		for(int j=0; j<4; ++j) val[i][j] = 0;
	for(int i=1; i<=m; ++i)
	{
		int r1, c1, r2, c2;
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		if(r1 == r2)
			++val[encode(r1-1, min(c1, c2))][0];
		else
			++val[encode(min(r1, r2), c1-1)][1];
	}
	
	for(int u=0; u<pcnt; ++u)
	{
		int v;
		if((v = walk(u, 0)) != -1) val[v][2] = val[u][0];
		if((v = walk(u, 1)) != -1) val[v][3] = val[u][1];
	}
	
	int ans = inf;
	
	static int dis[MAXP];
	static bool vis[MAXP];
	memset(dis,0x3f,pcnt<<2); memset(vis,0,pcnt);
	priority_queue<pii> q;
	
	int beg = encode(n / 2, n / 2);
	dis[beg] = 0; q.emplace(0, beg);
	while(q.size())
	{
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		if(u / n == 0 || u / n == n-1) ans = min(ans, dis[u]);
		if(u % n == 0 || u % n == n-1) ans = min(ans, dis[u]);
		for(int k=0; k<4; ++k)
		{
			int v = walk(u,k);
			if(v == -1) continue;
			int nxt = dis[u] + val[u][k] + val[getoth(u)][k ^ 2];
			if(nxt < dis[v])
				dis[v] = nxt,
				q.emplace(-dis[v], v);
		}
	}
	
	printf("%d\n",m - ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}