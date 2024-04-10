#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int a[MAXN], b[MAXN];
int suma[MAXN], sumb[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	for(int i=1; i<=n; ++i)
	{
		suma[i] = suma[i-1] + a[i];
		sumb[i] = sumb[i-1] + b[i];
	}
	
	int ans = inf;
	for(int i=1; i<=n; ++i)
	{
		int cur = 0;
		cur = max(cur, suma[n] - suma[i]);
		cur = max(cur, sumb[i-1]);
		ans = min(ans, cur);
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}