#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

inline ll gcd(ll a,ll b){ return b? gcd(b,a%b): a;}
inline int get_sum(ll x)
{
	int res = 0;
	while(x) res += x%10, x/=10;
	return res;
}

void solve(void)
{
	ll x;
	scanf("%lld",&x);
	
	while(gcd(x, get_sum(x)) == 1) ++x;
	printf("%lld\n",x);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}