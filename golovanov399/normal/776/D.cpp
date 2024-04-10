#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 111111;
vector<pair<int, int>> a[N];
int state[N];

void panic() {
	puts("NO");
	exit(0);
}

void dfs(int v, int s) {
	state[v] = s;
	for (auto p : a[v]) {
		int x = p.second, to = p.first;
		if (state[to] == -1) {
			dfs(to, s ^ x);
		} else {
			if (state[to] != (s ^ x)) {
				panic();
			}
		}
	}
}

int main(){

	int m = nxt(), n = nxt();
	vector<int> st(m);
	for (int i = 0; i < m; ++i) {
		st[i] = 1 - nxt();
	}
	vector<vector<int>> doors(m);
	for (int i = 0; i < n; ++i) {
		int k = nxt();
		for (int j = 0; j < k; ++j) {
			int x = nxt() - 1;
			doors[x].push_back(i);
		}
	}

	for (int i = 0; i < m; ++i) {
		assert(doors[i].size() == 2);
		int u = doors[i][0], v = doors[i][1];
		a[u].push_back({v, st[i]});
		a[v].push_back({u, st[i]});
	}

	memset(state, -1, sizeof(state));
	for (int i = 0; i < n; ++i) {
		if (state[i] == -1) {
			dfs(i, 0);
		}
	}

	puts("YES");

	return 0;
}