#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	vector<ll> a(n), b(n);
	ll gcd = 0;
	for(int i = 0; i < n; i++){
		cin>>a[i]>>b[i];
		gcd = __gcd(gcd, a[i]*b[i]);
	}
	if(gcd == 1){
		cout<<-1<<'\n';
		exit(0);
	}
	set<ll> st;
	{
		ll m = a[0];
		for(ll x = 2; x*x <= m; x++){
			if(m%x)continue;
			st.insert(x);
			while(m%x == 0){
				m /= x;
			}
		}
		if(m > 1)st.insert(m);
	}
	{
		ll m = b[0];
		for(ll x = 2; x*x <= m; x++){
			if(m%x)continue;
			st.insert(x);
			while(m%x == 0){
				m /= x;
			}
		}
		if(m > 1)st.insert(m);
	}
	for(auto x : st){
		if(gcd%x == 0){
			cout<<x;
			exit(0);
		}
	}
	assert(false);

	return 0;
}