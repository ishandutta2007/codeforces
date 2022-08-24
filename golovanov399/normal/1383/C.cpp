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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int L = 20;
const int N = 1 << L;

char good[N];

void solve() {
	int n = nxt();
	string s, t;
	cin >> s >> t;
	array<int, L> to = {};
	array<int, L> fr = {};
	for (int i = 0; i < n; ++i) {
		if (s[i] != t[i]) {
			to[s[i] - 'a'] |= 1 << (t[i] - 'a');
			fr[t[i] - 'a'] |= 1 << (s[i] - 'a');
		}
	}
	memset(good, 0, sizeof(good));
	good[0] = 1;
	for (int mask = 1; mask < N; ++mask) {
		for (int i = 0; i < L; ++i) {
			if (mask & (1 << i) && !(mask & to[i]) && good[mask ^ (1 << i)]) {
				good[mask] = 1;
			}
		}
	}
	vector<int> comps;
	vector<char> used(L);
	for (int i = 0; i < L; ++i) {
		if (used[i]) {
			continue;
		}
		comps.push_back(0);
		used[i] = 1;
		vector<int> st = {i};
		while (!st.empty()) {
			int v = st.back();
			st.pop_back();
			comps.back() |= 1 << v;
			for (int j = 0; j < L; ++j) {
				if (!used[j] && ((fr[v] | to[v]) & (1 << j))) {
					used[j] = 1;
					st.push_back(j);
				}
			}
		}
	}
	int ans = 0;
	for (int comp : comps) {
		int mx = 0;
		for (int mask = comp; mask > 0; mask = (mask - 1) & comp) {
			if (good[mask]) {
				mx = max(mx, __builtin_popcount(mask));
			}
		}
		ans += 2 * __builtin_popcount(comp) - 1 - mx;
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}