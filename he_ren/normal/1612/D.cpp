#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll x;

bool dfs(ll a,ll b)
{
	if(a > b) swap(a, b);
	if(x > b) return 0;
	if(a == x || b == x || b-a == x) return 1;
	if(a == 0 || a == b) return 0;
	
	if(a && x <= b && b % a == x % a) return 1;
	a = b - a;
	if(a && x <= b && b % a == x % a) return 1;
	
	a = b - a;
	return dfs(b % a, a);
}

void solve(void)
{
	ll a,b;
	scanf("%lld%lld%lld",&a,&b,&x);
	if(dfs(a,b)) printf("YES\n");
	else printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}