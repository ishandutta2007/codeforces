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
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	string s;
	cin >> s;
	ll r = 0;
	deque<ll> ab, ba;
	string now;
	now.push_back(s[0]);
	a -= s[0] == 'A';
	b -= s[0] == 'B';
	s.erase(s.begin());
	s.push_back('#');
	for (auto i : s) {
		a -= i == 'A';
		b -= i == 'B';
		if (i == now.back() || i == '#') {
			if (now.size() % 2 == 1) {
				r += now.size() / 2;
			} else {
				if (now[0] == 'A') {
					ab.push_back(now.size() / 2);
				} else {
					ba.push_back(now.size() / 2);
				}
			}
			now.clear();
		}
		now.push_back(i);
	}
	sort(ab.begin(), ab.end());
	sort(ba.begin(), ba.end());
	a += c + d;
	b += c + d;
	while (c != 0 && ab.size() != 0) {
		if (c >= ab.front()) {
			c -= ab.front();
			ab.pop_front();
		} else {
			ab.front() -= c;
			c = 0;
		}
	}
	while (d != 0 && ba.size() != 0) {
		if (d >= ba.front()) {
			d -= ba.front();
			ba.pop_front();
		} else {
			ba.front() -= d;
			d = 0;
		}
	}
	if (c >= r) {
		c -= r;
		r = 0;
	} else {
		r -= c;
		c = 0;
	}
	if (d >= r) {
		d -= r;
		r = 0;
	} else {
		r -= d;
		d = 0;
	}
	while (c != 0 && ba.size() != 0) {
		if (c >= ba.front() - 1) {
			c -= ba.front() - 1;
			ba.pop_front();
		} else {
			ba.front() -= c + 1;
			c = 0;
		}
	}
	while (d != 0 && !ab.empty()) {
		if (d >= ab.front() - 1) {
			d -= ab.front() - 1;
			ab.pop_front();
		} else {
			ab.front() -= d + 1;
			d = 0;
		}
	}
	if (d != 0 || c != 0 || a != 0 || b != 0) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
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