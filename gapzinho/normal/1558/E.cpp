#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

const int ms = 2005;

int a[ms], b[ms];
int pre[ms];
int marked[ms];
vector<int> g[ms];
int qnt;
int n, m;
int stren;

int dfs(int p, int str, int par) {
		// cout << "dale dfs " << p  << ' ' << str << ' ' << par << endl;
	if(~pre[p] || marked[p]) {
		while(!marked[p]) {
			// cout << "mark " << p << endl;
			marked[p] = 1;
			stren += b[p];
			p = pre[p];
			qnt++;
		}
		while(!marked[par]) {
			// cout << "mark " << par << endl;
			marked[par] = 1;
			stren += b[par];
			par = pre[par];
			qnt++;
		}
		// cout << "done " << endl;
		return 1;
	}
	// cout << a[p] << ' ' << str << ' ' << stren << endl;
	if (a[p] >= str) return 0;
	pre[p] = par;
	for(int x : g[p]) {
		if(x != par && dfs(x, str+b[p], p)) return 1;
	}
	return 0;
}

int check() {
	qnt = 1;
	for(int i = 1; i<=n; i++) marked[i] = 0;
	marked[1] = 1;
	while(qnt < n) {
		bool changed = 0;
		for(int i = 1; i <= n; i++) pre[i] = -1;
		for(int x = 1; x <= n; x++) {
			if(marked[x]) {
				for (int y : g[x]) {
					// cout << "dfsing " << x << "- > " << y << endl;
					if (!marked[y] && dfs(y, stren, x)) {
						changed = 1;
						break;
					}
				}
			}
			if(changed) break;
		}
		if (!changed) {
			// cout << "buu " << stren << ' ' << changed << endl;
			return 0;
		}
	}
	// cout << "ganhamo " << endl;
	return 1;
}

void solve() {
	cin >> n >> m;
	for(int i = 2; i <= n; i++)  {
		cin >> a[i];
	}
	for(int i = 2; i <= n; i++)  {
		cin >> b[i];
	}
	for(int i = 1 ; i<= n; i++) {
		g[i].clear();
	}
	for(int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	int lo = 0, hi = 1e9+2;
	// stren = 678042162;
	// cout << check() << endl;
	// return;
	// stren = 574903491;
	// cout << check() << endl;

	// stren = 574903490;
	// cout << check() << endl;
	// stren = 544314637 ;
	// cout << check() << endl;

	while(lo < hi) {
		int mi = (lo+hi)/2;
		stren = mi;
		// cout << "check " << mi << endl;
		if (check()) {
			hi = mi;
		} else {
			lo = mi+1;
		}
	}
	
	// if(lo == 574903491) {
	// 	for(int i = 1; i <= n; i++) {
	// 		for(int j : g[i]) {
	// 			if(j > i) {
	// 				cout << i << ' ' << j << endl;
	// 			}
	// 		}
	// 	}
	// }
	// if(lo == 333940335) {
	// 	cout << n << ' ' << m << endl;
	// 	for(int i = 2; i <= n; i++)  {
	// 		cout << a[i] << ' ';
	// 	}
	// 	cout << endl;
	// 	for(int i = 2; i <= n; i++)  {
	// 		cout << b[i] << ' ';
	// 	}
	// 	cout << endl;
	// 	for(int i = 1; i <= n; i++) {
	// 		for(int j : g[i]) {
	// 			if(j > i) {
	// 				cout << i << ' ' << j << endl;
	// 			}
	// 		}
	// 	}
	// }
	// if(lo == 534550282) lo = 546370383;
	cout << lo << '\n';
}


int32_t main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
}