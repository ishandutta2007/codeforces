#include<bits/stdc++.h>
#define x0 x000
#define y0 y000
#define x1 x111
#define y1 y111
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;

void solve(void)
{
	int n,m,x1,y1,x2,y2,a,b;
	scanf("%d%d%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2,&a,&b);
	
	int c = x2 - x1, d = y2 - y1;
	if(a + c > n && b + d > m)
	{
		printf("-1\n");
		return;
	}
	
	int ans = inf;
	if(a + c <= n)
	{
		ans = min(ans, max(a, x1) - x1);
		ans = min(ans, x2 - min(x2, n - a));
	}
	if(b + d <= m)
	{
		ans = min(ans, max(b, y1) - y1);
		ans = min(ans, y2 - min(y2, m - b));
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