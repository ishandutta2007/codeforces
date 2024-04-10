#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 50 + 5;

int a[MAXN], b[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	int mna = a[1], mnb = b[1];
	for(int i=1; i<=n; ++i)
		mna = min(mna, a[i]),
		mnb = min(mnb, b[i]);
	
	ll ans = 0;
	for(int i=1; i<=n; ++i)
		ans += max(a[i]-mna, b[i]-mnb);
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}