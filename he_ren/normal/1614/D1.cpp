#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int maxa = 5e6;
const int MAXA = maxa + 5;

int a[MAXN];

int cnt[MAXA], tot[MAXA];
ll f[MAXA];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		++cnt[a[i]];
	
	ll ans = 0;
	for(int i=maxa; i>=1; --i)
	{
		for(int j=i; j<=maxa; j+=i)
			tot[i] += cnt[j];
		if(!tot[i]) continue;
		
		f[i] = (ll)tot[i] * i;
		for(int j=i+i; j<=maxa; j+=i)
			f[i] = max(f[i], f[j] + (ll)(tot[i] - tot[j]) * i);
		
		ans = max(ans, f[i]);
	}
	
	printf("%lld",ans);
	return 0;
}