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
vector<int> a[N];
int c[N];
int ct[N];

void dfs(int v, int p = -1) {
	ct[v] = c[v];
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		dfs(x, v);
		if (ct[x] != ct[v]) {
			ct[v] = 0;
		}
	}
}

void dfs1(int v, int p = -1) {
	int good_cnt = 0;
	int cnt = 0;
	int bad_cnt = 0;
	for (int x : a[v]) {
		if (x != p && ct[x] == c[0]) {
			++good_cnt;
		}
		if (x != p) {
			++cnt;
		}
		if (x != p && ct[x] == 0) {
			++bad_cnt;
		}
	}

	if (bad_cnt == 0) {
		cout << "YES\n" << v + 1 << "\n";
		exit(0);
	}
	if (c[v] == c[0] && good_cnt >= cnt - 1) {
		for (int x : a[v]) {
			if (x == p) {
				continue;
			}
			if (cnt == good_cnt + (ct[x] != c[0] ? 1 : 0)) {
				dfs1(x, v);
			}
		}
	}
}

int main(){

	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 0; i < n; ++i) {
		c[i] = nxt();
	}

	dfs(0);
	dfs1(0);
	cout << "NO\n";

	return 0;
}