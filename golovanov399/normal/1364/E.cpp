#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

// #define TEST

#ifdef TEST
int gcnt = 0;
vector<int> g;
#endif

int ask(int i, int j) {
#ifdef TEST
	++gcnt;
	return g[i] | g[j];
#else
	cout << "? " << i + 1 << " " << j + 1 << endl;
	return nxt();
#endif
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand rng

#ifdef TEST
	int n = 2048;
	g.resize(n);
	iota(all(g), 0);
	random_shuffle(all(g));
#else
	int n = nxt();
#endif
	if (n <= 90) {
		vector<vector<int>> a(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				a[i][j] = a[j][i] = ask(i, j);
			}
		}
		vector<int> ans(n, (1 << 20) - 1);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i != j) {
					ans[i] &= a[i][j];
				}
			}
		}
#ifdef TEST
		assert(ans == g);
		cout << gcnt << "\n";
#else
		cout << "!";
		for (int x : ans) {
			cout << " " << x;
		}
		cout << endl;
#endif
		return 0;
	}

	auto reveal = [&](int i) {
		int cnt = 0;
		int res = (1 << 20) - 1;
		while (cnt < 15) {
			int j = rand() % n;
			if (i == j) {
				continue;
			}
			cnt += 1;
			res &= ask(i, j);
		}
		return res;
	};

	map<int, int> M;
	int p1 = -1, p2 = -1;
	int iz = -1;
	while (true) {
		int i = rand() % n;
		if (M.count(i)) {
			continue;
		}
		int x = reveal(i);
		if (!x) {
			iz = i;
			break;
		}
		bool ok = false;
		for (auto p : M) {
			if (!(p.second & x)) {
				ok = true;
				p1 = i;
				p2 = p.first;
				break;
			}
		}
		M[i] = x;
		if (ok) {
			break;
		}
	}

	if (iz == -1) {
		vector<int> order(n);
		iota(all(order), 0);
		for (int i = 0; i < n; ++i) {
			swap(order[i], order[rand() % (i + 1)]);
		}
		for (int i : order) {
			if (i != p1 && i != p2 && ask(p1, i) == M[p1] && ask(p2, i) == M[p2]) {
				iz = i;
				break;
			}
		}
	}

	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		if (i != iz) {
			ans[i] = ask(i, iz);
		}
	}
#ifdef TEST
	assert(ans == g);
	cout << gcnt << "\n";
#else
	cout << "!";
	for (int x : ans) {
		cout << " " << x;
	}
	cout << "\n";
#endif

	return 0;
}