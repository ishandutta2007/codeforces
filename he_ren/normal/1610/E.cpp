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
	
	int ans = 0;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && a[i] == a[j]) ++j;
		if(j > n) ans = max(ans, j-i);
		else
		{
			int x = a[i], y = a[j], cur = j - i + 1;
			while(1)
			{
				int nxt = lower_bound(a+1,a+n+1, 2 * y - x) - a;
				if(nxt > n) break;
				++cur; y = a[nxt];
			}
			ans = max(ans, cur);
		}
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