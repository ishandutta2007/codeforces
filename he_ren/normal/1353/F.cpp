#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e2 + 5;
const int MAXM = 1e2 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

template<typename T>
inline void chk_min(T &a,T b){ if(a>b) a=b;}

ll a[MAXN][MAXM], b[MAXN][MAXM];
ll f[MAXN][MAXM];

void solve(void)
{	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			scanf("%lld",&a[i][j]);
	
	for(int i=1; i<=m; ++i) f[0][i] = linf;
	for(int i=1; i<=n; ++i) f[i][0] = linf;
	
	ll ans = linf;
	for(int x=1; x<=n; ++x)
		for(int y=1; y<=m; ++y)
		{	
			f[0][1] = 0;
			for(int i=1; i<=x; ++i)
				for(int j=1; j<=y; ++j)
				{
					b[i][j] = a[x][y] - ((x-i) + (y-j));
					if(a[i][j] < b[i][j]){ f[i][j]=linf; continue;}
					
					f[i][j] = min(f[i-1][j], f[i][j-1]);
					if(f[i][j] == linf) continue;
					
					f[i][j] += a[i][j] - b[i][j];
				}
			if(f[x][y] == linf) continue;
			
			for(int i=x; i<=n; ++i)
				for(int j=y; j<=m; ++j)
				{
					if(i==x && j==y) continue;
					
					b[i][j] = a[x][y] + ((i-x) + (j-y));
					if(a[i][j] < b[i][j]){ f[i][j]=linf; continue;}
					
					f[i][j] = linf;
					if(i>x) chk_min(f[i][j], f[i-1][j]);
					if(j>y) chk_min(f[i][j], f[i][j-1]);
					if(f[i][j] == linf) continue;
					
					f[i][j] += a[i][j] - b[i][j];
				}
			
			chk_min(ans, f[n][m]);
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