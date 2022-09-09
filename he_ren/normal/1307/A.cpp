#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e2 + 5;

int a[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int ans=a[1];
	for(int i=2; i<=n; ++i)
	{
		if(a[i]*(i-1) >= d)
		{
			ans += d/(i-1);
			break;
		}
		ans += a[i];
		d -= a[i]*(i-1);
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