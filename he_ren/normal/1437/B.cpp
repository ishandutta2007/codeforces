#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int n;
char s[MAXN];

int calc(void)
{
	int cnt = 0;
	for(int i=2; i<=n; ++i)
		if(s[i] == '0' && s[i-1] == '1')
			++cnt;
	return cnt;
}

void solve(void)
{
	scanf("%d%s",&n,s+1);
	
	int ans = n/2 - calc();
	reverse(s+1,s+n+1);
	ans = min(ans, n/2 - calc());
	
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}