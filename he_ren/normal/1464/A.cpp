#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

pii p[MAXN];
int r[MAXN], c[MAXN];
int rid[MAXN], cid[MAXN];

int fa[MAXN];
inline void init(int n){ for(int i=1; i<=n; ++i) fa[i] = i;}
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
void connect(int u,int v){ fa[find(u)] = find(v);}

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
		scanf("%d%d",&p[i].first,&p[i].second);
	
	for(int i=1; i<=n; ++i) r[i] = c[i] = rid[i] = cid[i] = 0;
	for(int i=1; i<=m; ++i)
	{
		int x = p[i].first, y = p[i].second;
		r[x] = y; c[y] = x;
		rid[x] = cid[y] = i;
	}
	
	queue<int> q;
	for(int i=1; i<=n; ++i)
	{
		if(r[i] && c[i]) continue;
		if(!r[i] && !c[i]) continue;
		if(r[i]) q.push(rid[i]);
		else q.push(cid[i]);
	}
	
	int ans = 0;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		int &x = p[u].first, &y = p[u].second;
		if(x == y) continue;
		
		if(!r[y])
		{
			++ans;
			r[x] = rid[x] = 0;
			if(c[x]) q.push(cid[x]);
			
			x = y;
			r[y] = y; rid[y] = u;
		}
		else if(!c[x])
		{
			++ans;
			c[y] = cid[y] = 0;
			if(r[y]) q.push(rid[y]);
			
			y = x;
			c[x] = x; cid[x] = u;
		}
	}
	
	static bool has[MAXN];
	for(int i=1; i<=n; ++i) has[i] = 0;
	init(n);
	
	int cnt = 0;
	for(int i=1; i<=m; ++i)
		if(p[i].first != p[i].second)
		{
			++cnt;
			has[p[i].first] = has[p[i].second] = 1;
			connect(p[i].first, p[i].second);
		}
	for(int i=1; i<=n; ++i) if(has[i] && find(i) == i)
		++cnt;
	
	printf("%d\n",ans + cnt);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}