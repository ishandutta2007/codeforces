#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 333333;
vector<int> a[N];

int main() {
	int n = nxt(), m = nxt();
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	vector<int> d(n, -1);
	vector<int> pr(n, -1);
	d[0] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int x : a[v]) {
			if (d[x] > -1) {
				continue;
			}
			d[x] = d[v] + 1;
			pr[x] = v;
			q.push(x);
		}
	}
	vector<int> ans;
	if (d[n - 1] > -1) {
		for (int x = n - 1; x > -1; x = pr[x]) {
			ans.push_back(x);
		}
	}

	auto relax = [&](const vector<int>& cand) {
		if (ans.empty() || cand.size() < ans.size()) {
			ans = cand;
		}
	};

	if (a[0].empty()) {
		printf("%d\n", -1);
		return 0;
	}

	vector<char> neigs(n, 0);
	for (int x : a[0]) {
		neigs[x] = 1;
	}

	for (int v : a[0]) {
		for (int x : a[v]) {
			if (!neigs[x] && x) {
				relax({n - 1, 0, x, v, 0});
			}
		}
	}

	if (ans.empty() || (int)ans.size() > 5) {
		// check that all cliques
		vector<char> used(n, 0);
		vector<int> st;
		for (int i = 0; i < n; ++i) {
			if (!neigs[i] || used[i]) {
				continue;
			}
			st.push_back(i);
			used[i] = 1;
			int num_v = 1;
			int num_e = 0;
			vector<int> vs;
			while (!st.empty()) {
				int v = st.back();
				st.pop_back();

				vs.push_back(v);

				for (int x : a[v]) {
					if (x == 0) {
						continue;
					}
					++num_e;
					if (!used[x]) {
						++num_v;
						st.push_back(x);
						used[x] = 1;
					}
				}
			}

			if (1ll * num_e == 1ll * num_v * (num_v - 1)) {
				continue;
			}

			int v = 0;
			while ((int)a[vs[v]].size() == num_v) {
				++v;
			}
			v = vs[v];

			neigs.assign(n, 0);
			for (int x : a[v]) {
				if (x) {
					neigs[x] = 1;
				}
			}

			for (int w : a[v]) {
				if (w == 0) {
					continue;
				}
				for (int x : a[w]) {
					if (!neigs[x] && x && x != v) {
						relax({n - 1, v, x, w, v, 0});
					}
				}
			}
			break;
		}
	}

	printf("%d\n", (int)ans.size() - 1);
	reverse(all(ans));
	for (int v : ans) {
		printf("%d ", v + 1);
	}
	printf("\n");

	return 0;
}