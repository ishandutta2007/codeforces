#include <bits/stdc++.h>
 
#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())
 
using namespace std;
 
inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}
 
void solve() {
	int n = nxt();
	vector<vector<int>> l(n);
	for (int i = 0; i < n; ++i) {
		l[i].resize(nxt());
		for (auto& x : l[i]) {
			x = nxt() - 1;
		}
		sort(all(l[i]));
	}
	vector<char> used(n);
	int bitch = -1;
	for (int i = 0; i < n; ++i) {
		int opt = -1;
		for (int x : l[i]) {
			if (!used[x]) {
				opt = x;
				break;
			}
		}
		if (opt == -1) {
			bitch = i;
			continue;
		}
		used[opt] = true;
	}
	if (bitch == -1) {
		cout << "OPTIMAL\n";
	} else {
		cout << "IMPROVE\n" << bitch + 1 << " " << min_element(all(used)) - used.begin() + 1 << "\n";
	}
}
 
int main() {
	int t = nxt();
	while (t--) {
		solve();
	}
 
	return 0;
}