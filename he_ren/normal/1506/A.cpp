#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,m;
	ll k;
	scanf("%d%d%lld",&n,&m,&k);
	
	int x = k % n, y = (k + n - 1) / n;
	if(!x) x = n;
	printf("%lld\n",(ll)(x - 1) * m + y);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}