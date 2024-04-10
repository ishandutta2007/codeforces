#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 50 + 5;

char s[MAXN][MAXN];
int a[MAXN][MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			a[i][j] = s[i][j] - '0';
	
	for(int i=1; i<n; ++i)
		for(int j=1; j<n; ++j)
		{
			if(!a[i][j]) continue;
			if(!a[i+1][j] && !a[i][j+1])
			{
				printf("NO\n");
				return;
			}
		}
	printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}