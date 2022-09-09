#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n;
	ll x,y;
	cin >> n >> x >> y;
	vector<ll> a(n);
	for(ll &t: a) cin >> t;
	
	for(ll &t: a) x ^= t;
	if(x%2 == y%2) printf("Alice\n");
	else printf("Bob\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}