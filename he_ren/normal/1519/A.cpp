#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	ll r,b,d;
	scanf("%lld%lld%lld",&r,&b,&d);
	
	if(r > b) swap(r, b);
	if(r * (d + 1) < b) printf("NO\n");
	else printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}