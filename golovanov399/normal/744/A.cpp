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

const int N = 1111;
vector<int> a[N];
int color[N];

int dfs(int v, int col) {
	color[v] = col;
	int result = 0;
	for (int x : a[v]) {
		if (color[x]) {
			assert(color[x] == col);
			continue;
		}
		result += dfs(x, col) + 1;
	}
	return result;
}

int main(){

	int n = nxt(), m = nxt();
	int k = nxt();
	vector<int> capitals(k);
	for (int i = 0; i < k; ++i) {
		capitals[i] = nxt() - 1;
	}

	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	vector<int> eds(k);
	for (int i = 0; i < k; ++i) {
		eds[i] = dfs(capitals[i], i + 1);
	}

	vector<int> szs(k);
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			if (color[j] == color[capitals[i]]) {
				++szs[i];
			}
		}
	}

	int ans = 0;
	int edges = m;
	int verts = n;
	for (int i = 0; i < k; ++i) {
		ans += szs[i] * (szs[i] - 1) / 2 - eds[i];
		verts -= szs[i];
		edges -= eds[i];
	}

	ans += verts * (verts - 1) / 2 - edges;
	ans += *max_element(all(szs)) * verts;

	printf("%d\n", ans);

	return 0;
}