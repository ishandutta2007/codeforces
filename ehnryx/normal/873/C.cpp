#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	int grid[n][m];
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> grid[i][j];

	int score = 0;
	int ans = 0;
	for (int j = 0; j < m; j++) {
		int sum = 0;
		int curr = 0;
		int col = 0;
		int remove = 0;
		for (int i = 0; i < min(k, n); i++) {
			sum += grid[i][j];
		}
		col = sum;
		for (int i = k; i < n; i++) {
			sum += grid[i][j] - grid[i-k][j];
			curr += grid[i-k][j];
			if (sum > col) {
				col = sum;
				remove = curr;
			}
		}
		score += col;
		ans += remove;
	}

	cout << score << " " << ans << nl;

	return 0;
}