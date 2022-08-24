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

#define fixed skdjflfsdj
const int N = 55;
int a[N][N];
char fixed[N][N];
int score[N];

void add(int u, int v, int x) {
	a[u][v] += x;
	score[u] += x;
}

vector<int> all_out(int v, int n) {
	vector<char> used(n);
	vector<int> st = {v};
	used[v] = 1;
	vector<int> par(n, -1);
	while (!st.empty()) {
		int u = st.back();
		st.pop_back();
		for (int i = 0; i < n; ++i) {
			if (!fixed[i][u] && a[u][i]) {
				if (!used[i]) {
					used[i] = 1;
					par[i] = u;
					st.push_back(i);
				}
			}
		}
	}
	return par;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		add(u, v, 1);
		fixed[u][v] = fixed[v][u] = 1;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (!fixed[i][j]) {
				if (rand() % 2) {
					add(i, j, 1);
				} else {
					add(j, i, 1);
				}
			}
		}
	}

	while (true) {
		bool ok = false;
		for (int i = 0; i < n; ++i) {
			if (ok) {
				break;
			}
			auto par = all_out(i, n);
			for (int j = 0; j < n; ++j) {
				if (i != j && par[j] > -1 && score[j] < score[i] - 1) {
					for (int u = j; u != i; u = par[u]) {
						add(u, par[u], 1);
						add(par[u], u, -1);
					}
					ok = true;
					break;
				}
			}
		}
		if (!ok) {
			break;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j];
		}
		cout << "\n";
	}

	return 0;
}