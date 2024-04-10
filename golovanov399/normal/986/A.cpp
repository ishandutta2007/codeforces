#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

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

const int N = 111111;
vector<int> a[N];
vector<int> opt[N];

int main() {
	int n = nxt(), m = nxt(), k = nxt(), s = nxt();
	vector<vector<int>> type(k);
	for (int i = 0; i < n; ++i) {
		type[nxt() - 1].push_back(i);
	}
	for (itn i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (const auto& v : type) {
		vector<int> d(n, -1);
		queue<int> q;
		for (int x : v) {
			q.push(x);
			d[x] = 0;
		}
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int x : a[v]) {
				if (d[x] == -1) {
					d[x] = d[v] + 1;
					q.push(x);
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			opt[i].push_back(d[i]);
		}
	}
	for (int i = 0; i < n; ++i) {
		sort(all(opt[i]));
		opt[i].resize(s);
		printf("%d ", accumulate(all(opt[i]), 0));
	}
	printf("\n");

	return 0;
}