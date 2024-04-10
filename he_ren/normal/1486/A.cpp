#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n;
	scanf("%d",&n);
	bool ok = 1;
	ll sum = 0;
	for(int i=0; i<n; ++i)
	{
		ll x;
		scanf("%lld",&x);
		if(!ok) continue;
		x += sum;
		if(x < i) ok = 0;
		else sum = x - i;
	}
	if(ok) printf("YES\n");
	else printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}