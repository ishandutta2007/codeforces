#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

const ll MOD1 = 1e9 + 123;
const ll MOD2 = 1e9 + 321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <vector <char>> c(n + 2, vector <char>(m + 2));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> c[i][j];
	vector <vector <bool>> from(n + 2, vector <bool>(m+2));
	from[n][m] = true;
	for (int i = n; i >= 1; i--) 
		for (int j = m; j >= 1; j--) {
			if (c[i][j] == '#') continue;
			if (i == n && j == m) continue;
			from[i][j] = (from[i][j + 1] || from[i + 1][j]);
		}
	vector <vector <pair <ll, ll>>> ans11(n + 2, vector <pair <ll, ll>>(m + 2));
	ans11[1][1] = { 1, 1 };
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) continue;
			if (!from[i][j]) continue;
			ans11[i][j].first = (ans11[i][j - 1].first + ans11[i - 1][j].first) % MOD1;
			ans11[i][j].second = (ans11[i][j - 1].second + ans11[i][j - 1].second) % MOD2;
		}
	if (!ans11[n][m].first && !ans11[n][m].second) {
		cout << 0;
		return 0;
	}
	vector <vector <pair <ll, ll>>> ansnm(n + 2, vector <pair <ll, ll>>(m + 2));
	ansnm[n][m] = { 1, 1 };
	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--) {
			if (i == n && j == m) continue;
			if (!ans11[i][j].first && !ans11[i][j].second) continue;
			ansnm[i][j].first = (ansnm[i][j + 1].first + ansnm[i + 1][j].first) % MOD1;
			ansnm[i][j].second = (ansnm[i][j + 1].second + ansnm[i][j + 1].second) % MOD2;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if ((i == 1 && j == 1) || (i == n && j == m)) continue;
			if (((ans11[i][j].first * ansnm[i][j].first) % MOD1 == ans11[n][m].first) &&
				((ans11[i][j].second * ansnm[i][j].second) % MOD2 == ans11[n][m].second)) {
				cout << 1;
				return 0;
			}
		}
	cout << 2;
	return 0;
}