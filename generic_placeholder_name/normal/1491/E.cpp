//trying to fix https://codeforces.com/contest/1491/submission/108732322

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAXN = 200005;
vector<int> path[MAXN];
int sz[MAXN];

map<int, int> fib;

int get_fib(int i) {
	if (fib.find(i) == fib.end()) return -1;
	else return fib[i];
}

bool ban[MAXN];
int par[MAXN];

void dfs(int u, int p, vector<int>& verts) {
    verts.push_back(u);
    sz[u] = 1;
    for(int v: path[u]) if(v != p && !ban[v]) {
        par[v] = u;
        dfs(v, u, verts);
        sz[u] += sz[v];
    }   
}

bool get(int u, int cur) {
    vector<int> verts;
    dfs(u, 0, verts);
    if (verts.size() == 1) return cur <= 1;
	for (int v: verts) if (v != u) {
		int f = get_fib(sz[v]);
		if (f != -1 && (f == cur - 1 || f == cur - 2)) {
		    ban[par[v]] = 1;
		    bool child = get(v, f);
		    ban[par[v]] = 0;
		    ban[v] = 1;
			bool parent = get(u, 2 * cur - 3 - f);
			ban[v] = 0;
			if (child && parent) return true;
		}
	} 
	return false;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0); cout.tie(0);
	int n;
	cin >> n;
	
	int cur = 1, pre = 0;
	
	for (int i = 1; i <= MAXN; i++) {
		if (cur + pre > MAXN) break;
		fib[cur + pre] = i;
		int tmp = cur + pre;
		pre = cur;
		cur = tmp;
	}
	
	// for (auto ii: fib) cout << ii.first << ' '; cout << '\n';
	
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		path[u].push_back(v);
		path[v].push_back(u);
	}	
	
	if (n == 1) return cout << "YES\n", 0;
	if (get_fib(n) == -1) return cout << "NO\n", 0;
	cout << (get(1, get_fib(n)) ? "YES\n" : "NO\n");
}