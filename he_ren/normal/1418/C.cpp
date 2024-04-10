#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static int f[MAXN][2];
	f[0][0] = 0; f[0][1] = inf;
	
	for(int i=1; i<=n; ++i)
	{
		f[i][0] = i<2? f[i-1][1]: min(f[i-1][1], f[i-2][1]);
		f[i][1] = i<2? f[i-1][0] + a[i]: min(f[i-1][0] + a[i], f[i-2][0] + a[i] + a[i-1]);
	}
	
	printf("%d\n",min(f[n][0], f[n][1]));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}