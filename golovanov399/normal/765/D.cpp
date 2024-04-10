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

void panic() {
	puts("-1");
	exit(0);
}

int main(){

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<int> b = a;
	sort(all(b));
	b.resize(unique(all(b)) - b.begin());
	int m = b.size();
	vector<int> g(n);
	vector<int> h(m);
	for (int i = 0; i < n; ++i) {
		g[i] = lower_bound(all(b), a[i]) - b.begin() + 1;
		h[g[i] - 1] = a[i];
	}

	for (int i = 0; i < n; ++i) {
		if (h[g[i] - 1] != a[i]) {
			panic();
		}
	}
	for (int i = 0; i < m; ++i) {
		if (g[h[i] - 1] != i + 1) {
			panic();
		}
	}

	printf("%d\n", m);
	for (int i = 0; i < n; ++i) {
		printf("%d ", g[i]);
	}
	printf("\n");
	for (int i = 0; i < m; ++i) {
		printf("%d ", h[i]);
	}
	printf("\n");

	return 0;
}