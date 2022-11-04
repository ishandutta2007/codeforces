#include <bits/stdc++.h>
typedef int ll;

const ll INF = 1'000'000'000;

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

using namespace std;

int go[3];

void rec(ll x, ll y, vector<vector<ll>>& arr, deque<tuple<ll, ll, ll>>& ans, ll n, ll m) {
	arr[x][y] = 0;
	arr[x + 1][y] = 0;
	arr[x][y + 1] = 0;
	arr[x + 1][y + 1] = 0;
	go[0] = -1;
	go[1] = 0;
	go[2] = 1;
	for (auto px : go) {
		for (auto py : go) {
			if (x + px >= 0 && x + px < n - 1 && y + py >= 0 && y + py < m - 1) {
				set<ll> s;
				x += px;
				y += py;
				if (arr[x][y] != 0) {
					s.insert(arr[x][y]);
				}
				if (arr[x][y + 1] != 0) {
					s.insert(arr[x][y + 1]);
				}
				if (arr[x + 1][y] != 0) {
					s.insert(arr[x + 1][y]);
				}
				if (arr[x + 1][y + 1] != 0) {
					s.insert(arr[x + 1][y + 1]);
				}
				if (s.size() == 1) {
					ans.push_front(make_tuple(x, y, *s.begin()));
					s.clear();
					rec(x, y, arr, ans, n, m);
				}
				x -= px;
				y -= py;
			}
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> arr(n, vector<ll>(m, 0));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	deque<tuple<ll, ll, ll>> ans;
	vector<ll> x, y;
	for (ll i = 0; i < n - 1; i++) {
		for (ll j = 0; j < m - 1; j++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i + 1][j + 1]) {
				x.push_back(i);
				y.push_back(j);
			}
		}
	}
	if (x.size() == 0) {
		cout << -1;
		return 0;
	}
	for (ll i = 0; i < x.size(); i++) {
		if (arr[x[i]][y[i]] != 0) {
			ans.push_back(make_tuple(x[i], y[i], arr[x[i]][y[i]]));
			rec(x[i], y[i], arr, ans, n, m);
		}
	}
	for (auto i : arr) {
		for (auto j : i) {
			if (j != 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto[x, y, z] : ans) {
		cout << x + 1 << ' ' << y + 1 << ' ' << z << '\n';
	}
}
/*
















*/