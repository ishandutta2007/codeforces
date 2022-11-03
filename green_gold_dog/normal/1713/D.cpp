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
	vector<ll> arr;
	for (ll i = 0; i < (1 << n); i++) {
		arr.push_back(i + 1);
	}
	while (arr.size() > 1) {
		if (arr.size() == 2) {
			cout << "? " << arr[0] << ' ' << arr[1] << endl;
			ll x;
			cin >> x;
			if (x == 2) {
				swap(arr[0], arr[1]);
			}
			arr.resize(1);
			break;
		}
		vector<ll> na;
		for (ll i = 0; i < arr.size() / 4; i++) {
			cout << "? " << arr[i * 4] << ' ' << arr[i * 4 + 2] << endl;
			ll x;
			cin >> x;
			if (x == 0) {
				cout << "? " << arr[i * 4 + 1] << ' ' << arr[i * 4 + 3] << endl;
				cin >> x;
				if (x == 1) {
					na.push_back(arr[i * 4 + 1]);
				} else {
					na.push_back(arr[i * 4 + 3]);
				}
			} else {
				if (x == 2) {
					swap(arr[i * 4], arr[i * 4 + 2]);
					swap(arr[i * 4 + 1], arr[i * 4 + 3]);
				}
				cout << "? " << arr[i * 4] << ' ' << arr[i * 4 + 3] << endl;
				cin >> x;
				if (x == 1) {
					na.push_back(arr[i * 4]);
				} else {
					na.push_back(arr[i * 4 + 3]);
				}
			}
		}
		arr = na;
	}
	cout << "! " << arr[0] << endl;
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