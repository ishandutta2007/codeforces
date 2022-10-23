#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt(), k = nxt();
	vector<int> cnt(27);
	{
		string s;
		cin >> s;
		for (char c : s) {
			cnt[c - 'a'] += 1;
		}
	}
	string ans = "";
	for (int i = 0; i < k; ++i) {
		int j = 0;
		int need = n / k;
		while (need && cnt[j]) {
			--need;
			--cnt[j];
			++j;
		}
		ans += 'a' + j;
		// j = 25;
		// while (need) {
		// 	while (!cnt[j]) {
		// 		--j;
		// 	}
		// 	--cnt[j];
		// 	--need;
		// }
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