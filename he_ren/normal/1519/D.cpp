#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e4 + 5;

int a[MAXN], b[MAXN];
ll pre[MAXN], suf[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i<<1]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i<<1]);
	n <<= 1;
	
	for(int i=1; i<=n; ++i) pre[i] = pre[i-1] + (ll)a[i] * b[i];
	for(int i=n; i>=1; --i) suf[i] = suf[i+1] + (ll)a[i] * b[i];
	
	ll ans = pre[n];
	for(int i=1; i<=n; ++i)
	{
		ll cur = -(ll)a[i] * b[i];
		for(int l=i, r=i; l>=1 && r<=n; --l, ++r)
		{
			cur += (ll)b[l] * a[r] + (ll)b[r] * a[l];
			ans = max(ans, cur + pre[l-1] + suf[r+1]);
		}
	}
	
	printf("%lld",ans);
	return 0;
}