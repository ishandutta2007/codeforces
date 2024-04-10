#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void solve(){
	ll x1, y1, x2, y2;
	cin>>x1>>y1>>x2>>y2;
	ll n = abs(x1 - x2);
	ll m = abs(y1 - y2);
	cout<<n*m + 1<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int t;
	cin>>t;
	while(t--)solve();

	return 0;
}