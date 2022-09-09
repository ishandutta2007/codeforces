#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1,y; i<=n; ++i) scanf("%d",&y);
	
	sort(a+1,a+n+1);
	
	int ans = 0;
	
	int mx = 0;
	for(int i=1; i<=n; ++i)
	{
		int pos = upper_bound(a+i,a+n+1, a[i]+d) - a;
		ans = max(ans, mx + pos-i);
		
		pos = lower_bound(a+1,a+i, a[i]-d) - a;
		mx = max(mx, i - pos + 1);
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