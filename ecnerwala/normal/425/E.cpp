#include<iostream>
#include<cstring>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll PHI = MOD - 1;

ll exp(ll a, ll b) {
	b %= PHI;
	if(b < 0) b += PHI;
	ll res = 1;
	while(b) {
		if(b % 2) res *= a, res %= MOD;

		b /= 2;
		a *= a, a %= MOD;
	}
	return res;
}

const int MAXN = 1e3;
const int MAXK = 1e3;

ll precomp[MAXN];
ll exp2[MAXN];
ll res[MAXN];

int N, K;
//ll dp[MAXN][MAXK];

ll c2(ll a) {
	return a * (a - 1) / 2;
}

void multRes() {
	for(int i = N; i >= 0; i--) {
		res[i] = 0;
		for(int j = 0; j < i; j++) {
			res[i] += res[j] * exp2[i - j];
			res[i] %= MOD;
		}
	}
}

void multExp() {

	for(int i = N; i >= 0; i--) {
		exp2[i] = 0;
		for(int j = 1; j < i; j++) {
			exp2[i] += exp2[j] * exp2[i - j];
			exp2[i] %= MOD;
		}
	}
}

ll go() {
	for(int i = 0; i <= N; i++) {
		precomp[i] = (exp(2, i) - 1) * exp(2, -c2(i + 1)) % MOD;
	}

	memcpy(exp2, precomp, sizeof(precomp));

	memset(res, 0, sizeof(res));
	res[0] = 1;
	/*
	for(int k = K; k; k /= 2) {
		if(k % 2) {
			multRes();
		}
		multExp();
	}
	*/
	for(int k = 0; k < K; k++) multRes();

	ll v = 0;
	for(int i = 0; i <= N; i++) {
		v += res[i];
		if(v >= MOD) v -= MOD;
	}
	memcpy(exp2, precomp, sizeof(precomp));
	multRes();
	for(int i = 0; i <= N; i++) {
		v -= res[i];
		if(v < 0) v += MOD;
	}
	v *= exp(2, c2(N + 1));
	v %= MOD;
	return v;
}

int main() {
	cin >> N >> K;
	cout << go() << '\n';
	return 0;
}