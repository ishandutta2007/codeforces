#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e3 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll ans = 0;
	static ll tag[MAXN];
	for(int i=1; i<=n+2; ++i) tag[i] = 0;
	for(int i=1; i<=n; ++i)
	{
		tag[i] += tag[i-1];
		if(tag[i] <= a[i] - 1)
		{
			ans += a[i] - tag[i] - 1;
			int l = i+2, r = min(n, i + a[i]);
			if(l <= r) ++tag[l], --tag[r+1];
		}
		else
		{
			int l = i+2, r = min(n, i + a[i]);
			if(l <= r) ++tag[l], --tag[r+1];
			tag[i+1] += (tag[i] - (a[i]-1));
			tag[i+2] -= (tag[i] - (a[i]-1));
		}
	}
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}