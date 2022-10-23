#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN], b[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	vector<int> p[2];
	for(int i=1; i<=n; ++i)
		p[a[i]].push_back(b[i]);
	
	sort(p[0].begin(), p[0].end(), greater<int>());
	sort(p[1].begin(), p[1].end(), greater<int>());
	
	ll ans = 0, cur = 0;
	int t = min((int)p[0].size(), (int)p[1].size());
	for(int i=-1; i<(int)p[0].size() && i<(int)p[1].size(); ++i)
	{
		if(i >= 0) cur += p[0][i] + p[1][i];
		if(i+1 < t)
			ans = max(ans, cur + p[0][i+1]), ans = max(ans, cur + p[1][i+1]);
		if(i+1 < (int)p[0].size() || i+1 < (int)p[1].size())
			ans = max(ans, cur);
	}
	
	ans += accumulate(b+1, b+n+1, 0ll);
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}