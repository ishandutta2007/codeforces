#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 5;

char s[MAXN];
int sum[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + s[i] - '0';
	
	int ans = min(sum[n], n-sum[n]);
	for(int i=1; i<=n; ++i)
	{
		ans = min(ans, sum[i] + (n-i)-(sum[n]-sum[i]));
		ans = min(ans, i-sum[i] + sum[n]-sum[i]);
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