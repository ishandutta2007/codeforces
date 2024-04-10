#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;

inline ll gcd(ll a,ll b){ return b? gcd(b,a%b): a;}

ll a[MAXN], b[MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	for(int i=1; i<=m; ++i) scanf("%lld",&b[i]);
	
	if(n == 1)
	{
		for(int i=1; i<=m; ++i) printf("%lld ",b[i] + a[1]);
		return 0;
	}
	
	sort(a+1,a+n+1);
	for(int i=n; i>=1; --i) a[i] -= a[i-1];
	ll t = a[2];
	for(int i=2; i<=n; ++i) t = gcd(t, a[i]);
	
	for(int i=1; i<=m; ++i)
		printf("%lld ",gcd(t, b[i] + a[1]));
	return 0;
}