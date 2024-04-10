#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

ll solve(){
	ll d, m;
	cin>>d>>m;
	ll ans = 1;
	ll cur = 1;
	while(d){
		ll tmp = min(d, cur);
		(ans *= (tmp + 1)) %= m;
		d -= tmp;
		cur <<= 1;
	}
	return (ans + m - 1) % m;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int t;
	cin>>t;
	while(t--)cout<<solve()<<'\n';

	return 0;
}