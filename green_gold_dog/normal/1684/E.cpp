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
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	map<ll, ll> all;
	for (auto i : arr) {
		all[i]++;
	}
	multiset<pair<ll, ll>> ms;
	for (auto[a, b] : all) {
		for (ll i = 0; i < b; i++) {
			ms.insert(make_pair(b, -a));
		}
	}
	set<ll> nb;
	for (ll i = 0; i <= n; i++) {
		nb.insert(i);
	}
	for (auto i : arr) {
		nb.erase(i);
	}
	ll mb = 0;
	ll nk = k;
	for (auto i : nb) {
		if (nk == -1) {
			break;
		}
		mb = i;
		nk--;
	}
	if (nk > -1) {
		mb = n;
	}
	for (ll i = 0; i < mb; i++) {
		if (all[i] > 0) {
			for (ll _ = 0; _ < all[i]; _++) {
				ms.erase(ms.find(make_pair(all[i], -i)));
			}
			for (ll _ = 1; _ < all[i]; _++) {
				ms.insert(make_pair(INF64, -i));
			}
		}
	}
	while (!ms.empty() && k > 0) {
		auto[a, b] = *ms.begin();
		b = -b;
		ms.erase(ms.begin());
		all[b]--;
		all[*nb.begin()]++;
		nb.erase(nb.begin());
		if (all[b] == 0) {
			nb.insert(b);
		}
		k--;
	}
	ll ans = -*nb.begin();
	for (auto[a, b] : all) {
		if (b > 0) {
			ans++;
		}
	}
	cout << ans << '\n';
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