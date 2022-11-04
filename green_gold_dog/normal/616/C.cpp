#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll dfs(ll x, ll y, vector<vector<ll>>& color, vector<vector<bool>>& arr, ll now_color) {
	color[x][y] = now_color;
	ll col = 0;
	for (ll i = -1; i <= 1; i++) {
		for (ll j = -1; j <= 1; j++) {
			if (abs(i) != abs(j)) {
				if (arr[x+i][y+j]) {
					if (color[x+i][y+j] == -1) {
						col += dfs(x+i, y+j, color, arr, now_color);
					}
				}
			}
		}
	}
	return col+1;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<vector<bool>> arr(n+2, vector<bool>(m+2, false));
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			char c;
			cin >> c;
			arr[i][j] = (c == '.');
		}
	}
	vector<vector<ll>> color(n+2, vector<ll>(m+2, -1));
	vector<ll> col;
	ll stc = 0;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (arr[i][j]) {
				if (color[i][j] == -1) {
					col.push_back(dfs(i, j, color, arr, stc));
					stc++;
				}
			}
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (arr[i][j]) {
				cout << '.';
			} else {
				set<ll> co;
				for (ll px = -1; px <= 1; px++) {
					for (ll py = -1; py <= 1; py++) {
						if (abs(px) != abs(py)) {
							if (arr[i+px][j+py]) {
								co.insert(color[i+px][j+py]);
							}
						}
					}
				}
				ll ans = 0;
				for (auto i : co) {
					ans += col[i];
				}
				cout << (ans+1)%10;
			}
		}
		cout << '\n';
	}
}