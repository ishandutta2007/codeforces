#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

int a[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	int ans = 0;
	for(int i=1,j=1; i<=n; ++i, ++j)
	{
		while(j<=n && a[j]-a[i] < d) ++j;
		if(j>n) break;
		
		++ans;
		if(ans == n/2) break;
	}
	printf("%d",ans);
}

int main(void)
{
	int T=1;
	while(T--) solve();
	return 0;
}