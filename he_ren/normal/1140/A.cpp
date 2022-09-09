#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e4 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	int ans = 0;
	int mx = -1;
	for(int i=1; i<=n; ++i)
	{
		mx = max(mx, a[i]);
		if(mx <= i)
		{
			++ans;
			mx = -1;
		}
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T=1;
	while(T--) solve();
	return 0;
}