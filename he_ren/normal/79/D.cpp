#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e4 + 5;
const int MAXM = 1e2 + 5;
const int MAXD = 20 + 5;
const int ALL = (1<<20) + 5;
const int inf = 0x3f3f3f3f;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

int a[MAXN], len[MAXM];

int main(void)
{
	int n,d,m;
	scanf("%d%d%d",&n,&d,&m);
	for(int i=1; i<=d; ++i)
	{
		int x;
		scanf("%d",&x);
		a[x] = 1;
	}
	for(int i=1; i<=m; ++i) scanf("%d",&len[i]);
	
	++n;
	for(int i=n; i>=1; --i) a[i] ^= a[i-1];
	
	vector<int> pos;
	for(int i=1; i<=n; ++i)
		if(a[i]) pos.push_back(i);
	d = (int)pos.size();
	
	auto bfs_dis = [&] (int beg)
	{
		--beg;
		vector<int> res(n, inf);
		queue<int> q;
		res[beg] = 0; q.push(beg);
		while(q.size())
		{
			int u = q.front(); q.pop();
			for(int i=1; i<=m; ++i)
				for(int v: {u - len[i], u + len[i]})
					if(v >= 0 && v < n && res[v] == inf)
						res[v] = res[u] + 1, q.push(v);
		}
		return res;
	};
	
	static int dis[MAXD][MAXD];
	for(int i=0; i<d; ++i)
	{
		vector<int> t = bfs_dis(pos[i]);
		for(int j=0; j<d; ++j)
			dis[i][j] = t[pos[j] - 1];
	}
	
	int all = (1<<d) - 1;
	
	static int dp[ALL];
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for(int mask=1; mask<=all; ++mask)
	{
		int u = 0;
		while(!bdig(mask, u)) ++u;
		
		for(int v=u+1; v<d; ++v) if(bdig(mask, v))
			dp[mask] = min(dp[mask], dp[mask ^ bbit(u) ^ bbit(v)] + dis[u][v]);
	}
	
	if(dp[all] == inf) printf("-1");
	else printf("%d",dp[all]);
	return 0;
}