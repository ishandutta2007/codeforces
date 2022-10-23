#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN];
int pre[MAXN], suf[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	pre[0] = suf[n+1] = 0;
	for(int i=1; i<=n; ++i)
		pre[i] = pre[i-1] + (a[i] == 1);
	for(int i=n; i>=1; --i)
		suf[i] = suf[i+1] + (a[i] == 0);
	
	int ans = n;
	for(int i=0; i<=n; ++i)
		ans = min(ans, pre[i] + max(0, suf[i+1] - pre[i]));
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}