#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int n;
char s[MAXN];

int f[MAXN][2][2];

void gao(void)
{
	for(int i=2; i<=n; ++i)
	{
		f[i][0][1] = min(f[i-1][1][1], f[i-1][1][0]) + (s[i] != 'L');
		f[i][0][0] = f[i-1][0][1] + (s[i] != 'L');
		f[i][1][0] = min(f[i-1][0][0], f[i-1][0][1]) + (s[i] != 'R');
		f[i][1][1] = f[i-1][1][0] + (s[i] != 'R');
	}
}

void solve(void)
{
	scanf("%d%s",&n,s+1);
	
	int ans = inf;
	for(int i=0; i<=1; ++i)
	{
		f[1][0][i] = (s[1] != 'L');
		f[1][1][i] = inf;
		f[1][0][!i] = inf;
		f[1][1][!i] = inf;
		
		gao();
		
		if(i==0) ans = min(ans, f[n][i][1]);
		else ans = min(ans, min(f[n][i][0], f[n][i][1]));
		
		f[1][0][i] = inf;
		f[1][1][i] = (s[1] != 'R');
		f[1][0][!i] = inf;
		f[1][1][!i] = inf;
		
		gao();
		
		if(i==1) ans = min(ans, f[n][i][0]);
		else ans = min(ans, min(f[n][i][0], f[n][i][1]));
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