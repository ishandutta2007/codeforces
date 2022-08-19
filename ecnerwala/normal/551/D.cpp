#include<bits/stdc++.h>
using namespace std;

// 1, 1 ^n = F[n + 1] F[n]
// 1, 0      F[n] F[n - 1]
//
// dp[i] = F[i+1]

typedef long long ll;
ll M;

ll N;
ll K;
ll L;

ll dsum(ll v) {
	return v ? 1 + dsum(v & (v - 1)) : 0;
}

ll exp(ll a, ll b) {
	a %= M;
	ll r = 1;
	while(b) {
		if(b % 2) r *= a, r %= M;
		a *= a, a %= M;
		b /= 2;
	}
	return r % M;
}

ll res[2][2];

ll trans[2][2];

ll tmp[2][2];
void mult(ll a[2][2], ll b[2][2]) {
	tmp[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % M;
	tmp[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % M;
	tmp[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % M;
	tmp[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % M;

	a[0][0] = tmp[0][0];
	a[1][0] = tmp[1][0];
	a[0][1] = tmp[0][1];
	a[1][1] = tmp[1][1];
}

ll dp(ll n) {
	res[0][0] = res[1][1] = 1;
	res[0][1] = res[1][0] = 0;

	trans[0][0] = trans[0][1] = trans[1][0] = 1;
	trans[1][1] = 0;

	n++;
	while(n) {
		if(n % 2) {
			mult(res, trans);
		}
		mult(trans, trans);
		n /= 2;
	}

	return res[0][0] % M;
}

int main() {
	cin >> N >> K >> L >> M;
	if(M == 1) {
		cout << 0 << '\n';
		return 0;
	}

	ll way0 = dp(N);
	ll way1 = (exp(2, N) - way0 + M) % M;

	if(L <= 62 && (1ll << L) <= K) {
		cout << 0 << '\n';
		return 0;
	}

	ll num1 = dsum(K);
	ll num0 = L - dsum(K);

	//cerr << way0 << ' ' << num0 << '\n';
	//cerr << way1 << ' ' << num1 << '\n';

	ll v = exp(way0, num0) * exp(way1, num1) % M;

	cout << v % M << '\n';
	return 0;
}