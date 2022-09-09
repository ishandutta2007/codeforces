#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

ll gcd(ll a,ll b){ return b? gcd(b,a%b): a;}

ll a[MAXN];

void solve(void)
{
	int n;
	ll d;
	scanf("%d%lld",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	
	ll tmp = a[1];
	for(int i=1; i<=n; ++i) a[i] -= tmp;
	d -= tmp;
	
	ll g = 0;
	for(int i=1; i<=n; ++i) g = gcd(g, a[i]);
	
	if(d % g == 0) printf("YES\n");
	else printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}