#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e2 + 5;
const int MAXM = 5e2 + 5;

char s[MAXN][MAXM];
int sum[MAXN][MAXM];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			sum[i][j] = sum[i][j-1] + (s[i][j] != '*');
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			for(int k=0; i+k<=n && j-k>=1 && j+k<=m; ++k)
			{
				if(sum[i+k][j+k] - sum[i+k][j-k-1]) break;
				++ans;
			}
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