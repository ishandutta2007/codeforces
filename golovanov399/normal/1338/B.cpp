#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 111111;
vector<int> a[N];
set<long long> S;
int color[N];

long long rndll() {
	long long x = rand() & ((1 << 30) - 1);
	long long y = rand() & ((1 << 30) - 1);
	return (x << 30) | y;
}

void dfs(int v, long long cur = 0, int p = -1) {
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		color[x] = color[v] ^ 1;
		if ((int)a[x].size() == 1) {
			S.insert(cur);
		} else {
			long long tmp = rndll();
			S.insert(tmp);
			dfs(x, cur ^ tmp, v);
		}
	}
}

int main() {
	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int root = 0;
	while ((int)a[root].size() > 1) {
		++root;
	}
	dfs(root);

	int minc = 0;
	for (int i = 0; i < n; ++i) {
		if ((int)a[i].size() == 1) {
			minc |= 1 << color[i];
		}
	}
	minc >>= __builtin_ctz(minc);
	cout << minc << " " << S.size() << "\n";

	return 0;
}