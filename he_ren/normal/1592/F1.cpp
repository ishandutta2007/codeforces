#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e2 + 5;
const int MAXM = 5e2 + 5;

char s[MAXN][MAXM];
int a[MAXN][MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			a[i][j] = s[n-i+1][m-j+1] == 'B';
	
	for(int i=n; i>=1; --i)
		for(int j=m; j>=1; --j)
			a[i][j] ^= a[i-1][j] ^ a[i][j-1] ^ a[i-1][j-1];
	
	int sum = 0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			sum += a[i][j];
	
	int ans = sum;
	for(int i=1; i<n; ++i)
		for(int j=1; j<m; ++j)
		{
			int cur = sum;
			cur += 4 - 2 * (a[1][1] + a[i+1][1] + a[1][j+1] + a[i+1][j+1]);
			cur += 3;
			ans = min(ans, cur);
		}
	printf("%d\n",ans);
	return 0;
}