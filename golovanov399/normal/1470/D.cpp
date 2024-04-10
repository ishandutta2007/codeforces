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

const int N = 333333;
vector<int> a[N];

void solve() {
	int n = nxt(), m = nxt();
	for (int i = 0; i < n; ++i) {
		a[i].clear();
	}
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	vector<int> ans;
	vector<char> used(n, false);
	set<int> S;
	S.insert(0);
	while (!S.empty()) {
		int v = *S.begin();
		S.erase(S.begin());
		ans.push_back(v);
		used[v] = 1;
		vector<int> cands;
		for (int x : a[v]) {
			if (!used[x]) {
				cands.push_back(x);
			}
		}
		for (int x : cands) {
			used[x] = 1;
			if (S.count(x)) {
				S.erase(x);
			}
		}
		for (int u : cands) {
			for (int w : a[u]) {
				if (!used[w]) {
					S.insert(w);
				}
			}
		}
	}
	if (!*min_element(all(used))) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << ans.size() << "\n";
		sort(all(ans));
		for (int x : ans) {
			cout << x + 1 << " ";
		}
		cout << "\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}