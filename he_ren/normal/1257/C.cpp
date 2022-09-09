#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static int lst[MAXN];
	for(int i=1; i<=n; ++i) lst[i] = -1;
	
	int ans = inf;
	for(int i=1; i<=n; ++i)
	{
		if(lst[a[i]] != -1)
			ans = min(ans, i - lst[a[i]] + 1);
		lst[a[i]] = i;
	}
	
	if(ans == inf) printf("-1\n");
	else printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}