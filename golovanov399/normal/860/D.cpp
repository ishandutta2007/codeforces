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

const int N = 222222;
vector<int> a[N];
char used[N];
int last[N];

vector<vector<int>> ans;

void partition(int v) {
	if (used[v]) {
		return;
	}
	// cerr << v + 1 << " in\n";
	vector<int> cand;
	for (int x : a[v]) {
		if (!used[x]) {
			cand.push_back(x);
		}
	}
	used[v] = 1;
	for (int x : cand) {
		partition(x);
	}
	vector<int> new_cand;
	for (int x : cand) {
		if (last[x] > -1) {
			ans.push_back({last[x], x, v});
			last[x] = -1;
		} else {
			new_cand.push_back(x);
		}
	}
	// cerr << v + 1 << ": cand";
	// for (int x : cand) {
	// 	cerr << " " << x + 1;
	// }
	// cerr << " new_cand";
	// for (int x : new_cand) {
	// 	cerr << " " << x + 1;
	// }
	// cerr << "\n";
	for (int i = 0; i < (int)new_cand.size(); i += 2) {
		if (i == (int)new_cand.size() - 1) {
			last[v] = new_cand[i];
		} else {
			ans.push_back({new_cand[i], v, new_cand[i + 1]});
		}
	}
}

int main() {
	int n = nxt(), m = nxt();
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	memset(last, -1, sizeof(int) * n);
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			partition(i);
		}
	}

	printf("%d\n", ans.size());
	for (auto v : ans) {
		for (int x : v) {
			printf("%d ", x + 1);
		}
		printf("\n");
	}

	return 0;
}