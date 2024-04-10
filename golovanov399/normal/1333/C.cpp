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
	long long cur = 0;
	long long ans = 0;
	map<long long, int> M;
	M[0] = 1;
	int mx = -1;
	for (int i = 1; i <= n; ++i) {
		cur += nxt();
		mx = max(mx, M[cur]);
		ans += i - mx;
		M[cur] = i + 1;
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}