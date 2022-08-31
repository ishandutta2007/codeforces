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
	vector<int> a(n);
	generate(all(a), nxt);
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		vector<int> b;
		for (int j = i; j < i + 4 && j < (int)a.size(); ++j) {
			b.push_back(a[j]);
			bool ok = true;
			for (int l = 0; l < (int)b.size() - 1; ++l) {
				for (int r = l + 1; r < (int)b.size() - 1; ++r) {
					if ((b[l] <= b[r] && b[r] <= b.back()) || (b[l] >= b[r] && b[r] >= b.back())) {
						ok = false;
						break;
					}
				}
			}
			if (ok) {
				++ans;
			} else {
				break;
			}
		}
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