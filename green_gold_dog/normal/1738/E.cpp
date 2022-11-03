#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 998244353;
const db PI = acos(-1);
const bool IS_FILE = false, IS_TEST_CASES = true;

random_device rd;
mt19937 rnd32(rd());
mt19937_64 rnd64(rd());

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
T square(T a) {
	return a * a;
}

template<>
struct std::hash<pair<ll, ll>> {
	ll operator() (pair<ll, ll> p) {
		return ((__int128)p.first * MOD + p.second) % INF64;
	}
};

ll bin_pow(ll x, ll y) {
	if (y == 0) {
		return 1;
	}
	if (y % 2 == 0) {
		return square(bin_pow(x, y / 2)) % MOD;
	} else {
		return bin_pow(x, y - 1) * x % MOD;
	}
}

ll inv(ll x) {
	return bin_pow(x, MOD - 2);
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n);
	ll me = 0;
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		assign_max(me, arr[i]);
	}
	vector<ll> f;
	f.push_back(1);
	for (ll i = 1; i <= n; i++) {
		f.push_back(f.back() * i % MOD);
	}
	ll col = 0;
	ll sumpref = arr[0], sumsuf = arr.back();
	ll u1 = 1, u2 = n - 2;
	ll ans = 1;
	while ((u1 - 1) < (u2 + 1)) {
		while (u1 <= u2 && sumpref != sumsuf) {
			while (u1 <= u2 && sumpref > sumsuf) {
				sumsuf += arr[u2];
				u2--;
			}
			while (u1 <= u2 && sumpref < sumsuf) {
				sumpref += arr[u1];
				u1++;
			}
		}
		if (sumsuf == sumpref) {
			ll colvf = 1, colvs = 1;
			while (u1 <= u2 && arr[u1] == 0) {
				colvf++;
				u1++;
			}
			if (u1 == u2 + 1) {
				ans = ans * bin_pow(2, colvf) % MOD;
				break;
			}
			while (arr[u2] == 0) {
				colvs++;
				u2--;
			}
			ll nans = 0;
			for (ll i = 0; i <= min(colvf, colvs); i++) {
				nans = (nans + ans * f[colvf] % MOD * inv(f[colvf - i]) % MOD * inv(f[i]) % MOD * f[colvs] % MOD * inv(f[colvs - i]) % MOD * inv(f[i]) % MOD) % MOD;
			}
			ans = nans;
		}
		sumpref += arr[u1];
		u1++;
	}
	cout << ans << '\n';
}

int main() {
	if (IS_FILE) {
		freopen("", "r", stdin);
		freopen("", "w", stdout);
	}
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	if (IS_TEST_CASES) {
		cin >> t;
	}
	for (ll i = 0; i < t; i++) {
		solve();
	}
}