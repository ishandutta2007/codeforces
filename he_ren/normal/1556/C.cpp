#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

int c[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&c[i]);
	
	ll ans = 0;
	for(int i=1; i<=n; i+=2)
	{
		ll cur1 = c[i], cur2 = 0;
		for(int j=i+1; j<=n; ++j)
		{
			if(j&1){ cur2 += c[j]; continue;}
			if(c[j] <= cur2)
			{
				cur2 -= c[j];
				if(cur2 == 0 && cur1 < c[i]) ++ans;
				continue;
			}
			
			ll x = c[j] - cur2; cur2 = 0;
			if(x < c[j] && cur1 < c[i]) ++ans;
			ans += min(cur1, x);
			if(x > cur1) break;
			cur1 -= x;
		}
	}
	
	printf("%lld",ans);
	return 0;
}