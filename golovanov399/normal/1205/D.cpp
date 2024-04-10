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

const int N = 1111;
vector<int> a[N];

int sz[N];

void dfs(int v, int p) {
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		dfs(x, v);
		sz[v] += sz[x];
	}
	sz[v] += 1;
}

vector<array<int, 3>> answer;

void fillans(int v, int p, vector<int>& need, int off) {
	answer.push_back({{p, v, need.back() - off}});
	off = need.back();
	need.pop_back();
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		fillans(x, v, need, off);
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	if (n <= 3) {
		for (int i = 0; i < n; ++i) {
			for (int j : a[i]) {
				if (j > i) {
					cout << i + 1 << " " << j + 1 << " " << 1 << "\n";
				}
			}
		}
		return 0;
	}

	dfs(0, -1);
	int v = 0;
	int par = -1;
	vector<int> good;
	int sumsz = 0;
	while (sz[v] > 2 * n / 3) {
		int nx = -1;
		for (int x : a[v]) {
			if (x == par) {
				continue;
			}
			if ((sz[x] - 1) * 3 > 2 * (n - 1)) {
				nx = x;
				break;
			} else if ((sz[x] - 1) * 3 >= (n - 1)) {
				nx = x;
				break;
			} else {
				sumsz += sz[x];
				good.push_back(x);
				if (sumsz * 3 >= n - 1) {
					break;
				}
			}
		}
		if (sumsz * 3 >= n - 1) {
			break;
		}
		if (nx > -1) {
			good.clear();
			sumsz = 0;
			par = v;
			v = nx;
		}
	}
	if ((sz[v] - 1) * 3 >= (n - 1) && (sz[v] - 1) * 3 <= 2 * (n - 1)) {
		sumsz = sz[v] - 1;
		good = a[v];
		auto it = find(all(good), par);
		if (it != good.end()) {
			good.erase(it);
		}
	}
	// cerr << v + 1 << ":";
	// for (int x : good) {
	// 	cerr << " " << x + 1;
	// }
	// cerr << "\n";

	vector<int> psu(sumsz, 1);
	vector<int> psv(n - 1 - sumsz, 1);
	for (int i = 1; i < (int)psu.size(); ++i) {
		psu[i] += psu[i - 1];
	}
	for (int i = 1; i < (int)psv.size(); ++i) {
		psv[i] += psv[i - 1];
	}
	for (auto& x : psv) {
		x *= sumsz + 1;
	}
	reverse(all(psu));
	reverse(all(psv));

	for (int x : a[v]) {
		if (find(all(good), x) != good.end()) {
			fillans(x, v, psu, 0);
		} else {
			fillans(x, v, psv, 0);
		}
	}

	for (const auto& v : answer) {
		for (int i = 0; i < 3; ++i) {
			printf("%d ", v[i] + (i < 2 ? 1 : 0));
		}
		printf("\n");
	}

	return 0;
}