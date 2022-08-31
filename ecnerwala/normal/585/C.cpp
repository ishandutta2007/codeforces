#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll X, Y;

ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }

int main() {
	cin >> X >> Y;
	if(gcd(X, Y) != 1) {
		cout << "Impossible\n";
		return 0;
	}

	// alice: 1/0, bob: 0/1
	
	while(X != Y) {
		// letter a: bx/by -> mediant
		if(X > Y) {
			// do operation B
			ll n = X / Y;
			X %= Y;
			if(!X) n--, X = Y;
			cout << n << 'A';
		} else {
			ll n = Y / X;
			Y %= X;
			if(!Y) n--, Y = X;
			cout << n << 'B';
		}
	}
	cout << '\n';

	return 0;
}