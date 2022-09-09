#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int LB = 30 + 5;

int t[LB];

void solve(void)
{
	int n;
	scanf("%d",&n);
	memset(t,0,sizeof(t));
	for(int i=1; i<=n; ++i)
	{
		int a;
		scanf("%d",&a);
		int dig = 0;
		while(a>>dig) ++dig;
		++t[dig];
	}
	
	ll ans = 0;
	for(int i=0; i<LB; ++i)
		ans += (ll)t[i] * (t[i]-1) / 2;
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}