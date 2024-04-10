#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

const ll MAX_N = 1e5 + 1;

ll fact[MAX_N], fact_inv[MAX_N];

ll bin_pow(ll a, ll p) {
	if (!p) {
		return 1;
	}
	if (p & 1) {
		return a * bin_pow(a, p - 1) % MOD;
	}
	ll x = bin_pow(a, p / 2);
	return x * x % MOD;
}

ll inv(ll x) {
	return bin_pow(x, MOD - 2);
}

void init() {
	fact[0] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	fact_inv[MAX_N - 1] = inv(fact[MAX_N - 1]);
	for (int i = MAX_N - 2; i >= 0; --i) {
		fact_inv[i] = fact_inv[i + 1] * (i + 1) % MOD;
	}
}

ll cnk(ll k, ll n) {
	if (n < 0 || k < 0 || n - k < 0) {
		return 0;
	}
	return fact[n] * fact_inv[k] % MOD * fact_inv[n - k] % MOD;
}

int main() {
	init();
	int left_b = 0, left_w = 0, left_q = 0;
	int right_b = 0, right_w = 0, right_q = 0;
	int n;
	cin >> n;
	map<string, int> kek;
	for (int i = 0; i < n; ++i) {
		char ch1, ch2;
		cin >> ch1 >> ch2;
		if (ch1 == 'B') {
			left_b++;
		} else if (ch1 == 'W') {
			left_w++;
		} else {
			left_q++;
		}
		if (ch2 == 'B') {
			right_b++;
		} else if (ch2 == 'W') {
			right_w++;
		} else {
			right_q++;
		}
		string str;
		str += ch1;
		str += ch2;
		kek[str]++;
	}
	ll ans = 0;
	map<pair<int, int>, ll> left_arr;
	for (int i = 0; i <= left_q; ++i) {
		left_arr[{i + left_b, (left_q - i) + left_w}] = cnk(i, left_q);
	}
	for (int i = 0; i <= right_q; ++i) {
		int this_right_b = i + right_b;
		int this_right_w = (right_q - i) + right_w;
		ll vars = cnk(i, right_q);
		ans += left_arr[{this_right_w, this_right_b}] * vars;
		ans %= MOD;
	}
	if (kek["WW"] == 0 && kek["BB"] == 0) {
		int bw = kek["BW"] + kek["?W"] + kek["B?"];
		int wb = kek["WB"] = kek["?B"] + kek["W?"];
		for (int i = 0; i <= kek["??"]; ++i) {
			int x = bw + i;
			int y = wb + (kek["??"] - i);
			if (x && y) {
				ans -= cnk(i, kek["??"]);
			}
		}
	}
	while (ans < 0) {
		ans += MOD;
	}
	cout << ans;
	return 0;
}