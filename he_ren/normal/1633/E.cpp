#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 50 + 5;
const int MAXM = 3e2 + 5;
const int MAXD = MAXM * 3;
const int inf = 0x3f3f3f3f;

int n,m;
array<int,3> es[MAXM];

vector<pii> g[MAXN];
void add_edge(int i)
{
	int u = es[i][1], v = es[i][2];
	g[u].emplace_back(v, i);
	g[v].emplace_back(u, i);
}
void del_edge(int i)
{
	int u = es[i][1], v = es[i][2];
	g[u].erase(find(g[u].begin(), g[u].end(), make_pair(v, i)));
	g[v].erase(find(g[v].begin(), g[v].end(), make_pair(u, i)));
}

vector<int> path;
bool dfs_path(int u,int to,int fa = 0)
{
	if(u == to) return 1;
	for(pii it: g[u])
		if(it.first != fa && dfs_path(it.first, to, u))
		{
			path.push_back(it.second);
			return 1;
		}
	return 0;
}

int dsc[MAXD], dcnt = 0;

int resk[MAXD];
ll resb[MAXD];

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		es[i] = {w,u,v};
	}
	
	sort(es+1,es+m+1);
	
	static int tL[MAXM], tR[MAXM];
	memset(tL, 0xc0, sizeof(tL));
	memset(tR, 0x3f, sizeof(tR));
	for(int i=1; i<=m; ++i)
	{
		int u = es[i][1], v = es[i][2];
		path.clear();
		if(!dfs_path(u, v))
		{
			add_edge(i);
		}
		else if(path.size())
		{
			int j = *min_element(path.begin(), path.end());
			tR[j] = (es[j][0] + es[i][0]) / 2;
			tL[i] = tR[j] + 1;
			del_edge(j);
			add_edge(i);
		}
	}
	
	dsc[++dcnt] = inf;
	for(int i=1; i<=m; ++i)
	{
		if(tL[i] > tR[i]) continue;
		dsc[++dcnt] = tL[i];
		dsc[++dcnt] = tR[i] + 1;
		dsc[++dcnt] = es[i][0] + 1;
	}
	sort(dsc+1,dsc+dcnt+1);
	dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
	
	auto updres = [&] (int l,int r,int k,int b)
	{
		resk[l] += k; resk[r+1] -= k;
		resb[l] += b; resb[r+1] -= b;
	};
	
	for(int i=1; i<=m; ++i)
	{
		if(tL[i] > tR[i]) continue;
		int w = es[i][0];
		int l = lower_bound(dsc+1,dsc+dcnt+1,tL[i]) - dsc;
		int r = upper_bound(dsc+1,dsc+dcnt+1,tR[i]) - dsc - 1;
		if(l > r) continue;
		
		int pos = upper_bound(dsc+1,dsc+dcnt+1,w) - dsc - 1;
		pos = min(pos, r);
		pos = max(pos, l-1);
		
		updres(l, pos, -1, w);
		updres(pos+1, r, 1, -w);
	}
	
	for(int i=1; i<=dcnt; ++i)
	{
		resk[i] += resk[i-1];
		resb[i] += resb[i-1];
	}
	
	
	{
		ll res = 0;
		int tQ, Q, A, B, C;
		scanf("%d%d%d%d%d",&tQ,&Q,&A,&B,&C);
		int cur = 0;
		for(int i=1; i<=Q; ++i)
		{
			if(i <= tQ) scanf("%d",&cur);
			else cur = ((ll)cur * A + B) % C;
			
			int pos = upper_bound(dsc+1,dsc+dcnt+1,cur) - dsc - 1;
			res ^= (ll)resk[pos] * cur + resb[pos];
		}
		printf("%lld",res);
	}
	return 0;
}