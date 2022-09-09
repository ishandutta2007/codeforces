#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

ll s[MAXN], dif[MAXN], sum[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%lld",&s[i]);
	
	sort(s+1,s+n+1);
	for(int i=1; i<n; ++i) dif[i] = s[i+1] - s[i];
	dif[n] = linf;
	sort(dif+1,dif+n+1);
	for(int i=1; i<=n; ++i) sum[i] = sum[i-1] + dif[i];
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		ll l,r;
		scanf("%lld%lld",&l,&r);
		ll len = r - l + 1;
		
		int pos = upper_bound(dif+1,dif+n+1,len) - dif - 1;
		printf("%lld ",sum[pos] + (ll)(n - pos) * len);
	}
	return 0;
}