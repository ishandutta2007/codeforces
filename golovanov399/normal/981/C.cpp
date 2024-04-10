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

int main() {
	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	int root = -1;
	for (int i = 0; i < n; ++i) {
		if ((int)a[i].size() <= 2) {
			continue;
		}
		if (root != -1) {
			puts("No");
			return 0;
		}
		root = i;
	}

	if (root == -1) {
		root = 0;
	}

	printf("Yes\n");
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (i != root && (int)a[i].size() == 1) {
			ans.push_back(i);
		}
	}
	printf("%d\n", (int)ans.size());
	for (int x : ans) {
		printf("%d %d\n", root + 1, x + 1);
	}

	return 0;
}