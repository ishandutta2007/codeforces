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
mt19937 rnd32(rd() + 1);
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
	stack<ll> now;
	vector<char> arr;
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		char c;
		cin >> c;
		arr.push_back(c);
		if (c == '(') {
			now.push(i);
		} else {
			if (now.empty()) {
				sum += (i + 1) * (n - i);
			} else {
				ll x = now.top();
				now.pop();
				sum += (n - i) * (i - x) + (x + 1) * (i - x);
			}
		}
	}
	while (!now.empty()) {
		ll x = now.top();
		now.pop();
		sum += (x + 1) * (n - x);
	}
	ll absb = 0;
	map<ll, ll> otr, pol;
	ll m = 0;
	ll sotr = 0, spol = 0;
	ll cotr = 0, cpol = 1;
	pol[0]++;
	for (ll i = 0; i < n; i++) {
		if (arr[i] == '(') {
			pol[-m] += otr[-m];
			cpol += otr[-m];
			cotr -= otr[-m];
			otr[-m] = 0;
			m++;
			sotr += cotr;
			spol += cpol;
		} else {
			otr[-m] += pol[-m];
			cpol -= pol[-m];
			cotr += pol[-m];
			pol[-m] = 0;
			m--;
			sotr -= cotr;
			spol -= cpol;
		}
		pol[-m]++;
		cpol++;
		absb += spol - sotr;
	}
	cout << (sum - absb) / 2 + absb << '\n';
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