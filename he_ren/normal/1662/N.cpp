#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1.5e3 + 5;

int a[MAXN][MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			scanf("%d",&a[i][j]);
	
	static int f[MAXN][MAXN], g[MAXN][MAXN];
	for(int i=1; i<=n; ++i)
	{
		static int id[MAXN];
		iota(id+1, id+n+1, 1);
		sort(id+1, id+n+1, [&] (int x,int y){
			return a[i][x] > a[i][y];
		});
		for(int j=1; j<=n; ++j)
			f[i][id[j]] = j-1;
		
		sort(id+1, id+n+1, [&] (int x,int y){
			return a[x][i] > a[y][i];
		});
		for(int j=1; j<=n; ++j)
			g[id[j]][i] = j-1;
	}
	
	ll tot = 0, ans = 0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
		{
			tot += (i-1) * (j-1);
			ans += f[i][j] * g[i][j];
		}
	ans = tot * 2 - ans;
	printf("%lld",ans);
	return 0;
}