#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, char> pii;

int dp[110][110][26][2];
vector <pii> from[110];

int dfs(int x, int y, int r, char now){
	if (~dp[x][y][now - 'a'][r]) return dp[x][y][now - 'a'][r];
	if (r == 0){
		for (int i = 0; i < from[x].size(); i++){
			int v = from[x][i].fi;
			char c = from[x][i].se;
			if (c < now) continue;
			int tmp = dfs(v, y, r ^ 1, c);
			if (tmp == 0) return dp[x][y][now - 'a'][r] = 1;
		}
		return dp[x][y][now - 'a'][r] = 0;
	} else {
		for (int i = 0; i < from[y].size(); i++){
			int v = from[y][i].fi;
			char c = from[y][i].se;
			if (c < now) continue;
			int tmp = dfs(x, v, r ^ 1, c);
			if (tmp == 0) return dp[x][y][now - 'a'][r] = 1;
		}
		return dp[x][y][now - 'a'][r] = 0;
	}
}

int main(){
	memset(dp, -1, sizeof(dp));
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, v; char c;
		cin >> u >> v >> c;
		from[u].push_back(mp(v, c));
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cout << (dfs(i, j, 0, 'a') ? 'A' : 'B');
		}
		cout << endl;
	}
	return 0;
}