#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

void solve(void)
{
	int n;
	static char s[MAXN];
	scanf("%d%s",&n,s+1);
	
	static int sum[MAXN];
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + s[i] - '0';
	
	map<int,int> t;
	t[0] = 1;
	
	ll ans = 0;
	for(int i=1; i<=n; ++i)
	{
		ans += t[i - sum[i]];
		++t[i - sum[i]];
	}
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}