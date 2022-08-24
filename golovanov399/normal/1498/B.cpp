#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	int w = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	vector<int> rem;
	sort(all(a));
	reverse(all(a));
	for (int i = 0; i < n;) {
		int x = a[i];
		int j = 0;
		while (i < n && a[i] == x) {
			++i;
			while (j < (int)rem.size() && rem[j] < x) {
				++j;
			}
			if (j == (int)rem.size()) {
				rem.push_back(w);
			}
			rem[j] -= x;
		}
	}
	cout << rem.size() << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}