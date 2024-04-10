#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 1005;

int n, m;
char f[N][N];
int used[N][N];
int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool ok(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m && f[x][y] == '#';
}

void dfs(int x, int y) {
	used[x][y] = 1;
	forn(t, 4) {
		int xx = x + d[t][0], yy = y + d[t][1];
		if (ok(xx, yy) && !used[xx][yy]) {
			dfs(xx, yy);
		}
	}
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m;
	forn(i, n) {
		forn(j, m) {
			cin >> f[i][j];
		}
	}
	int bad = 0;
	int cntHor = 0;
	forn(i, n) {
		int state = 0;
		char last = '.';
		forn(j, m) {
			if (f[i][j] != last) {
				state++;
			}
			last = f[i][j];
		}
		if (state > 2) {
			bad = 1;
			break;
		}
		if (state == 0) {
			cntHor++;
		}
	}
	if (bad) {
		cout << -1 << '\n';
		return 0;
	}
	int cntVer = 0;
	forn(j, m) {
		int state = 0;
		char last = '.';
		forn(i, n) {
			if (f[i][j] != last) {
				state++;
			}
			last = f[i][j];
		}
		if (state > 2) {
			bad = 1;
			break;
		}
		if (state == 0) {
			cntVer++;
		}
	}
	if ((cntHor > 0 && cntVer == 0) || (cntHor == 0 && cntVer > 0) || bad) {
		cout << -1 << '\n';
		return 0;
	}	
	int ans = 0;
	forn(i, n) {
		forn(j, m) {
			if (!used[i][j] && f[i][j] == '#') {
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << '\n';
    return 0;
}