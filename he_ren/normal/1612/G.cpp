#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int MAXA = 1e6 + 5;
const int mod = 1e9 + 7;

ll fac[MAXN];

int a[MAXN];

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1] * i %mod;
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll sum = 0;
	static int cnt[MAXA];
	for(int i=1; i<=n; ++i) ++cnt[a[i]], sum += a[i];
	
	auto calc = [&] (ll l,ll r,ll len)
	{
		return ((l + r) * len / 2) %mod;
	};
	
	int ans1 = 0, ans2 = 1;
	for(int i=MAXA-1; i>=2; --i) if(cnt[i])
	{
		ans2 = ans2 * fac[cnt[i]] %mod * fac[cnt[i]] %mod;
		ans1 = (ans1 + (ll)(i - 1) * calc(sum - 1, sum - cnt[i] * 2 + 1, cnt[i])) %mod;
		
		sum -= cnt[i] * 2;
		cnt[i-2] += cnt[i]; cnt[i] = 0;
	}
	ans2 = ans2 * fac[cnt[1]] %mod;
	
	printf("%d %d",ans1,ans2);
	return 0;
}