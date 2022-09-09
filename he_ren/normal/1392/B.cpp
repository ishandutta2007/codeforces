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
	int n;
	ll d;
	scanf("%d%lld",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int mx = a[1], mn = a[1];
	for(int i=1; i<=n; ++i)
		mx = max(mx, a[i]),
		mn = min(mn, a[i]);
	
	if(d&1)
	{
		for(int i=1; i<=n; ++i)
			printf("%d ",mx-a[i]);
	}
	else
	{
		for(int i=1; i<=n; ++i)
			printf("%d ",a[i]-mn);
	}
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}