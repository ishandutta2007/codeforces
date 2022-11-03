#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
const db PI = acos(-1);
const bool IS_FILE = false, IS_TEST_CASES = false;

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
	vector<ll> all;
	for (ll i = 1; i <= n; i++) {
		all.push_back(i);
	}
	while (all.size() > 3) {
		vector<ll> f1, f2, s1, s2;
		ll col = all.size() / 4;
		for (ll i = 0; i < col; i++) {
			f1.push_back(all[i]);
		}
		for (ll i = col; i < col * 2; i++) {
			f2.push_back(all[i]);
		}
		for (ll i = col * 2; i < col * 3; i++) {
			s1.push_back(all[i]);
		}
		for (ll i = col * 3; i < all.size(); i++) {
			s2.push_back(all[i]);
		}
		cout << "? " << f1.size() + f2.size() << ' ';
		for (auto i : f1) {
			cout << i << ' ';
		}
		for (auto i : f2) {
			cout << i << ' ';
		}
		cout << endl;
		string s;
		cin >> s;
		vector<ll> nall;
		if (s == "NO") {
			cout << "? " << f1.size() << ' ';
			for (auto i : f1) {
				cout << i << ' ';
			}
			cout << endl;
			cin >> s;
			if (s == "NO") {
				for (auto i : f2) {
					nall.push_back(i);
				}
				for (auto i : s1) {
					nall.push_back(i);
				}
				for (auto i : s2) {
					nall.push_back(i);
				}
			} else {
				for (auto i : f1) {
					nall.push_back(i);
				}
				for (auto i : s1) {
					nall.push_back(i);
				}
				for (auto i : s2) {
					nall.push_back(i);
				}
			}
		} else {
			cout << "? " << s1.size() << ' ';
			for (auto i : s1) {
				cout << i << ' ';
			}
			cout << endl;
			cin >> s;
			if (s == "NO") {
				for (auto i : f1) {
					nall.push_back(i);
				}
				for (auto i : f2) {
					nall.push_back(i);
				}
				for (auto i : s2) {
					nall.push_back(i);
				}
			} else {
				for (auto i : f1) {
					nall.push_back(i);
				}
				for (auto i : f2) {
					nall.push_back(i);
				}
				for (auto i : s1) {
					nall.push_back(i);
				}
			}
		}
		all = nall;
	}
	if (all.size() == 1) {
		cout << "! " << all[0] << endl;
		return;
	}
	if (all.size() == 2) {
		cout << "! " << all[0] << endl;
		string s;
		cin >> s;
		if (s[1] == '(') {
			cout << "! " << all[1] << endl;
		}
		return;
	}
	cout << "? " << 1 << ' ' << all.back() << endl;
	string s;
	cin >> s;
	if (s == "NO") {
		cout << "? " << 1 << ' ' << all.back() << endl;
		cin >> s;
		if (s == "NO") {
			all.pop_back();
		}
	}
	if (all.size() == 2) {
		cout << "! " << all[0] << endl;
		string s;
		cin >> s;
		if (s[1] == '(') {
			cout << "! " << all[1] << endl;
		}
		return;
	}
	cout << "! " << all.back() << endl;
	cin >> s;
	if (s[1] == ')') {
		return;
	}
	all.pop_back();
	cout << "? " << 1 << ' ' << all[0] << endl;
	cin >> s;
	cout << "! " << (s == "YES" ? all[0] : all[1]) << endl;
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