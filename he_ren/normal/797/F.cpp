#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e3 + 5;
const int MAXM = 5e3 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int a[MAXN];
pii b[MAXM];
ll dp[MAXM][MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=m; ++i) scanf("%d%d",&b[i].first,&b[i].second);
	
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for(int k=1; k<=m; ++k)
	{
		static ll pre[MAXN];
		for(int i=1; i<=n; ++i)
			pre[i] = pre[i-1] + abs(a[i] - b[k].first);
		
		static pair<ll,int> q[MAXN];
		int hd = 1, tl = 0;
		for(int i=0; i<=n; ++i)
		{
			while(hd <= tl && q[hd].second < i-b[k].second) ++hd;
			if(dp[k-1][i] < linf)
			{
				ll cur = dp[k-1][i] - pre[i];
				while(hd <= tl && q[tl].first >= cur) --tl;
				q[++tl] = {cur, i};
			}
			if(hd <= tl) dp[k][i] = q[hd].first + pre[i];
		}
	}
	
	if(dp[m][n] < linf)
		printf("%lld",dp[m][n]);
	else
		printf("-1");
	return 0;
}