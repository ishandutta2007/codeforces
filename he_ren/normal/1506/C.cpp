#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 20 + 5;
const int MAXM = 20 + 5;

char s[MAXN], t[MAXM];

void solve(void)
{
	scanf("%s%s",s+1,t+1);
	int n = strlen(s+1), m = strlen(t+1);
	
	int ans = n + m;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			for(int k=1; i+k-1 <= n && j+k-1 <= m && s[i+k-1] == t[j+k-1]; ++k)
				ans = min(ans, n - k + m - k);
	
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}