//GRT_2018
#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 200 * 1000 + 10;
int t, n, m;
vector<pi> V[nax];
bool vis[nax];
int ans[nax];

void dfs(int x) {
	vis[x] = true;
	for(auto [nbh, id] : V[x]) {
		if(!vis[nbh]) {
			ans[id] = 1;
			dfs(nbh);
		}
	}
}

int cnt[nax];
pi ed[nax];
int who = -1, memo = -1;

void dfs2(int x) {
	vis[x] = true;
	for(auto [nbh, id] : V[x]) {
		if(ans[id] == 1 && !vis[nbh]) {
			if(nbh == who) {
				memo = id;
			}
			dfs2(nbh);
		}
	}
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		V[i].clear();
		vis[i] = 0;
	}
	for(int i = 0; i < m; ++i) {
		ans[i] = 0;
	}
	for(int a, b, i = 0; i < m; ++i) {
		cin >> a >> b;
		ed[i] = {a, b};
		V[a].emplace_back(b, i);
		V[b].emplace_back(a, i);
	}
	dfs(1);
	for(int i = 1; i <= n; ++i) {
		cnt[i] = 0;
	}
	if(m < n + 2) {
		for(int i = 0; i < m; ++i) {
			cout << ans[i];
		}
		cout << "\n";
		return;
	}
	int ex = -1, m1 = -1;
	for(int i = 0; i < m; ++i) {
		if(ans[i] == 1) continue;
		auto [a,b] = ed[i];
		cnt[a]++, cnt[b]++;
		ex = a; who = b;
		m1 = i;
	}
	int ile = 0;
	for(int i = 1; i <= n; ++i) {
		if(cnt[i] == 2) {
			ile++;
		}
	}
	if(ile != 3) {
		for(int i = 0; i < m; ++i) {
			cout << ans[i];
		}
		cout << "\n";
		return;
	}
	for(int i = 1; i <= n; ++i) {
		vis[i] = false;
	}
	dfs2(ex);
	ans[m1] = 1;
	ans[memo] = 0;
	for(int i = 0; i < m; ++i) {
		cout << ans[i];
	}
	cout << "\n";
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		solve();
	}
}