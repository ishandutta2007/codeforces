#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

#define size klsjfklajf

const int N = 111111;
vector<int> a[N];
int size[N];

void dfs(int v) {
	for (int x : a[v]) {
		dfs(x);
		size[v] += size[x];
	}
	if (a[v].empty()) {
		++size[v];
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	for (int i = 1; i < n; ++i) {
		a[nxt() - 1].push_back(i);
	}

	dfs(0);
	sort(size, size + n);
	for (int i = 0; i < n; ++i) {
		printf("%d ", size[i]);
	}
	printf("\n");

	return 0;
}