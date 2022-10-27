#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void solve(){
	int n;
	cin>>n;
	vector<ll> a(n);
	for(auto &x : a){
		cin>>x;
	}
	ll ans = 0;
	for(int i = 1; i < n; i++){
		if(a[i] < a[i - 1])ans += a[i - 1] - a[i];
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int t;
	cin>>t;
	while(t--)solve();

	return 0;
}