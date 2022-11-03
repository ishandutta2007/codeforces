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
	vector<pair<ll, ll>> arr(n);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	vector<vector<ll>> all(n);
	vector<ll> color(n);
	for (ll i = 0; i < n; i++) {
		color[i] = i;
		all[i].push_back(i);
	}
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());
	vector<ll> sum(n);
	for (ll i = 0; i < n; i++) {
		sum[arr[i].second] = arr[i].first;
	}
	ll ost = n;
	for (ll j = 0; j < n; j++) {
		for (ll i = 0; i < n; i++) {
			while (sum[color[arr[i].second]] > square((ll)all[color[arr[i].second]].size()) && arr[i].first > 0 && ost > 0) {
				cout << "? " << arr[i].second + 1 << endl;
				ll x;
				ost--;
				cin >> x;
				x--;
				if (color[arr[i].second] != color[x]) {
					ll o = arr[i].second;
					if (all[color[arr[i].second]].size() < all[color[x]].size()) {
						swap(x, arr[i].second);
					}
					sum[color[arr[i].second]] += sum[color[x]];
					for (auto j : all[color[x]]) {
						all[color[arr[i].second]].push_back(j);
						color[j] = color[arr[i].second];
					}
					arr[i].second = o;
				}
				arr[i].first--;
			}
		}
	}
	cout << "! ";
	for (auto i : color) {
		cout << i + 1 << ' ';
	}
	cout << endl;
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