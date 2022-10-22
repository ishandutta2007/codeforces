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

vector<int> dx = { -1, 1, 0, 0 };
vector<int> dy = { 0, 0, -1, 1 };

struct Node {
	int i, j;
};

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, m, p;
	cin >> n >> m >> p;

	int s[p];
	for (int i=0; i<p; i++) {
		cin >> s[i];
	}

	int dist[n][m];
	memset(dist, INF, sizeof dist);

	queue<Node> bfs[p];
	string grid[n];
	for (int i=0; i<n; i++) {
		cin >> grid[i];
		for (int j=0; j<m; j++) {
			for (int k=0; k<p; k++) {
				if (grid[i][j]-'0' == k+1) {
					bfs[k].push({i,j});
					dist[i][j] = 0;
					grid[i][j] -= 1;
				}
			}
		}
	}

	const int T = 1e6+1;
	for (int t=0; t<T*p; t++) {
		int id = t%p;
		int ub = (1 + t/p) * s[id];
		while (!bfs[id].empty()) {
			Node u = bfs[id].front();
			if (dist[u.i][u.j] >= ub) {
				break;
			}
			bfs[id].pop();

			for (int d=0; d<4; d++) {
				int ni = u.i + dx[d];
				int nj = u.j + dy[d];
				if (0<=ni && ni<n && 0<=nj && nj<m && grid[ni][nj] == '.') {
					grid[ni][nj] = id+'0';
					dist[ni][nj] = dist[u.i][u.j] + 1;
					bfs[id].push({ni,nj});
				}
			}
		}
	}

	int ans[p];
	memset(ans, 0, sizeof ans);
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			for (int k=0; k<p; k++) {
				ans[k] += (grid[i][j]-'0' == k);
			}
		}
	}
	for (int i=0; i<p; i++) {
		cout << ans[i] << " ";
	}
	cout << nl;

	return 0;
}