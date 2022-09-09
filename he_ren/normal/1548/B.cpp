#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int LB = 18 + 2;

int lb[MAXN];

ll gcd(ll a,ll b){ return b? gcd(b,a%b): a;}

ll a[MAXN], b[MAXN][LB];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	
	for(int i=1; i<n; ++i) b[i][0] = abs(a[i+1] - a[i]);
	for(int j=1; j<=18; ++j)
		for(int i=1; i+(1<<j)-1 < n; ++i)
			b[i][j] = gcd(b[i][j-1], b[i+(1<<(j-1))][j-1]);
	
	int ans = 1;
	for(int i=1; i<n; ++i)
	{
		int cur = i;
		ll k = 0;
		for(int j=lb[n-i]; j>=0; --j)
			if(cur+(1<<j)-1 < n && gcd(k, b[cur][j]) != 1)
				k = gcd(k, b[cur][j]),
				cur += 1<<j;
		ans = max(ans, cur - i + 1);
	}
	printf("%d\n",ans);
}

int main(void)
{
	lb[0] = -1;
	for(int i=2; i<MAXN; ++i) lb[i] = lb[i>>1] + 1;
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}