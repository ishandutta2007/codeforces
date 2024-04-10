#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n;
	scanf("%d",&n);
	vector<ll> a(n);
	for(ll &x: a) cin >> x;
	
	ll sum = accumulate(a.begin(), a.end(), 0ll);
	printf("%d\n",sum % n == 0? 0: 1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}