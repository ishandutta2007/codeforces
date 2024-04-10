#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll pow2[26] = {
0, // 0 0
0, // 1 1
1, // 2 3
1, // 3 7
5, // 4 15
1, // 5 31
21, // 6 63
1, // 7 127
85, // 8 255
73, // 9 511
341, // 10 1023
89, // 11 2047
1365, // 12 4095
1, // 13 8191
5461, // 14 16383
4681, // 15 32767
21845, // 16 65535
1, // 17 131071
87381, // 18 262143
1, // 19 524287
349525, // 20 1048575
299593, // 21 2097151
1398101, // 22 4194303
178481, // 23 8388607
5592405, // 24 16777215
1082401, // 25 33554431
};

ll slow(ll a) {
	ll r = 0;
	for (ll b = 1; b < a; b++) {
		r = max(r, __gcd(a^b, a&b));
	}
	return r;
}

void gen() {
	for (int i = 0; i <= 25; i++) {
		ll n = (1ll << i) - 1;
		cerr << slow(n) << ", // " << i << ' ' << n << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//gen();
	int Q; cin >> Q;
	while (Q--) {
		ll A; cin >> A;
		int l2 = 0;
		while ((1ll << l2) <= A) l2++;
		if (A == (1ll << l2) - 1) {
			cout << pow2[l2] << '\n';
		} else {
			cout << (1ll << l2) - 1 << '\n';
		}
	}

	return 0;
}