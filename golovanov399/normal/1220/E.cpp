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

const int N = 222222;
set<int> a[N];
set<int> b[N];
long long w[N];

char is_bad[N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	for (int i = 0; i < n; ++i) {
		w[i] = nxt();
	}
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].insert(v);
		a[v].insert(u);
	}
	for (int i = 0; i < n; ++i) {
		b[i] = a[i];
	}

	int root = nxt() - 1;
	
	set<pair<int, int>> S;
	for (int i = 0; i < n; ++i) {
		S.insert({(int)a[i].size(), i});
	}
	vector<int> par(n, -1);
	while (!S.empty()) {
		if (S.begin()->first > 1) {
			break;
		}
		int v = S.begin()->second;
		S.erase(S.begin());

		is_bad[v] = 1;
		if (a[v].empty()) {
			break;
		}
		int x = *a[v].begin();
		par[v] = x;
		S.erase({(int)a[x].size(), x});
		a[x].erase(v);
		S.insert({(int)a[x].size(), x});
	}

	vector<int> idx(n);
	vector<long long> nw;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		if (is_bad[i]) {
			idx[i] = cur++;
			nw.push_back(w[i]);
		}
	}
	if (*min_element(is_bad, is_bad + n) == 0) {
		nw.push_back(0);
		for (int i = 0; i < n; ++i) {
			if (!is_bad[i]) {
				idx[i] = cur;
				nw.back() += w[i];
			}
		}
		++cur;
	}
	int sz = cur;
	vector<vector<int>> g(sz);
	for (int i = 0; i < n; ++i) {
		for (int x : b[i]) {
			if (idx[i] != idx[x]) {
				g[idx[i]].push_back(idx[x]);
			}
		}
	}

	vector<int> st = {idx[root]};
	vector<long long> res(sz);
	vector<char> used(sz);
	used[idx[root]] = 1;
	while (!st.empty()) {
		int v = st.back();
		st.pop_back();
		res[v] += nw[v];
		for (int x : g[v]) {
			if (used[x]) {
				continue;
			}
			res[x] += res[v];
			st.push_back(x);
			used[x] = 1;
		}
	}

	long long answer = *max_element(all(res));

	if (is_bad[root] && *min_element(is_bad, is_bad + n) == 0) {
		long long tmp = 0;
		int v = root;
		while (is_bad[v]) {
			tmp += w[v];
			w[v] = 0;
			v = par[v];
		}
		root = v;




		vector<int> idx(n);
		vector<long long> nw;
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			if (is_bad[i]) {
				idx[i] = cur++;
				nw.push_back(w[i]);
			}
		}
		if (*min_element(is_bad, is_bad + n) == 0) {
			nw.push_back(0);
			for (int i = 0; i < n; ++i) {
				if (!is_bad[i]) {
					idx[i] = cur;
					nw.back() += w[i];
				}
			}
			++cur;
		}
		int sz = cur;
		vector<vector<int>> g(sz);
		for (int i = 0; i < n; ++i) {
			for (int x : b[i]) {
				if (idx[i] != idx[x]) {
					g[idx[i]].push_back(idx[x]);
				}
			}
		}

		vector<int> st = {idx[root]};
		vector<long long> res(sz);
		vector<char> used(sz);
		used[idx[root]] = 1;
		while (!st.empty()) {
			int v = st.back();
			st.pop_back();
			res[v] += nw[v];
			for (int x : g[v]) {
				if (used[x]) {
					continue;
				}
				res[x] += res[v];
				st.push_back(x);
				used[x] = 1;
			}
		}


		answer = max(answer, tmp + *max_element(all(res)));

	}

	cout << answer << "\n";

	return 0;
}