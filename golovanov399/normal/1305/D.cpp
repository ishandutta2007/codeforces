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
	// scanf("%d", &x);
	cin >> x;
	return x;
}

int ask(int x, int y) {
	cout << "? " << x + 1 << " " << y + 1 << endl;
	return nxt() - 1;
}

const int N = 1111;
set<int> a[N];

void delete_edge(int u, int v) {
	a[u].erase(v);
	a[v].erase(u);
}

int findLeaf(int v, int p = -1) {
	if ((int)a[v].size() == 1) {
		return v;
	}
	for (int x : a[v]) {
		if (x != p) {
			int res = findLeaf(x, v);
			if (res != -1) {
				return res;
			}
		}
	}
	return -1;
}

pair<int, int> findFurthest(int v, int p = -1, int d = 0) {
	pair<int, int> res = {d, v};
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		res = max(res, findFurthest(x, v, d + 1));
	}
	return res;
}

int getSz(int v, int p = -1) {
	int res = 1;
	for (int x : a[v]) {
		if (x != p) {
			res += getSz(x, v);
		}
	}
	return res;
}

bool used[N];
bool markPath(int v, int finish) {
	used[v] = true;
	if (v == finish) {
		return true;
	}
	for (int x : a[v]) {
		if (used[x]) {
			continue;
		}
		if (markPath(x, finish)) {
			return true;
		}
	}
	used[v] = false;
	return false;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].insert(v);
		a[v].insert(u);
	}

	int l = 0;
	while (n > 1) {
		if (n == 2) {
			assert((int)a[l].size() == 1);
			int u = l, v = *a[l].begin();
			l = ask(u, v);
			delete_edge(u, v);
			break;
		}

		int u = findFurthest(l).second;
		int v = findFurthest(u).second;
		l = ask(u, v);
		memset(used, 0, sizeof(used));
		markPath(u, v);
		vector<int> to_del;
		for (int x : a[l]) {
			if (used[x]) {
				to_del.push_back(x);
			}
		}
		for (int x : to_del) {
			delete_edge(l, x);
		}
		n = getSz(l);
	}

	cout << "! " << l + 1 << endl;

	return 0;
}