#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

__int128 power(__int128 a, __int128 p, __int128 m = (ll)1e18) {
	if (p == 0) {
		return 1;
	}
	if (p % 2 == 0) {
		__int128 ans = power(a, p/2, m);
		return ans*ans%m;
	} else {
		return power(a, p-1, m)*a%m;
	}
}

ll gcd(ll a, ll b) {
	if (a == 0) {
		return b;
	}
	if (b == 0) {
		return a;
	}
	return gcd(min(a, b), max(a, b)%min(a, b));
}

ll gcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll d = gcd(b, a%b, x1, y1);
	x = y1;
	y = x1 - (a/b)*y1;
	return d;
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

ll sub(ll a, ll b, ll m) {
	if (a-b < 0) return a-b+m;
	return a-b;
}

ll sum(ll a, ll b, ll m) {
	if (a+b >= m) return a+b-m;
	return a+b;
}

bool is_prime(ll p) {
	for (ll i = 2; i*i <= p; i++) {
		if (p % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll iii = 0; iii < t; iii++) {
		ll n;
		cin >> n;
		ll n1 = n, n2 = n+1;
		while (!is_prime(n1)) {
			n1--;
		}
		while (!is_prime(n2)) {
			n2++;
		}
		if (n == 2) {
			cout << 1 << '/' << 6 << '\n';
		} else {
			if (n == 3) {
				cout << 7 << '/' << 30 << '\n';
			} else {
				if (n == 4) {
					cout << 3 << '/' << 10 << '\n';
				} else {
					cout << (n1*n2+(n-n1+1)*2-1*2*n2)/gcd(n1*n2+(n-n1+1)*2-1*2*n2, 2*n1*n2) << '/' << 2*n1*n2/gcd(n1*n2+(n-n1+1)*2-1*2*n2, 2*n1*n2) << '\n';
				}
			}
		}
	}
}