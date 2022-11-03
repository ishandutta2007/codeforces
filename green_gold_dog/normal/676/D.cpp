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

char get(char c, ll x) {
	if (c == 'L') {
		if (x == 0) {
			return 'L';
		}
		if (x == 1) {
			return 'U';
		}
		if (x == 2) {
			return 'R';
		}
		if (x == 3) {
			return 'D';
		}
	}
	if (c == 'U') {
		if (x == 0) {
			return 'U';
		}
		if (x == 1) {
			return 'R';
		}
		if (x == 2) {
			return 'D';
		}
		if (x == 3) {
			return 'L';
		}
	}
	if (c == 'R') {
		if (x == 0) {
			return 'R';
		}
		if (x == 1) {
			return 'D';
		}
		if (x == 2) {
			return 'L';
		}
		if (x == 3) {
			return 'U';
		}
	}
	if (c == 'D') {
		if (x == 0) {
			return 'D';
		}
		if (x == 1) {
			return 'L';
		}
		if (x == 2) {
			return 'U';
		}
		if (x == 3) {
			return 'R';
		}
	}
	if (c == '|') {
		if (x % 2 == 0) {
			return c;
		} else {
			return '-';
		}
	}
	if (c == '-') {
		if (x % 2 == 0) {
			return c;
		} else {
			return '|';
		}
	}
	if (c == '>') {
		if (x == 0) {
			return '>';
		}
		if (x == 1) {
			return 'v';
		}
		if (x == 2) {
			return '<';
		}
		if (x == 3) {
			return '^';
		}
	}
	if (c == 'v') {
		if (x == 0) {
			return 'v';
		}
		if (x == 1) {
			return '<';
		}
		if (x == 2) {
			return '^';
		}
		if (x == 3) {
			return '>';
		}
	}
	if (c == '<') {
		if (x == 0) {
			return '<';
		}
		if (x == 1) {
			return '^';
		}
		if (x == 2) {
			return '>';
		}
		if (x == 3) {
			return 'v';
		}
	}
	if (c == '^') {
		if (x == 0) {
			return '^';
		}
		if (x == 1) {
			return '>';
		}
		if (x == 2) {
			return 'v';
		}
		if (x == 3) {
			return '<';
		}
	}
	return c;
}

bool check(char c, ll x, ll nap) {
	c = get(c, x);
	if (c == '*') {
		return false;
	}
	if (c == '+') {
		return true;
	}
	if (nap == 0) {
		if (c == '|' || c == '^' || c == 'L' || c == 'D' || c == 'R') {
			return true;
		}
		return false;
	}
	if (nap == 1) {
		if (c == '-' || c == '>' || c == 'U' || c == 'D' || c == 'L') {
			return true;
		}
		return false;
	}
	if (nap == 2) {
		if (c == '|' || c == 'v' || c == 'L' || c == 'U' || c == 'R') {
			return true;
		}
		return false;
	}
	if (nap == 3) {
		if (c == '-' || c == '<' || c == 'R' || c == 'D' || c == 'U') {
			return true;
		}
		return false;
	}
	return true;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<char>> arr(n + 2, vector<char>(m + 2, '*'));
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	ll ys, xs, yf, xf;
	cin >> xs >> ys >> xf >> yf;
	vector<vector<vector<ll>>> dist(n + 2, vector<vector<ll>>(m + 2, vector<ll>(4, INF32)));
	dist[xs][ys][0] = 0;
	queue<tuple<ll, ll, ll>> q;
	q.push(make_tuple(xs, ys, 0));
	while (!q.empty()) {
		auto[x, y, p] = q.front();
		q.pop();
		if (assign_min(dist[x][y][(p + 1) % 4], dist[x][y][p] + 1)) {
			q.push(make_tuple(x, y, (p + 1) % 4));
		}
		if (check(arr[x][y], p, 0) && check(arr[x - 1][y], p, 2) && assign_min(dist[x - 1][y][p], dist[x][y][p] + 1)) {
			q.push(make_tuple(x - 1, y, p));
		}
		if (check(arr[x][y], p, 1) && check(arr[x][y + 1], p, 3) && assign_min(dist[x][y + 1][p], dist[x][y][p] + 1)) {
			q.push(make_tuple(x, y + 1, p));
		}
		if (check(arr[x][y], p, 2) && check(arr[x + 1][y], p, 0) && assign_min(dist[x + 1][y][p], dist[x][y][p] + 1)) {
			q.push(make_tuple(x + 1, y, p));
		}
		if (check(arr[x][y], p, 3) && check(arr[x][y - 1], p, 1) && assign_min(dist[x][y - 1][p], dist[x][y][p] + 1)) {
			q.push(make_tuple(x, y - 1, p));
		}
	}
	ll ans = min(min(dist[xf][yf][0], dist[xf][yf][1]), min(dist[xf][yf][2], dist[xf][yf][3]));
	cout << (ans == INF32 ? -1 : ans) << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}