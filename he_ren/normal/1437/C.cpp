#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e2 + 5;
const int inf = 0x3f3f3f3f;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	
	static int f[MAXN][MAXN * 2];
	
	for(int i=0; i<=n; ++i)
		for(int j=0; j<=n*2; ++j)
			f[i][j] = inf;
	
	f[0][0] = 0;
	for(int i=1; i<=n; ++i)
		for(int j=i; j<=n*2; ++j)
		{
			for(int k=i-1; k<j; ++k)
				f[i][j] = min(f[i][j], f[i-1][k] + abs(a[i] - j));
		}
	
	int ans = inf;
	for(int i=1; i<=n*2; ++i)
		ans = min(ans, f[n][i]);
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}