#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;

ll pw10[MAXN];

char s[MAXN];

ll pre[MAXN], sum[MAXN];

int main(void)
{
	pw10[0] = 1;
	for(int i=1; i<MAXN; ++i) pw10[i] = pw10[i-1] * 10 %mod;
	
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	for(int i=1; i<=n; ++i)
		pre[i] = (pre[i-1] * 10 + s[i] - '0') %mod;
	
	for(int i=1; i<=n; ++i)
		sum[i] = (sum[i-1] + pre[i]) %mod;
	
	ll ans = 0;
	
	ll cur = 0;
	for(int i=n+1; i>=1; --i)
	{
		ans = (ans + cur * (i-1)) %mod;
		if(i > 2) ans = (ans + sum[i-2] * pw10[n-i+1]) %mod;
		
		cur = (cur + pw10[n-i+1] * (s[i-1] - '0')) %mod;
	}
	
	printf("%lld",ans);
	return 0;
}