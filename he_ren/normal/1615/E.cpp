#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

__gnu_pbds::priority_queue<int, less<int>, pairing_heap_tag> q[MAXN];

vector<int> g[MAXN];

int f1[MAXN];
void dfs_f(int u,int fa)
{
	if((int)g[u].size() - (fa != 0) == 0)
	{
		q[u].push(0);
		return;
	}
	
	for(int v: g[u]) if(v != fa)
	{
		dfs_f(v,u);
		f1[u] = max(f1[u], f1[v] + 1);
		
		q[u].join(q[v]);
	}
	q[u].pop(); q[u].push(f1[u]);
	q[u].push(-1);
}

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	
	dfs_f(1,0);
	
	ll ans = -linf;
	int cur = 0;
	for(int i=0; i<=d; ++i)
	{
		int r = i, w = cur, b = n - r - w;
		ll t = (ll)w * (r-b);
		if(w == 0 && b)
		{
			w = 1; --b;
			t = min(t, (ll)w * (r-b));
			w = 0; ++b;
		}
		if(r - b < 0)
		{
			int k = -(r - b);
			if(k > w)
			{
				k = (k + w) / 2;
				b = k + r;
				w = n - r - b;
				t = min(t, (ll)w * (r-b));
			}
		}
		
		ans = max(ans, t);
		if(!q[1].size()) break;
		cur += q[1].top(); q[1].pop();
	}
	
	printf("%lld",ans);
	return 0;
}