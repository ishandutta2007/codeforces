#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int N;
int K;

char grid[3][MAXN];
bool open[3][MAXN];

bool vis[3][MAXN];

bool free(char c) { return !('A' <= c && c <= 'Z'); }

bool go() {
	memset(grid, 0, sizeof(grid));
	cin >> N >> K;
	cin >> grid[0] >> grid[1] >> grid[2];
	for(int r = 0; r < 3; r++) {
		for(int i = 0; i <= N; i++) {
			open[r][i] =
				(free(grid[r][3 * i]) && free(grid[r][3 * i + 1]))
				&& ((i == 0) || (free(grid[r][3 * i - 1]) && free(grid[r][3 * i - 2])));
			cerr << open[r][i];
		}
		cerr << '\n';
	}
	memset(vis, 0, sizeof(vis));
	if(grid[0][0] == 's') vis[0][0] = true;
	if(grid[1][0] == 's') vis[1][0] = true;
	if(grid[2][0] == 's') vis[2][0] = true;
	for(int i = 0; i < N; i++) {
		for(int r = 0; r < 3; r++) {
			if(!open[r][i]) vis[r][i] = false;
			if(!vis[r][i]) continue;
			vis[r][i + 1] = true;
			if(r > 0) vis[r - 1][i + 1] = true;
			if(r < 2) vis[r + 1][i + 1] = true;
		}
	}
	return vis[0][N] || vis[1][N] || vis[2][N];

}

int main() {
	ios_base::sync_with_stdio(0);
	int cases; cin >> cases;
	while(cases--) {
		cout << (go() ? "YES" : "NO") << '\n';
	}
	return 0;
}