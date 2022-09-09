#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll ans = 0;
	int cnt = 0;
	for(int i=1; i<=n; ++i)
	{
		int cur = min(cnt, a[i] / 2);
		ans += cur;
		cnt -= cur; a[i] -= cur * 2;
		ans += a[i] / 3; a[i] %= 3;
		cnt += a[i];
	}
	
	printf("%lld",ans);
	return 0;
}