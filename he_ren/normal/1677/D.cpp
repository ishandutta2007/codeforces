#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int mod = 998244353;

int a[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	if(d) rotate(a+1, a+(n+1-d), a+n+1);
	
	ll ans = 1;
	for(int i=1; i<=n; ++i)
	{
		if(a[i] == -1)
			ans = ans * i %mod;
		else if(a[i] == 0)
			ans = ans * (min(i-1, d) + 1) %mod;
		else
		{
			if(a[i]+d > i-1){ ans = 0; break;}
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