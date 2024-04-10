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

const int N = 111111;
vector<int> a[N];
char used[N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), k = nxt();
	for (int i = 0; i < k; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	int csz = 0;
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		vector<int> st = {i};
		used[i] = 1;
		csz += 1;
		while (!st.empty()) {
			int v = st.back();
			st.pop_back();
			for (int x : a[v]) {
				if (!used[x]) {
					used[x] = 1;
					st.push_back(x);
				}
			}
		}
	}

	cout << k - n + csz << "\n";

	return 0;
}