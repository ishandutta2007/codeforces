#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt(), m = nxt();
	if (1ll * n * (n - 1) / 2 == m) {
		cout << "NO\n";
		return 0;
	}

	vector<vector<int>> a(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	int u = -1, v = -1;
	for (int i = 0; i < n; ++i) {
		if ((int)a[i].size() == n - 1) {
			continue;
		}
		a[i].push_back(i);
		sort(all(a[i]));
		u = i;
		v = 0;
		while (v < (int)a[i].size() && a[i][v] == v) {
			++v;
		}
		break;
	}

	vector<int> b(n, -1);
	b[u] = 1;
	b[v] = 2;
	int cur = 3;
	for (int i = 0; i < n; ++i) {
		if (b[i] == -1) {
			b[i] = cur++;
		}
	}
	printf("YES\n");
	for (int x : b) {
		printf("%d ", x);
	}
	printf("\n");
	b[u] = b[v];
	for (int x : b) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}