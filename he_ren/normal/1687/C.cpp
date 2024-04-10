#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;

int a[MAXN], b[MAXN];
pii p[MAXM];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	for(int i=1; i<=m; ++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		p[i] = {l-1, r};
	}
	
	static int rem[MAXM];
	static vector<int> g[MAXN];
	for(int i=0; i<=n; ++i) g[i].clear();
	for(int i=1; i<=m; ++i)
	{
		rem[i] = 2;
		g[p[i].first].push_back(i);
		g[p[i].second].push_back(i);
	}
	
	set<int> t;
	for(int i=0; i<=n; ++i) t.emplace_hint(t.end(), i);
	function<void(int)> light = [&] (int x)
	{
		t.erase(x);
		for(auto i: g[x])
		{
			if(--rem[i] != 0) continue;
			int l = p[i].first, r = p[i].second;
			while(1)
			{
				auto it = t.lower_bound(l);
				if(it == t.end() || *it > r) break;
				light(*it);
			}
		}
	};
	
	light(0);
	ll sum = 0;
	for(int i=1; i<=n; ++i)
	{
		sum = sum + a[i] - b[i];
		if(sum == 0) light(i);
	}
	if(t.size()) printf("NO\n");
	else printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}