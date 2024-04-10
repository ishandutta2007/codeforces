#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
    inline int pidorand() {
        return ((rand() & 32767) << 15) | (rand() & 32767);
    }
    #define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 333333;
vector<int> types[N];
vector<int> a[N];
int colors[N];

void dfs(int v, int p = -1) {
	vector<int> busy;
	vector<int> to_paint;
	for (int x : types[v]) {
		if (colors[x] > -1) {
			busy.push_back(colors[x]);
		} else {
			to_paint.push_back(x);
		}
	}
	sort(all(busy));
	size_t idx = 0;
	int cur = 0;
	while (!to_paint.empty()) {
		while (idx < busy.size() && busy[idx] == cur) {
			cur = busy[idx] + 1;
			++idx;
		}
		colors[to_paint.back()] = cur++;
		to_paint.pop_back();
	}
	for (int x : a[v]) {
		if (x != p) {
			dfs(x, v);
		}
	}
}

int main(){
	int n = nxt(), m = nxt();
	for (int i = 0; i < n; ++i) {
		int s = nxt();
		types[i].resize(s);
		for (int j = 0; j < s; ++j) {
			types[i][j] = nxt() - 1;
		}
	}

	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	memset(colors, -1, sizeof(colors));
	dfs(0);
	for (int i = 0; i < m; ++i) {
		if (colors[i] == -1) {
			colors[i] = 0;
		}
	}
	printf("%d\n", *max_element(colors, colors + m) + 1);
	for (int i = 0; i < m; ++i) {
		printf("%d ", colors[i] + 1);
	}
	printf("\n");

	return 0;
}