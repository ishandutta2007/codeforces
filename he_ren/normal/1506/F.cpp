#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

inline int calc(int x,int y,int tx,int ty)
{
	tx -= x; ty -= y;
	tx -= ty;
	if(!tx) return (x + y) % 2? 0: ty;
	return (x + y) % 2? (tx + 1) / 2: tx / 2;
}

pii p[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i].first);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i].second);
	
	sort(p+1,p+n+1);
	ll ans = calc(1,1, p[1].first,p[1].second);
	for(int i=1; i<n; ++i)
		ans += calc(p[i].first,p[i].second, p[i+1].first, p[i+1].second);
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}