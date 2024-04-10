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

const int N = 222222;
int dp[N][2];

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	int l = -1, r = -1;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] == a[i + 1]) {
			if (l == -1) {
				l = i;
			}
			r = i;
		}
	}
	if (l == -1 || l == r) {
		cout << "0\n";
	} else {
		cout << max(1, r - l - 1) << "\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}