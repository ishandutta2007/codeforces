#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { if(!a) return b; return gcd(b % a, a); }

bool go() {
	ll p, q; cin >> p >> q;
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		if(!q) return false;
		ll a; cin >> a;
		if(p / q < a) return false;
		p -= a * q;
		swap(p, q);
	}
	return q == 0;
}

int main() {
	if(go()) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}