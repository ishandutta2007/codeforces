#include <bits/stdc++.h>
#define ll long long
#define maxn 505 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int n, m;
vi eg[maxn];
int col[maxn];
int fl[maxn][maxn];
void dfs(int a, int tp) {
	if (col[a] != -1) return ;
	col[a] = tp;
	for (auto v : eg[a])
		dfs(v, tp ^ 1);
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		fl[u][v] = fl[v][u] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			if (!fl[i][j]) eg[i].pb(j), eg[j].pb(i);
		}
	memset(col, -1, sizeof(col));
	for (int i = 1; i <= n; i++) {
		if (col[i] != -1) continue;
		if (eg[i].size()) dfs(i, 0);
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			int g1 = (col[i] + col[j]) == 1;
			g1 ^= 1;
			if (g1 != fl[i][j]) {
				cout << "NO" << endl;
				return 0;
			}
		}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
		if (col[i] == 1) cout << "a";
		else if (col[i] == 0) cout << "c";
		else cout << "b";
	return 0;
}