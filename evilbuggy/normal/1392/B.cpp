#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void solve(){
	int n; ll k;
	cin>>n>>k;
	vector<ll> a(n);
	for(auto &x : a){
		cin>>x;
	}
	ll mx = *max_element(a.begin(), a.end());
	ll mn = *min_element(a.begin(), a.end());
	if(k&1){
		for(auto x : a){
			cout<<mx - x<<" ";
		}
	}else{
		for(auto x : a){
			cout<<x - mn<<" ";
		}
	}
	cout<<'\n';
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