#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

ll getA(ll n){
	ll m = 1;
	while(m < n){
		n -= m;
		m <<= 2;
	}
	return m + n - 1;
}

ll getB(ll n){
	ll m = 1;
	while(m < n){
		n -= m;
		m <<= 2;
	}
	n--;
	ll ret = 0;
	int ind = 0;
	while(m > 1){
		if(n%4 == 1)ret ^= (2LL<<ind);
		else if(n%4 == 2)ret ^= (3LL<<ind);
		else if(n%4 == 3)ret ^= (1LL<<ind);
		ind += 2;
		n >>= 2;
		m >>= 2;
	}
	ret ^= (2LL<<ind);
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll a = getA((n + 2)/3);
		ll b = getB((n + 2)/3);
		ll c = a^b;
		if(n%3 == 1)cout<<a<<'\n';
		else if(n%3 == 2)cout<<b<<'\n';
		else cout<<c<<'\n';
	}

	return 0;
}