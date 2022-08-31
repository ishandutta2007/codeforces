#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

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

int main() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<int> b = a;
	sort(all(b));
	for (int& x : a) {
		x = lower_bound(all(b), x) - b.begin();
	}

	vector<vector<int>> ed(n);
	for (int i = 0; i < n; ++i) {
		int j = a[i];
		ed[i].push_back(j);
		ed[j].push_back(i);
	}

	vector<char> used(n);
	vector<vector<int>> ans;
	for (itn i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		vector<itn> st = {i};
		ans.emplace_back();
		used[i] = 1;
		while (!st.empty()) {
			int v = st.back();
			st.pop_back();
			ans.back().push_back(v);
			for (int x : ed[v]) {
				if (used[x]) continue;
				st.push_back(x);
				used[x] = 1;
			}
		}
	}

	printf("%d\n", (int)ans.size());
	for (auto v : ans) {
		printf("%d", (int)v.size());
		for (int x : v) {
			printf(" %d", x + 1);
		}
		printf("\n");
	}

	return 0;
}