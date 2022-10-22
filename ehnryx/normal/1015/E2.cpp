#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Star {
	int x, y, d;
	Star(){}
	Star(int x, int y, int d): x(x), y(y), d(d) {}
	friend ostream& operator << (ostream& os, const Star& v) {
		return os << v.x << " " << v.y << " " << v.d;
	}
};

const int N = 1e3+1;
int dist[N][N][4], ans[N][N][2];
// right = 0

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	vector<Star> stars;
	string grid[n];
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '*') {
				for (int k = 0; k < 4; k++) {
					dist[i][j][k] = 1;
				}
			}
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (dist[i][j][1]) dist[i][j][1] += dist[i-1][j][1];
			if (dist[i][j][2]) dist[i][j][2] += dist[i][j-1][2];
		}
	}

	for (int i = n-2; i >= 0; i--) {
		for (int j = m-2; j >= 0; j--) {
			if (dist[i][j][0]) dist[i][j][0] += dist[i][j+1][0];
			if (dist[i][j][3]) dist[i][j][3] += dist[i+1][j][3];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int d = INF;
			for (int k = 0; k < 4; k++) {
				d = min(d, dist[i][j][k]);
			}
			if (d > 1) {
				stars.push_back(Star(i+1,j+1,d-1));
				ans[i][j][0] = ans[i][j][1] = d;
			}
		}
	}

	for (int i = 0; i+1 < n; i++) {
		for (int j = 0; j+1 < m; j++) {
			ans[i+1][j][0] = max(ans[i+1][j][0], ans[i][j][0] - 1);
			ans[i][j+1][1] = max(ans[i][j+1][1], ans[i][j][1] - 1);
		}
	}

	for (int i = n-1; i > 0; i--) {
		for (int j = m-1; j > 0; j--) {
			ans[i-1][j][0] = max(ans[i-1][j][0], ans[i][j][0] - 1);
			ans[i][j-1][1] = max(ans[i][j-1][1], ans[i][j][1] - 1);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((grid[i][j] == '*') != (ans[i][j][0] > 0 || ans[i][j][1] > 0)) {
				cout << -1 << nl;
				return 0;
			}
		}
	}

	cout << stars.size() << nl;
	for (const Star& star : stars) {
		cout << star << nl;
	}

	return 0;
}