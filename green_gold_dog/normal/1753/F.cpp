#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

constexpr ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007, SB = 1000, CB = 1001;
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

struct block {
	ll col[SB];
	ll cz;
	block() {
		for (ll i = 0; i < SB; i++) {
			col[i] = 0;
		}
		cz = SB;
	}
	ll get() {
		if (cz == 0) {
			return -1;
		}
		for (ll i = 0;; i++) {
			if (col[i] == 0) {
				return i;
			}
		}
	}
	void insert(ll x) {
		cz -= col[x] == 0;
		col[x]++;
	}
	void erase(ll x) {
		col[x]--;
		cz += col[x] == 0;
	}
	void clear() {
		if (cz == SB) {
			return;
		}
		for (ll i = 0; i < SB; i++) {
			col[i] = 0;
		}
		cz = SB;
	}
};

struct MEX {
	block arr[CB];
	void insert(ll x) {
		if (x / SB >= CB) {
			return;
		}
		arr[x / SB].insert(x % SB);
	}
	void erase(ll x) {
		if (x / SB >= CB) {
			return;
		}
		arr[x / SB].erase(x % SB);
	}
	ll get() {
		ll i = 0;
		ll x = 0;
		while ((x = arr[i].get()) == -1) {
			i++;
		}
		return x + i * SB;
	}
	void clear() {
		for (ll i = 0; i < CB; i++) {
			arr[i].clear();
		}
	}
};

struct MEXpm {
	MEX p, m;
	MEXpm() {
		p.insert(0);
		m.insert(0);
	}
	ll get() {
		return p.get() + m.get() - 1;
	}
	void insert(vector<ll>& arr) {
		for (auto i : arr) {
			insert(i);
		}
	}
	void erase(vector<ll>& arr) {
		for (auto i : arr) {
			erase(i);
		}
	}
	void insert(ll x) {
		if (x < 0) {
			m.insert(-x);
		} else {
			p.insert(x);
		}
	}
	void erase(ll x) {
		if (x < 0) {
			m.erase(-x);
		} else {
			p.erase(x);
		}
	}
	void clear() {
		m.clear();
		p.clear();
		m.insert(0);
		p.insert(0);
	}
};

void next(ll &x, ll &y) {
	if (x == 0) {
		y++;
		return;
	}
	x--;
}

void solve() {
	ll n, m, k, t;
	cin >> n >> m >> k >> t;
	vector<vector<vector<ll>>> arr(n, vector<vector<ll>>(m));
	for (ll i = 0; i < k; i++) {
		ll x, y, w;
		cin >> x >> y >> w;
		x--;
		y--;
		arr[x][y].push_back(w);
	}
	ll nx = n - 1, ny = 0;
	MEXpm mex;
	ll ans = 0;
	while (ny < m) {
		ll fx = nx, fy = ny, sx = nx + 1, sy = ny + 1;
		mex.insert(arr[fx][fy]);
		while (fx < n && fy < m) {
			while ((mex.get() < t && sx < n && sy < m) || (fx == sx && fy == fx)) {
				for (ll i = fx; i <= sx; i++) {
					mex.insert(arr[i][sy]);
				}
				for (ll i = fy; i < sy; i++) {
					mex.insert(arr[sx][i]);
				}
				sx++;
				sy++;
			}
			if (mex.get() < t) {
				break;
			}
			ans += min(n - sx + 1, m - sy + 1);
			for (ll i = fx; i < sx; i++) {
				mex.erase(arr[i][fy]);
			}
			for (ll i = fy + 1; i < sy; i++) {
				mex.erase(arr[fx][i]);
			}
			fx++;
			fy++;
		}
		mex.clear();
		next(nx, ny);
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