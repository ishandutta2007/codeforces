#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e3 + 5;
const int MAXM = 5e3 + 5;

char s[MAXN], t[MAXM];
int f[MAXN][MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d%s%s",&n,&m,s+1,t+1);
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			f[i][j] = max(f[i-1][j], f[i][j-1]) - 1;
			
			if(s[i] == t[j])
				f[i][j] = max(f[i][j], f[i-1][j-1] + 4 - 2);
			else
				f[i][j] = max(f[i][j], f[i-1][j-1] - 2);
			
			f[i][j] = max(f[i][j], 0);
			
			ans = max(ans, f[i][j]);
		}
	printf("%d",ans);
	return 0;
}