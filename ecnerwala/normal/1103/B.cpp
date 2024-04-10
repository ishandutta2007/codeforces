#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const bool TEST = false;
ll TESTA;

bool query(ll x, ll y) {
	cout << '?' << ' ' << x << ' ' << y << endl << flush;
	if (TEST) {
		return (x % TESTA) < (y % TESTA);
	}
	string s; cin >> s;
	if (s == "x") return false;
	else if (s == "y") return true;
	else if (s == "e") exit(0);
	else assert(false);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (true) {
		string msg; cin >> msg;
		if (msg == "end") break;
		else if (msg == "mistake") break;
		else if (msg != "start") assert(false);

		if (TEST) {
			cin >> TESTA;
		}

		// we want to end with m
		ll mi = 1; // mi <= x
		while (true) {
			// x % a = mi-1, y - a <= x % a, so if y < a, we get true, and otherwise if y >= a, we get false
			if (query(mi - 1, mi * 2 - 1)) {
				mi = mi * 2;
			} else {
				break;
			}
		}
		// mi <= a < ma
		ll ma = mi * 2;
		while (ma - mi > 1) {
			ll md = (mi + ma) / 2;
			if (query(mi-1, md-1)) {
				mi = md;
			} else {
				ma = md;
			}
		}
		cout << '!' << ' ' << mi << endl << flush;
	}

	return 0;
}