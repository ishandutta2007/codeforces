#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll L, R, K;

int main() {
	cin >> L >> R >> K;
	if(K == 1) {
		cout << L << '\n';
		cout << 1 << '\n';
		cout << L << '\n';
		return 0;
	}

	if(K == 2) {
		if(R - L == 1) {
			if(L < (L ^ R)) {
				cout << L << '\n';
				cout << 1 << '\n';
				cout << L << '\n';
				return 0;
			} else {
				cout << (L ^ R) << '\n';
				cout << 2 << '\n';
				cout << L << ' ' << R << '\n';
				return 0;
			}
		} else {
			if(L % 2 != 0) L++;
			cout << 1 << '\n';
			cout << 2 << '\n';
			cout << L << ' ' << L + 1 << '\n';
			return 0;
		}
	}

	assert(R - L + 1 >= 3);

	//need sum 0
	
	if(K >= 4 && (R + 1) / 4 * 4 - 4 >= L) {
		cout << 0 << '\n';
		cout << 4 << '\n';
		L = (R + 1) / 4 * 4 - 4;
		cout << L << ' ' << L + 1 << ' ' << L + 2 << ' ' << L + 3 << '\n';
		return 0;
	} else if(K >= 4) {
		for(ll m = 1; m < (1 << (R - L + 1)); m++) {
			ll v = 0;
			ll c = 0;
			for(ll i = 0; i <= R - L; i++) {
				if(m & (1 << i)) {
					v ^= (L + i);
					c++;
				}
			}
			if(v == 0) {
				cout << 0 << '\n';
				cout << c << '\n';
				for(ll i = 0; i <= R - L; i++) {
					if(m & (1 << i)) {
						cout << L + i << ' ';
					}
				}
				cout << '\n';
				return 0;
			}
		}
		if(L % 2 != 0) L++;
		cout << 1 << '\n';
		cout << 2 << '\n';
		cout << L << ' ' << L + 1 << '\n';
		return 0;
	} else {
		assert(K == 3);
		for(ll i = 0; i < 50; i++) {
			if(3ll << i <= R && (2ll << i) - 1 >= L) {
				cout << 0 << '\n';
				cout << 3 << '\n';
				cout << (2ll << i) - 1 << ' ' << (3ll << i) - 1 << ' ' << (3ll << i) << '\n';
				return 0;
			}
		}
	}

	if(L % 2 != 0) L++;
	cout << 1 << '\n';
	cout << 2 << '\n';
	cout << L << ' ' << L + 1 << '\n';
	return 0;
}