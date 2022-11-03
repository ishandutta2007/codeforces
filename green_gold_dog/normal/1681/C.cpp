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
	vector<pair<pair<ll, ll>, ll>> arr(n);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first.first;
	}
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first.second;
		arr[i].second = i;
	}
	vector<ll> nn(n), sa(n);
	for (ll i = 0; i < n; i++) {
		nn[i] = i;
		sa[i] = i;
	}
	sort(arr.begin(), arr.end());
	for (ll i = 1; i < n; i++) {
		if (arr[i].first.first < arr[i - 1].first.first) {
			cout << -1 << '\n';
			return;
		}
		if (arr[i].first.second < arr[i - 1].first.second) {
			cout << -1 << '\n';
			return;
		}
	}
	vector<pair<ll, ll>> ans;
	for (ll i = 0; i < n; i++) {
		arr[i].second = nn[arr[i].second];
		if (i != arr[i].second) {
			ans.push_back(make_pair(i, arr[i].second));
			swap(sa[arr[i].second], sa[i]);
			swap(nn[sa[arr[i].second]], nn[sa[i]]);
		}
	}
	cout << ans.size() << '\n';
	for (auto[a, b] : ans) {
		cout << a + 1 << ' ' << b + 1 << '\n';
	}
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