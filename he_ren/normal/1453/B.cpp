#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int n;
int a[MAXN];

inline int calc(int pos){ return pos == 1 || pos > n? 0: abs(a[pos] - a[pos-1]);}

void solve(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll sum = 0;
	for(int i=1; i<=n; ++i) sum += calc(i);
	
	ll ans = sum;
	for(int i=1; i<=n; ++i)
	{
		ll tmp = a[i];
		ll cur = sum - calc(i) - calc(i+1);
		a[i] = a[i-1];
		ans = min(ans, cur + calc(i) + calc(i+1));
		a[i] = a[i+1];
		ans = min(ans, cur + calc(i) + calc(i+1));
		a[i] = tmp;
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