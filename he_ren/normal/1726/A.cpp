#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e3 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	if(n == 1)
	{
		printf("0\n");
		return;
	}
	
	int ans = max(*max_element(a+2,a+n+1) - a[1], a[n] - *min_element(a+1,a+n));
	for(int i=1; i<=n; ++i)
		ans = max(ans, a[(i + n - 1 - 1) % n + 1] - a[i]);
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}