#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int a[MAXN];
pii f[MAXN], g[MAXN];
// f = inc, max{dec}
// g = dec, min{inc}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	f[1] = {inf, 0}; g[1] = {-inf, 0};
	for(int i=2; i<=n; ++i)
	{
		f[i] = {-inf, 0}; g[i] = {inf, 0};
		int lstf = f[i-1].first, lstg = g[i-1].first;
		
		if(a[i-1] < a[i]) f[i] = max(f[i], {lstf, 0});
		if(lstg < a[i]) f[i] = max(f[i], {a[i-1], 1});
		
		if(a[i-1] > a[i]) g[i] = min(g[i], {lstg, 1});
		if(lstf > a[i]) g[i] = min(g[i], {a[i-1], 0});
	}
	
	if(f[n].first == -inf && g[n].first == inf)
	{
		printf("NO");
		return 0;
	}
	
	static int res[MAXN];
	int cur = f[n].first != -inf? 0: 1;
	for(int i=n; i>=1; --i)
	{
		res[i] = cur;
		cur = cur == 0? f[i].second: g[i].second;
	}
	
	printf("YES\n");
	for(int i=1; i<=n; ++i) printf("%d ",res[i]);
	return 0;
}