#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

char s[MAXN];

int sum[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + s[i] - '0';
	
	ll ans = 0;
	for(int i=1; i<=n; ++i) if(s[i] == '1')
	{
		ll cur = 0;
		for(int j=i; j<=n; ++j)
		{
			cur = (cur<<1) + s[j]-'0';
			if(j-cur+1 < 1) break;
			if(sum[i-1] - sum[j-cur]) continue;
			++ans;
		}
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