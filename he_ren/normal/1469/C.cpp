#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

ll h[MAXN];
ll f[MAXN], g[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%lld",&h[i]);
	
	f[1] = g[1] = h[1];
	for(int i=1; i<n; ++i)
	{
		if(f[i] > g[i]){ printf("NO\n"); return;}
		f[i+1] = max(h[i+1], f[i] - d + 1);
		g[i+1] = min(h[i+1] + d - 1, g[i] + d - 1);
	}
	f[n] = max(f[n], h[n]); g[n] = min(g[n], h[n]);
	if(f[n] <= g[n]) printf("YES\n");
	else printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}