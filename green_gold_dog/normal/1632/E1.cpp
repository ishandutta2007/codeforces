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

ll bfs(vector<vector<ll>>& arr, ll to, ll tc) {
	ll n = arr.size();
	vector<ll> dist(n, INF32);
	dist[0] = 0;
	queue<ll> q;
	q.push(0);
	bool b = false;
	while (!q.empty()) {
		ll x = q.front();
		q.pop();
		if (dist[x] == tc && !b) {
			if (assign_min(dist[to], tc)) {
				q.push(to);
			}
			b = true;
		}
		for (auto y : arr[x]) {
			if (assign_min(dist[y], dist[x] + 1)) {
				q.push(y);
				if (dist[y] == tc && !b) {
					if (assign_min(dist[to], tc)) {
						q.push(to);
					}
					b = true;
				}
			}
		}
	}
	ll ans = 0;
	for (auto i : dist) {
		assign_max(ans, i);
	}
	return ans;
}

void solve() {
	ll n;
	cin >> n;
	vector<vector<ll>> arr(n);
	for (ll i = 1; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	vector<ll> dist(n, INF32), p(n, -1);
	dist[0] = 0;
	queue<ll> q;
	q.push(0);
	while (!q.empty()) {
		ll x = q.front();
		q.pop();
		for (auto i : arr[x]) {
			if (assign_min(dist[i], dist[x] + 1)) {
				p[i] = x;
				q.push(i);
			}
		}
	}
	ll md = 0, num = 0;
	for (ll i = 0; i < n; i++) {
		if (assign_max(md, dist[i])) {
			num = i;
		}
	}
	vector<ll> way;
	way.push_back(num);
	while (p[num] != -1) {
		num = p[num];
		way.push_back(num);
	}
	reverse(way.begin(), way.end());
	ll now = 0;
	while (now + 1 < way.size() && bfs(arr, way[now], 0) > bfs(arr, way[now + 1], 0)) {
		now++;
	}
	for (ll i = 1; i <= n; i++) {
		while (now + 1 < way.size() && bfs(arr, way[now], i) > bfs(arr, way[now + 1], i)) {
			now++;
		}
		cout << bfs(arr, way[now], i) << ' ';
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