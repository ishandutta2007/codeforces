#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
const db PI = acos(-1);

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

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
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (n % 2 == 1) {
		cout << "NO\n";
		return;
	}
	sort(arr.begin(), arr.end());
	vector<ll> ans(n, 0);
	for (ll i = 0; i < n / 2; i++) {
		ans[i * 2] = arr[i];
	}
	for (ll i = n / 2; i < n; i++) {
		ans[(i - n / 2) * 2 + 1] = arr[i];
	}
	bool b = false;
	for (ll i = 1; i < n - 1; i++) {
		if ((ans[i] > ans[i - 1] && ans[i] > ans[i + 1]) || (ans[i] < ans[i - 1] && ans[i] < ans[i + 1])) {
		} else {
			b = true;
			break;
		}
	}
	if ((ans[0] > ans.back() && ans[0] > ans[1]) || (ans[0] < ans.back() && ans[0] < ans[1])) {
	} else {
		b = true;
	}
	if ((ans[n - 1] > ans[0] && ans[n - 1] > ans[n - 2]) || (ans[n - 1] < ans[0] && ans[n - 1] < ans[n - 2])) {
	} else {
		b = true;
	}
	if (b) {
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}