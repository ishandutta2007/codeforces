#include <bits/stdc++.h>

using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &x, T2 y){if (x > y) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 &x, T2 y){if (x < y) x = y;}
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define x1 x1228
#define pb push_back
const int MAXN = 200001;

int n;
int p[MAXN];
int deep[MAXN];
vector<int> g[MAXN];
int cnt[MAXN];


void dfs(int u) {
	cnt[deep[u]]++;
	for (auto h: g[u]) {
		deep[h] = deep[u] + 1;
		dfs(h);
	}
}


int main() {
	//freopen("input.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> p[i];
		p[i]--;
		g[p[i]].push_back(i);
	}
	dfs(0);
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ans += cnt[i] & 1;
	}
	cout << ans << '\n';
	return 0;
}