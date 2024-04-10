#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN];

void solve(void)
{
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	
	int ans = 0;
	for(int i=1; i<=n;)
	{
		int cnt = 1;
		while(i+cnt-1 <= n && (ll)a[i+cnt-1] * cnt < x)
			++cnt;
		
		if(i+cnt-1 > n) break;
		++ans;
		i += cnt;
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