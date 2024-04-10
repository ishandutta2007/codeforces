#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static int dsc[MAXN];
	int dcnt = 0;
	for(int i=1; i<=n; ++i) dsc[++dcnt] = a[i];
	sort(dsc+1,dsc+dcnt+1);
	dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
	for(int i=1; i<=n; ++i) a[i] = lower_bound(dsc+1,dsc+dcnt+1,a[i]) - dsc;
	
	static int lef[MAXN], rig[MAXN];
	memset(lef, 0x3f, (dcnt+2)<<2); memset(rig, 0xc0, (dcnt+2)<<2);
	for(int i=1; i<=n; ++i)
	{
		lef[a[i]] = min(lef[a[i]], i);
		rig[a[i]] = max(rig[a[i]], i);
	}
	
	static int f[MAXN], g[MAXN], cnt[MAXN];
	memset(cnt, 0, (dcnt+2)<<2);
	for(int i=1; i<=n; ++i)
	{
		f[i] = cnt[a[i] - 1];
		++cnt[a[i]];
	}
	
	int ans = *max_element(cnt+1,cnt+dcnt+1);
	memset(cnt, 0, (dcnt+2)<<2);
	for(int i=n; i>=1; --i)
	{
		g[i] = cnt[a[i] + 1];
		++cnt[a[i]];
		ans = max(ans, f[i] + cnt[a[i]]);
	}
	
	for(int i=1,j=1; i<=dcnt; i=j)
	{
		j = i+1;
		while(j<=dcnt && lef[j] > rig[j-1]) ++j;
		
		int cur = f[lef[i]] + g[rig[j-1]];
		for(int k=i; k<j; ++k) cur += cnt[k];
		ans = max(ans, cur);
	}
	
	printf("%d\n",n - ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}