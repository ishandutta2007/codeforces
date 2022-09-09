#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e3 + 5;
const int MAXM = 5e3 + 5;

int a[MAXN];

int f[MAXN][MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
	{
		static char s[100];
		scanf("%d%s",&a[i],s+1);
	}
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j)
			f[i][j] = f[i-1][j];
		
		f[i][a[i]] = f[i-1][a[i]] + 1;
		for(int j=a[i]; j<=m; ++j)
			f[i][j] = max(f[i][j], f[i][j-1]);
	}
	
	printf("%d",n - f[n][m]);
	return 0;
}