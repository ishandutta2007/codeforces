#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	ll s,n,d;
	scanf("%lld%lld%lld",&s,&n,&d);
	if(d == s){ printf("YES\n"); return;}
	if(d > s){ printf("NO\n"); return;}
	
	ll cnt = s / (2 * d) * d + min(d, s % (2 * d) + 1);
	
	if(n >= cnt) printf("YES\n");
	else printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}