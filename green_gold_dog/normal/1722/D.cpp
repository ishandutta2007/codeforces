#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
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

void solve() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll na = 0;
	for (ll i = 0; i < n; i++) {
		if (s[i] == 'L') {
			na += i;
		} else {
			na += n - i - 1;
		}
	}
	ll num = 0;
	for (ll i = 0; i < n; i++) {
		while (num < (n - 1) / 2 && s[num] == 'R' && s[n - num - 1] == 'L') {
			num++;
		}
		if (s[num] == 'L') {
			na -= num;
			na += n - num - 1;
			s[num] = 'R';
		} else {
			if (s[n - num - 1] == 'R') {
				na -= num;
				na += n - num - 1;
				s[n - num - 1] = 'L';
			}
		}
		cout << na << ' ';
	}
	cout << '\n';
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